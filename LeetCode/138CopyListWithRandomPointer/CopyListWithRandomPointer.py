class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        # 2 passes -> Time:O(n), Space:O(n)
        original_copy = {None:None}
        curr = head
        while curr:
            copy = Node(curr.val)
            original_copy[curr] = copy
            curr = curr.next
        curr = head
        while curr:
            copy = original_copy[curr]
            copy.next = original_copy[curr.next]
            copy.random = original_copy[curr.random]
            curr = curr.next
        return original_copy[head]
