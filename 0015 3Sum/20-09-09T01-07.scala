import scala.collection.immutable.SortedMap

object Solution {
    
    implicit def bool2int(b:Boolean) = if (b) 1 else 0
    
    def threeSum(nums: Array[Int]): List[List[Int]] = {
        val map = SortedMap(nums.zipWithIndex.groupMap(_._1)(_._2).toArray map (t => (t._1, t._2.length)) : _*)
        def validCombination (a: Int, b: Int, c: Int, v: Int) : Boolean = {
            if (a == b && v < 2) return false
            val o = map.get(c)
            if (o.isEmpty) false else o.get - (c==a) - (c==b) >= 1
        }
        def newList(l: List[List[Int]])(e1: (Int, Int), e2: (Int, Int)): List[List[Int]] = {
            val (a, b, c) = (e1._1, e2._1, 0 - e1._1 - e2._1)
            if (c >= b && validCombination(a, b, c, e1._2)) 
                l :+ List(a, b, c)
            else
                l
        }
        map.foldLeft(List[List[Int]]())( (b1, e1) => 
            map.iteratorFrom(e1._1).foldLeft(b1)( (b2, e2) => newList(b2)(e1, e2) ) )
    }
}