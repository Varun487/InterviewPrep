class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // Single pass -> Time:O(n), Space:O(1)
        if (left == right) {
            return head;
        }
        ListNode *ans = new ListNode(0, head);
        ListNode *groupPrev, *groupNext, *curr, *prev, *next;
        ListNode *left_p = ans, *right_p = ans;
        while (left_p && left) {
            left--;
            groupPrev = left_p;
            left_p = left_p->next;
        }
        while (right_p && right) {
            right--;
            right_p = right_p->next;
        }
        groupNext = right_p->next;
        prev = groupNext;
        curr = left_p;
        while (curr != groupNext) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        groupPrev->next = right_p;
        return ans->next;
    }
};