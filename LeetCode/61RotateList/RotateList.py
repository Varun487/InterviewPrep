class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        # 2 passes -> Time:O(n), Space:O(1)
        if head == None:
            return head
        list_len = 0
        travel = head
        last_node = head
        while travel != None:
            list_len += 1
            last_node = travel
            travel = travel.next
        k %= list_len
        count = list_len-1-k
        travel = head
        while count > 0:
            count -= 1
            travel = travel.next
        last_node.next = head
        head = travel.next
        travel.next = None
        return head
