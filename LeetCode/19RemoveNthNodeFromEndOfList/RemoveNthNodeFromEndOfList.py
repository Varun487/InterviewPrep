class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        # Single pass -> Time:O(n), Space:O(1)
        travel = head
        remove = head
        remove_prev = head
        count = 0
        while travel != None:
            travel = travel.next
            count += 1
            if count > n:
                remove_prev = remove
                remove = remove.next
        if remove_prev == remove:
            head = head.next
        else:
            remove_prev.next = remove.next
        return head
