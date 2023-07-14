class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # Single pass -> Time:O(n), Space:O(1), n=NumberOfNodes
        ans = ListNode()
        ans.next = head
        prev, curr = ans, head
        while curr != None:
            if curr.next != None and curr.val == curr.next.val:
                while curr.next != None and curr.val == curr.next.val:
                    curr = curr.next
                prev.next = curr.next
            else:
                prev = prev.next
            curr = curr.next
        return ans.next
