class Solution {
public:
    Node* connect(Node* root) {
        // BFS -> Time:O(n), Space:O(n)
        if (root) {
            queue<Node*> q;
            q.push(root);
            Node *front, *prev;
            while (!q.empty()) {
                int n = q.size();
                prev = NULL;
                for (int i = 0; i < n; i++) {
                    front = q.front();
                    q.pop();
                    front->next = prev;
                    prev = front;
                    if (front->right) {
                        q.push(front->right);
                    }
                    if (front->left) {
                        q.push(front->left);
                    }
                }
            }
        }
        return root;
    }
};
