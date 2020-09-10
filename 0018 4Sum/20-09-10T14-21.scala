object Solution {
    def fourSum(nums: Array[Int], target: Int): List[List[Int]] = {
        type Quads = List[List[Int]]
        val l = nums.length
        val snums = nums.sorted
        val snumsR = snums.view.reverse
        val nextI = (i: Int, x: Int) => {val ni = snums.indexWhere(_ > x ,i+1); if (ni > 0) ni else l}
        val nextJ = (j: Int, y: Int) => {val nj = snumsR.indexWhere(_ < y ,l-j); if (nj > 0) l-1-nj else -1}
        def foldWithQuads(x: Int, y: Int, i: Int, j: Int, quads: Quads) : Quads = {
            if (i >= j) {
                quads
            } else {
                val c = x + y + snums(i) + snums(j) - target
                if (c < 0) {
                    foldWithQuads(x, y, nextI(i, snums(i)), j, quads)
                } else if (c > 0) {
                    foldWithQuads(x, y, i, nextJ(j, snums(j)), quads)
                } else {
                    foldWithQuads(x, y, nextI(i, snums(i)), nextJ(j, snums(j)), quads :+ List(x, y, snums(i), snums(j)))
                }
            }
        }
        def f(b1: Quads, i: Int) : Quads = {
            if (i > 0 && snums(i-1) == snums(i))
                b1
            else
                Range(i+2, l-1).foldLeft(foldWithQuads(snums(i), snums(i+1), i+2, l-1, b1))( (b2,j) => {
                    if (snums(j-1) == snums(j))
                        b2
                    else
                        foldWithQuads(snums(i), snums(j), j+1, l-1, b2)
                } )
        }                                                   
        Range(0, l-2).foldLeft(List[List[Int]]())(f)
    }
}