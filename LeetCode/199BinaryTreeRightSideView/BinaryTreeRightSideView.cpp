class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        // BFS -> Time:O(n), Space:O(2^h)
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* node;
        int size;
        while(!q.empty()) {
            ans.push_back(q.back()->val);
            size = q.size();
            for (int i = 0; i < size; i++) {
                node = q.front();
                q.pop();
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
        }
        return ans;
    }
};
