// TIME LIMIT EXCEEDED FOR CODE

class TrieNode {
public:
    map<char,TrieNode*> children;
    bool endOfWord = false;
    void addWord(string word) {
        TrieNode *curr = this;
        for (int i = 0; i < word.size(); i++) {
            if (curr->children.find(word[i]) == curr->children.end()) {
                curr->children[word[i]] = new TrieNode();
            }
            curr = curr->children[word[i]];
        }
        curr->endOfWord = true;
    }
};

class Solution {
public:
    void dfs(vector<vector<char>>& board, set<string> &ans_set, set<vector<int>> &visited, int r, int c, TrieNode* node, string word) {
        vector<int> char_index{r, c};
        if (r < 0 || c < 0 || r == board.size() || c == board[0].size()
            || visited.find(char_index) != visited.end()
            || node->children.find(board[r][c]) == node->children.end()) {
                return;
            }
        visited.insert(char_index);
        node = node->children[board[r][c]];
        word += board[r][c];
        if (node->endOfWord) {
            ans_set.insert(word);
        }
        dfs(board, ans_set, visited, r + 1, c, node, word);
        dfs(board, ans_set, visited, r - 1, c, node, word);
        dfs(board, ans_set, visited, r, c + 1, node, word);
        dfs(board, ans_set, visited, r, c - 1, node, word);
        visited.erase(char_index);
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // Trie + DFS -> Time:O(mn*4^(mn)), Space:O(4^(mn))
        vector<string> ans;
        TrieNode *root = new TrieNode();
        for (int i = 0; i < words.size(); i++) {
            root->addWord(words[i]);
        }

        int rows = board.size(), cols = board[0].size();
        set<string> ans_set;
        set<vector<int>> visited;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                dfs(board, ans_set, visited, i, j, root, "");
            }
        }

        for (string i:ans_set) {
            ans.push_back(i);
        }

        return ans;
    }
};
