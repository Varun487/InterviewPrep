/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* lsum = new ListNode(0);
        ListNode* travel_lsum = lsum;

        ListNode* travel_l1 = l1;
        ListNode* travel_l2 = l2;

        int s, node_sum, carry = 0;

        while (travel_l1 && travel_l2) {
            s = travel_l1->val + travel_l2->val + carry;
            node_sum = s%10;
            travel_lsum->next = new ListNode(node_sum);
            carry = s/10;
            travel_l1 = travel_l1->next;
            travel_l2 = travel_l2->next;
            travel_lsum = travel_lsum->next;
        }

        while (travel_l1) {
            s = travel_l1->val + carry;
            node_sum = s%10;
            travel_lsum->next = new ListNode(node_sum);
            carry = s/10;
            travel_l1 = travel_l1->next;
            travel_lsum = travel_lsum->next;
        }

        while (travel_l2) {
            s = travel_l2->val + carry;
            node_sum = s%10;
            travel_lsum->next = new ListNode(node_sum);
            carry = s/10;
            travel_l2 = travel_l2->next;
            travel_lsum = travel_lsum->next;
        }

        if (carry) {
            travel_lsum->next = new ListNode(carry);
        }

        return lsum->next;
    }
};