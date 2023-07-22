class Solution {
public:
    int getIndex(vector<int>& vec, int k) {
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i] == k) {
                return i;
            }
        }
        return -1;
    }
    vector<int> slice(vector<int>& vec, int i, int j) {
        auto start = vec.begin() + i;
        auto end = vec.begin() + j;
        vector<int> result(j - i);
        copy(start, end, result.begin());
        return result;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 || inorder.size() == 0) {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        int i = getIndex(inorder, preorder[0]);
        vector<int> leftPreorder = slice(preorder, 1, i+1);
        vector<int> rightPreorder = slice(preorder, i+1, inorder.size());
        vector<int> leftInorder = slice(inorder, 0, i);
        vector<int> rightInorder = slice(inorder, i+1, inorder.size());
        root->left = buildTree(leftPreorder, leftInorder);
        root->right = buildTree(rightPreorder, rightInorder);
        return root;
    }
};
