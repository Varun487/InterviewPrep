class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // Single pass -> Time:O(n), Space:O(1)
        ListNode *left = new ListNode(), *right = new ListNode(), *leftHead = left, *rightHead = right, *travel = head;
        while (travel) {
            if (travel->val < x) {
                left->next = travel;
                left = left->next;
            }
            else {
                right->next = travel;
                right = right->next;
            }
            travel = travel->next;
            left->next = NULL;
            right->next = NULL;
        }
        left->next = rightHead->next;
        return leftHead->next;
    }
};
