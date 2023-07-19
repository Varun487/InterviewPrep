class Solution:
    def getKth(self, curr, k):
        while curr and k > 0:
            curr = curr.next
            k -= 1
        return curr

    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        # Single pass -> Time:O(n), Space:O(1)
        ans = ListNode(0, head)
        groupPrev = ans
        kth = self.getKth(groupPrev, k)

        while kth:
            groupNext = kth.next
            prev, curr = groupNext, groupPrev.next
            while curr != groupNext:
                temp = curr.next
                curr.next = prev
                prev = curr
                curr = temp
            temp = groupPrev.next
            groupPrev.next = kth
            groupPrev = temp

            kth = self.getKth(groupPrev, k)
        
        return ans.next
