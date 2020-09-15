import scala.collection.mutable.ListBuffer
import scala.collection.immutable.Stream
import scala.util.control._


object Solution {
    def generateParenthesis(n: Int): List[String] = {
        //not pure functional programming :)
        var levels = Range(0, n).toArray
        var sb = new StringBuilder()
        var l = ListBuffer[String]()
        val rLevels = levels.view.reverse
        def appendNewParentheses(fromIdx: Int, level: Int) : Int = {
            //println(levels.mkString("-"), fromIdx, level)
            if (fromIdx == levels.length || levels(fromIdx) < level) return fromIdx
            sb.append('(')
            val nextIdx = appendNewParentheses(fromIdx+1, level+1)
            sb.append(')')
            appendNewParentheses(nextIdx, level)
        }
        def changeList() : Boolean = {
            val i = n - 1 - rLevels.indexWhere(_ != 0)
            if(i == n) return false
            levels(i) -= 1
            val off = levels(i)-i
            Range(i+1, n).foreach(j => levels(j) = off+j)
            true
        }
        def from(k: Int) : Stream[Int] = {
            new Stream.Cons(k, from(k+1))
        }
        var k = 0
        val loop = new Breaks
        loop.breakable{
            for(k <- from(0)){
                appendNewParentheses(0, 0)
                l = l :+ sb.toString
                sb.clear
                if(!changeList()) loop.break
            }
        }
        l.toList
    }
}