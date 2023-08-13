class Solution {
public:
    ListNode* getMid(ListNode* head) {
        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode *ans = new ListNode(), *travel = ans;
        while (left && right) {
            if (left->val < right->val) {
                travel->next = left;
                left = left->next;
            }
            else {
                travel->next = right;
                right = right->next;
            }
            travel = travel->next;
        }
        if (left) {
            travel->next = left;
        }
        if (right) {
            travel->next = right;
        }
        return ans->next;
    }
    ListNode* sortList(ListNode* head) {
        // Merge Sort -> Time:O(nlogn), Space:O(logn)
        if (!head || !head->next) {
            return head;
        }
        ListNode* left = head;
        ListNode* right = getMid(head);
        ListNode* temp = right->next;
        right->next = NULL;
        right = temp;
        left = sortList(left);
        right = sortList(right);
        return merge(left, right);
    }
};
