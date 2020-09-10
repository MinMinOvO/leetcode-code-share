/**
 * Definition for singly-linked list.
 * class ListNode(_x: Int = 0, _next: ListNode = null) {
 *   var next: ListNode = _next
 *   var x: Int = _x
 * }
 */
object Solution {
    def removeNthFromEnd(head: ListNode, n: Int): ListNode = {
        def getL(l: Int, head: ListNode):Int = {
            if (head == null) {
                l
            } else {
                getL(l+1, head.next)
            }
        }
        def getNth(head: ListNode, n: Int) : ListNode = {
            if (n == 1) {
                head
            } else {
                getNth(head.next, n-1)
            }
        }
        val nth = getL(0, head) - n + 1
        if (nth == 1) {
            head.next
        } else {
            val hNode = getNth(head, nth - 1)
            hNode.next = hNode.next.next
            head
        }
    }
}