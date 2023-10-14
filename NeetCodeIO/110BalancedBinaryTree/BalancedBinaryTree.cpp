class Solution {
public:
    pair<int,bool> getHeight(TreeNode* root) {
        pair<int,bool> ans;
        if (!root) {
            ans.first = 0;
            ans.second = true;
            return ans;
        }
        pair<int,bool> left = getHeight(root->left);
        pair<int,bool> right = getHeight(root->right);
        ans.first = 1 + max(left.first, right.first);
        ans.second = abs(left.first - right.first) <= 1 && left.second && right.second;
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        // DFS -> Time:O(n), Space:O(h)
        return getHeight(root).second;
    }
};
