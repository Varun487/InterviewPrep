class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        # Single pass -> Time:O(n), Space:O(1)
        if left == right:
            return head

        ans = ListNode(0, head)
        left_p, right_p, group_prev = ans, ans, ans

        while left_p and left:
            left -= 1
            group_prev = left_p
            left_p = left_p.next

        while right_p and right:
            right -= 1
            right_p = right_p.next
        
        group_next = right_p.next

        prev = group_next
        curr = left_p
        while curr != group_next:
            next_p = curr.next
            curr.next = prev
            prev = curr
            curr = next_p
        
        group_prev.next = right_p

        return ans.next
