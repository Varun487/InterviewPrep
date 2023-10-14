class Solution {
public:
    int ans = 0;
    void countGoodNodes(TreeNode* node, TreeNode* parent) {
        if (!node) return;
        if (!parent || node->val >= parent->val) {
            ans++;
            parent = node;
        }
        countGoodNodes(node->left, parent);
        countGoodNodes(node->right, parent);
    }
    int goodNodes(TreeNode* root) {
        // DFS -> Time:O(n), Space:O(n)
        countGoodNodes(root, NULL);
        return ans;
    }
};
