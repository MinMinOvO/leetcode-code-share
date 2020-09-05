object Solution {
    def longestCommonPrefix(strs: Array[String]): String = {
        if (strs.length == 0)
            return ""
        val s0 = strs(0)
        val minlen = strs.minBy(_.length).length
        def l (i: Int) : Int = {
            if (i >= minlen)
                return i
            val c = s0.charAt(i)
            if (strs.forall(_.charAt(i)==c)) {
                l(i+1)
            } else {
                i
            }
        }
        s0.substring(0, l(0))
    }
}