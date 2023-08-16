/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // int getListWithMinNode(vector<ListNode*>& lists) {
    //     int minIndex;
    //     int minVal = INT_MAX;
    //     for (int i = 0; i < lists.size(); i++) {
    //         if (lists[i] && lists[i]->val < minVal) {
    //             minVal = lists[i]->val;
    //             minIndex = i;
    //         }
    //     }
    //     return minIndex;
    // }
    // bool listsExist(vector<ListNode*>& lists) {
    //     for (int i = 0; i < lists.size(); i++) {
    //         if (lists[i]) {
    //             return true;
    //         }
    //     }
    //     return false;
    // }
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode *ans = new ListNode(), *travel = ans;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                travel->next = l1;
                l1 = l1->next;
            }
            else {
                travel->next = l2;
                l2 = l2->next;
            }
            travel = travel->next;
        }
        if (l1) {
            travel->next = l1;
        }
        if (l2) {
            travel->next = l2;
        }
        return ans->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // // Brute Force -> Time:O(k.n), Space:O(1)
        // ListNode *ans = new ListNode(), *travel = ans;
        // int minList;
        // while (listsExist(lists)) {
        //     minList = getListWithMinNode(lists);
        //     travel->next = lists[minList];
        //     lists[minList] = lists[minList]->next;
        //     travel = travel->next;
        //     travel->next = NULL;
        // }
        // return ans->next;

        // Divide and Conquer -> Time:O(log(k)*n), Space:O(k)
        vector<ListNode*> mergedLists;
        ListNode *l1, *l2;
        if (lists.size() == 0) {
            return NULL;
        }
        while (lists.size() > 1) {
            mergedLists.clear();
            for (int i = 0; i < lists.size(); i+=2) {
                l1 = lists[i];
                l2 = NULL;
                if ((i + 1) < lists.size()) {
                    l2 = lists[i+1];
                }
                mergedLists.push_back(merge(l1, l2));
            }
            lists = mergedLists;
        }
        return lists[0];
    }
};
