object Solution {
    
    def threeSumClosest(nums: Array[Int], target: Int): Int = {
        //iterate sorted array with two pointer
        val snums = nums.sorted
        def minDifWithX(x: Int, i: Int, j: Int, minDif: Int) : Int = {
            if (i >= j) {
                minDif
            } else {  
                val c = snums(i) + snums(j) + x - target
                if (c < 0) {
                    minDifWithX(x, i+1, j, if (-c<math.abs(minDif)) c else minDif )
                } else if (c > 0) {
                    minDifWithX(x, i, j-1, if (c<math.abs(minDif)) c else minDif )
                } else {
                    0
                }
            }
        }
        (snums.zipWithIndex).foldLeft(1e5.toInt)((b, e)=>minDifWithX(e._1, e._2+1, snums.length-1, b)) + target
    }
}