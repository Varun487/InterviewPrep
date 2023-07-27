class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // BFS -> Time:O(n), Space:O(2^h)
        vector<vector<int>> ans;
        if (root == NULL) {
            return ans;
        }
        int size, zigzag=0;
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
            if (zigzag) {
                reverse(level.begin(), level.end());
                zigzag = 0;
            }
            else {
                zigzag = 1;
            }
            ans.push_back(level);
        }
        return ans;
    }
};
