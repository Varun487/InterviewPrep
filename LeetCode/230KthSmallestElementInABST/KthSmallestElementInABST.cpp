class Solution {
public:
    int ans = -1;
    int index = 1;
    void inorder(TreeNode* root, int k) {
        if (!root) {
            return;
        }
        inorder(root->left, k);
        if (k == index) {
            ans = root->val;
        }
        index++;
        inorder(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        // DFS -> Time:O(n), Space:O(h)
        inorder(root, k);
        return ans;
    }
};
