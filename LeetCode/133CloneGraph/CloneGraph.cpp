class Solution {
public:
    map<Node*, Node*> original_new;
    void bfs(Node* node) {
        queue<Node*> q;
        q.push(node);
        set<Node*> visited;
        Node *front, *newNode;
        while (!q.empty()) {
            front = q.front();
            q.pop();
            newNode = NULL;
            if (front) {
                newNode = new Node(front->val);
                for (int i = 0; i < front->neighbors.size(); i++) {
                    if (visited.find(front->neighbors[i]) == visited.end()) {
                        q.push(front->neighbors[i]);
                    }
                }
            }
            original_new[front] = newNode;
            visited.insert(front);
        }
    }
    Node* cloneGraph(Node* node) {
        // BFS -> Time:O(n), Space:O(n)
        bfs(node);
        Node *originalNode, *newNode;
        for (auto i:original_new) {
            originalNode = i.first;
            newNode = i.second;
            if (originalNode) {
                for (int i = 0; i < originalNode->neighbors.size(); i++) {
                    newNode->neighbors.push_back(original_new[originalNode->neighbors[i]]);
                }
            }
        }
        return original_new[node];
    }
};
