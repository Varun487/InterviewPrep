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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // Recursive -> Time:O(n^2), Space:O(n+h)
        if (postorder.size() == 0 || inorder.size() == 0) {
            return NULL;
        }
        int n = postorder.size()-1;
        TreeNode* root = new TreeNode(postorder[n]);
        int i = getIndex(inorder, postorder[n]);
        vector<int> leftPostorder = slice(postorder, 0, i);
        vector<int> rightPostorder = slice(postorder, i, n);
        vector<int> leftInorder = slice(inorder, 0, i);
        vector<int> rightInorder = slice(inorder, i+1, inorder.size());
        root->left = buildTree(leftInorder, leftPostorder);
        root->right = buildTree(rightInorder, rightPostorder);
        return root;

    }
};
