class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // DFS Space optimized -> Time:O(n), Space:O(1)
        TreeNode* curr = root;
        while (curr) {
            if (p->val < curr->val && q->val < curr->val) {
                curr = curr->left;
            }
            else if (p->val > curr->val && q->val > curr->val) {
                curr = curr->right;
            }
            else {
                return curr;
            }
        }
        return curr;

        // // DFS -> Time:O(n), Space:O(h)
        // if (p->val < root->val && q->val < root->val) {
        //     return lowestCommonAncestor(root->left, p, q);
        // }
        // else if (p->val > root->val && q->val > root->val) {
        //     return lowestCommonAncestor(root->right, p, q);
        // }
        // return root;
    }
};
