import scala.collection.StringView

object Solution {
    def romanToInt(s: String): Int = {
        def symbolvalue (c: Char) = c match {
            case 'I' => 1
            case 'V' => 5
            case 'X' => 10
            case 'L' => 50
            case 'C' => 100
            case 'D' => 500
            case 'M' => 1000
        }
        def issubtracted (c1: Char, c2: Char) = c1 match {
            case 'I' => c2 == 'V' || c2 == 'X'
            case 'X' => c2 == 'L' || c2 == 'C'
            case 'C' => c2 == 'D' || c2 == 'M'
            case _ => false
        }
        def value(t: (Char, Char)) = {
            val (c1, c2) = t
            if (issubtracted(c1, c2)) {
                -symbolvalue(c1)
            } else {
                symbolvalue(c1)
            }
        }
        val sview = new StringView(s)
        (sview.init zip sview.tail).map(value).sum + symbolvalue(sview.last)
    }
}