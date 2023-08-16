class Solution:
    def merge(self, l1, l2):
        ans = ListNode()
        travel = ans
        while l1 and l2:
            if l1.val < l2.val:
                travel.next = l1
                l1 = l1.next
            else:
                travel.next = l2
                l2 = l2.next
            travel = travel.next
        if l1:
            travel.next = l1
        if l2:
            travel.next = l2
        return ans.next

    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        # Divide and Conquer -> Time:O(log(k)*n), Space:O(k)
        if len(lists) == 0 or not lists:
            return None
        while (len(lists) > 1):
            merged = []
            for i in range(0, len(lists), 2):
                l1 = lists[i]
                l2 = lists[i+1] if (i+1) < len(lists) else None
                merged.append(self.merge(l1, l2))
            lists = merged
        return lists[0]
