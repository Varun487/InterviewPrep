class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # 3 pointers -> Time:O(n), Space:O(1)
        if not head:
            return head
        prev, curr, nxt = None, head, head.next
        while curr:
            nxt = curr.next
            curr.next = prev
            prev = curr
            curr = nxt
        return prev
