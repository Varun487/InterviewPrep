class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // 3 pointers -> Time:O(n), Space:O(1)
        if (!head) {
            return head;
        }
        ListNode *prev = NULL, *curr = head, *next = head->next;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
