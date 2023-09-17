class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        # 3 passes -> Time:O(n), Space:O(1)
        # Find break point
        slow, fast = head, head
        while fast and fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
        # Break list
        l1, l2 = head, slow.next
        slow.next = None
        # Reverse list
        prev, curr, nxt = None, l2, None
        while curr:
            nxt = curr.next
            curr.next = prev
            prev = curr
            curr = nxt
        l2 = prev
        # Interleave list
        head = l1
        while l1 and l2:
            temp = l1.next
            l1.next = l2
            l1 = temp
            temp = l2.next
            l2.next = l1
            l2 = temp

        # # 4 passes -> Time:O(n), Space:O(1)
        # # Find list length
        # n = 0
        # start = head
        # while start:
        #     n += 1
        #     start = start.next
        # # Break point
        # b = n//2 + n%2
        # # Break list
        # start = head
        # l1, l2 = head, None
        # m = 0
        # while start:
        #     m += 1
        #     if m == b:
        #         l2 = start.next
        #         start.next = None
        #         break
        #     start = start.next
        # # Reverse list
        # prev, nxt = None, None
        # curr = l2
        # while curr:
        #     nxt = curr.next
        #     curr.next = prev
        #     prev = curr
        #     curr = nxt
        # l2 = prev
        # # Interleave
        # head = l1
        # t1, t2 = l1, l2
        # while t1 and t2:
        #     temp = t1.next
        #     t1.next = t2
        #     t1 = temp
        #     temp = t2.next
        #     t2.next = t1
        #     t2 = temp
