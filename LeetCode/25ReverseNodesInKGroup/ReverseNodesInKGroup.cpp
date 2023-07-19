class Solution {
public:
    ListNode* getKth(ListNode* curr, int k) {
        while (curr && k) {
            curr = curr->next;
            k--;
        }
        return curr;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Single pass -> Time:O(n), Space:O(1)
        ListNode *ans = new ListNode(0,head);
        ListNode *groupNext, *prev, *curr, *temp; 
        ListNode *groupPrev = ans, *kth = getKth(groupPrev,k);
        while (kth) {
            groupNext = kth->next;
            prev = groupNext;
            curr = groupPrev->next;
            while (curr != groupNext) {
                temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            temp = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = temp;
            kth = getKth(groupPrev,k);
        }
        return ans->next;
    }
};
