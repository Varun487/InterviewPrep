class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        # Single pass -> Time:O(n), Space:O(1)
        left, right = ListNode(), ListNode()
        left_head, right_head = left, right
        travel = head
        while travel:
            if travel.val < x:
                left.next = travel
                left = left.next
            else:
                right.next = travel
                right = right.next
            travel = travel.next
            left.next = None
            right.next = None
        left.next = right_head.next
        return left_head.next
