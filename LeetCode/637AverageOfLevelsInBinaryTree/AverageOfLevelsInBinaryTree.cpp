class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        // BFS -> Time:O(n), Space:O(2^h)
        queue<TreeNode*> q;
        q.push(root);
        int size;
        double levelSum;
        TreeNode *node;
        vector<double> ans;
        while (!q.empty()) {
            size = q.size();
            levelSum = 0;
            for (int i = 0; i < size; i++) {
                node = q.front();
                q.pop();
                levelSum += node->val;
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            ans.push_back(levelSum/size);
        }
        return ans;
    }
};
