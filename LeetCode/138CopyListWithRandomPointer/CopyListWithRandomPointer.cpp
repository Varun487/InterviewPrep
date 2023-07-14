class Solution {
public:
    Node* copyRandomList(Node* head) {
        // 2 passes -> Time:O(n), Space:O(n)
        map<Node*,Node*> m;
        m[NULL] = NULL;
        Node *copy, *curr = head;
        while (curr) {
            m[curr] = new Node(curr->val);
            curr = curr->next;
        }
        curr = head;
        while(curr) {
            copy = m[curr];
            copy->next = m[curr->next];
            copy->random = m[curr->random];
            curr = curr->next;
        }
        return m[head];
    }
};
