class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // 2 passes -> Time:O(n), Space:O(1)
        if (head == NULL) {
            return head;
        }
        int count, listLen = 0;
        ListNode* travel = head;
        ListNode* lastNode = head;
        while (travel != NULL) {
            listLen ++;
            lastNode = travel;
            travel = travel->next;
        }
        k %= listLen;
        count = listLen-1-k;
        travel = head;
        while (count > 0) {
            count--;
            travel = travel->next;
        }
        lastNode->next = head;
        head = travel->next;
        travel->next = NULL;
        return head;
    }
};
