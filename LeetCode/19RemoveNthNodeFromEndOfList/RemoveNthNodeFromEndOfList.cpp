class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Single pass -> Time:O(n), Space:O(1)
        ListNode* travel = head;
        ListNode* remove = head;
        ListNode* remove_prev = head;
        int count = 0;
        while (travel != NULL) {
            travel = travel->next;
            count++;
            if (count > n) {
                remove_prev = remove;
                remove = remove->next;
            }
        }
        if (remove == remove_prev) {
            head = head->next;
        }
        else {
            remove_prev->next = remove->next;
        }
        return head;
    }
};
