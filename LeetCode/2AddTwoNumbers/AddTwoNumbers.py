# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        # Complexity O(n+m)
        lsum = ListNode(0)
        travel_lsum = lsum

        travel_l1 = l1
        travel_l2 = l2

        carry = 0

        while travel_l1 != None and travel_l2 != None:

            s = travel_l1.val + travel_l2.val + carry
            node_sum = s%10

            travel_lsum.next = ListNode(node_sum)
            travel_lsum = travel_lsum.next

            carry = s//10

            travel_l1 = travel_l1.next
            travel_l2 = travel_l2.next
        
        lsum = lsum.next

        while travel_l1 != None:
            s = travel_l1.val + carry
            node_sum = s%10
            travel_lsum.next = ListNode(node_sum)
            travel_lsum = travel_lsum.next
            carry = s//10
            travel_l1 = travel_l1.next
        
        while travel_l2 != None:
            s = travel_l2.val + carry
            node_sum = s%10
            travel_lsum.next = ListNode(node_sum)
            travel_lsum = travel_lsum.next
            carry = s//10
            travel_l2 = travel_l2.next
                
        if carry != 0:
            travel_lsum.next = ListNode(carry)

        return lsum
