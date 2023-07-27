class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // BFS -> Time:O(n), Space:O(2^h)
        vector<vector<int>> ans;
        if (root == NULL) {
            return ans;
        }
        int size;
        TreeNode *front;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> level;
            size = q.size();
            for(int i = 0; i < size; i++) {
                front = q.front();
                q.pop();
                level.push_back(front->val);
                if (front->left) {
                    q.push(front->left);
                }
                if (front->right) {
                    q.push(front->right);
                }
            }
            ans.push_back(level);
        }
        return ans;
    }
};
