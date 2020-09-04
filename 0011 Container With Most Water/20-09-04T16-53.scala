object Solution {
    def maxArea(height: Array[Int]): Int = {
        //two pointer
        def water(i: Int, j: Int) : Int = {
            val width = j - i
            if (width == 0) {
                0
            } else if (height(i) < height(j)) {
                math.max(height(i)*width, water(i+1, j))
            } else {
                math.max(height(j)*width, water(i, j-1))
            }
        }
        water(0, height.length-1)
    }
}