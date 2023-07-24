class BSTIterator {
public:
    stack<TreeNode*> s;
    BSTIterator(TreeNode* root) {
        // Iterative DFS -> Time:O(n), Space:O(h)
        while (root) {
            s.push(root);
            root = root->left;
        }
    }
    
    int next() {
        TreeNode *res, *curr;
        res = s.top();
        s.pop();
        curr = res->right;
        while (curr) {
            s.push(curr);
            curr = curr->left;
        }
        return res->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};
