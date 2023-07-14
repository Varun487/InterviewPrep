class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // Single pass -> Time:O(n), Space:O(1), n=NumberOfNodes
        ListNode *ans = new ListNode(0, head);
        ListNode *curr = head, *prev = ans;
        while (curr != NULL) {
            if (curr->next && curr->val == curr->next->val) {
                while (curr->next && curr->val == curr->next->val) {
                    curr = curr->next;
                }
                prev->next = curr->next;
            }
            else {
                prev = prev->next;
            }
            curr = curr->next;
        }
        return ans->next;
    }
};
