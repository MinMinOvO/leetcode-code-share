import collection.View

object Solution {
    def convert(s: String, numRows: Int): String = {
        if (numRows<=1) s else {
            val M = 2 * (numRows-1)
            val satisfy = (m: Int) => (ms: (Int, Int)) => (t: (Char, Int)) =>{
                var r = (t._2 % m)
                r == ms._1 || r == ms._2
            }
            val getModles = (r: Int, m: Int) => (r, m-r)
            val slices : Seq[View[(Char, Int)]] = Range(0, numRows).map(i => s.view.zipWithIndex.filter( satisfy(M)(getModles(i, M)) ))
            val it = slices.foldLeft[View[(Char, Int)]](View[(Char, Int)]())(_ ++ _)
            it.unzip._1.mkString
        }
    }
}