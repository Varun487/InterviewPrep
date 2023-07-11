class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Single pass -> Time:O(n+m), Space:O(1), n=NodesInList1, m=NodesInList2
        ListNode dummy = ListNode(0);
        ListNode* head = &dummy;
        ListNode* curr = head;
        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                curr->next = list1;
                list1 = list1->next;
            }
            else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        if (list1 == NULL) {
            curr->next = list2;
        }
        else {
            curr->next = list1;
        }
        return head->next;
    }
};
