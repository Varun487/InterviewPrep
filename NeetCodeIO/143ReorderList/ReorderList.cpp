class Solution {
public:
    void reorderList(ListNode* head) {
        // 3 passes -> Time:O(n), Space:O(1)
        // Find break point
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // Break list
        ListNode *l1 = head, *l2 = slow->next;
        slow->next = NULL;
        // Reverse list
        ListNode *nxt = NULL, *prev = NULL, *curr = l2;
        while (curr) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        l2 = prev;
        // Interleave list
        head = l1;
        while (l1 && l2) {
            curr = l1->next;
            l1->next = l2;
            l1 = curr;
            curr = l2->next;
            l2->next = l1;
            l2 = curr;
        }
    }
};
