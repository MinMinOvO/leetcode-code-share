object Solution {
    def maxArea(height: Array[Int]): Int = {
        //brute-force
        val zipped = height.zipWithIndex
        zipped.map( (t1:(Int, Int)) => zipped.drop(t1._2).map( (t2:(Int, Int)) => math.abs(t1._2-t2._2)*math.min(t1._1,t2._1) ).max ).max
    }
}