class Solution:
    def get_mid(self, head):
        slow = head
        fast = head.next
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        return slow
    
    def merge(self, left, right):
        ans = ListNode()
        travel = ans
        while left and right:
            if left.val < right.val:
                travel.next = left
                left = left.next
            else:
                travel.next = right
                right = right.next
            travel = travel.next
        if left:
            travel.next = left
        if right:
            travel.next = right
        return ans.next

    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # Merge Sort -> Time:O(nlogn), Space:O(logn)
        if not head or not head.next:
            return head
        left = head
        right = self.get_mid(head)
        temp = right.next
        right.next = None
        right = temp
        left = self.sortList(left)
        right = self.sortList(right)
        return self.merge(left, right)
