object Solution {
    def isMatch(s: String, p: String): Boolean = {
        def ischarmatch = (s: Char, p: Char) => p == '.' || s == p
        def length = (a: String, i: Int) => a.length - i
        def isasterisked = (j: Int, pl: Int) => pl >= 2 && p.charAt(j+1) == '*'
        def firstmatch = (i: Int, j: Int, sl: Int) => sl >= 1 && ischarmatch(s.charAt(i), p.charAt(j))
        def ismatch(i: Int, j: Int) : Boolean = {
            val (sl, pl) = (length(s, i), length(p, j))
            if (pl == 0) {
                sl == 0
            } else if (isasterisked(j, pl)) {
                ismatch(i,j+2) || (firstmatch(i,j,sl) && ismatch(i+1,j))
            } else {
                firstmatch(i,j,sl) && ismatch(i+1,j+1)
            }
        }
        ismatch(0, 0)
    }
}