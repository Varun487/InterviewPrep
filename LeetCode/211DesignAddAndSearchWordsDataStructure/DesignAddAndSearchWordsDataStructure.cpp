struct TrieNode {
    map<char,TrieNode*> children;
    bool endOfWord = false;
};


class WordDictionary {
public:
    TrieNode* root = new TrieNode();
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        TrieNode *current = root;
        for (int i = 0; i < word.size(); i++) {
            if (current->children.find(word[i]) == current->children.end()) {
                current->children[word[i]] = new TrieNode();
            }
            current = current->children[word[i]];
        }
        current->endOfWord = true;
    }

    bool dfs(string &word, int startIndex, TrieNode* node) {
        TrieNode *current = node;
        for (int i = startIndex; i < word.size(); i++) {
            if (word[i] == '.') {
                for (pair<const char, TrieNode *> key:current->children) {
                    if (dfs(word, i + 1, current->children[key.first])) {
                        return true;
                    }
                }
                return false;
            }
            else {
                if (current->children.find(word[i]) == current->children.end()) {
                    return false;
                }
                current = current->children[word[i]];
            }
        }
        return current->endOfWord;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
};
