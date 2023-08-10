struct TrieNode {
    vector<TrieNode*> children = vector<TrieNode*>(26);
    bool endOfWord = false;
};

class Trie {
public:
    // Space:O(ln) l=avgLengthOfWord, n=numOfWords
    TrieNode *root = new TrieNode();

    Trie() {
        
    }
    
    void insert(string word) {
        // Time:O(n), Space:O(n), n=numOfCharactersInWord
        TrieNode *tempNode, *current = root;
        int idx = 0;
        for (int i = 0; i < word.size(); i++) {
            idx = word[i] - 'a';
            if (!current->children[idx]) {
                tempNode = new TrieNode();
                current->children[idx] = tempNode;
            }
            current = current->children[idx];
        }
        current->endOfWord = true;
    }
    
    bool search(string word) {
        // Time:O(n), Space:O(1)
        TrieNode *current = root;
        int idx = 0;
        for (int i = 0; i < word.size(); i++) {
            idx = word[i] - 'a';
            if (!current->children[idx]) {
                return false;
            }
            current = current->children[idx];
        }
        return current->endOfWord;
    }
    
    bool startsWith(string prefix) {
        // Time:O(n), Space:O(1)
        TrieNode *current = root;
        int idx = 0;
        for (int i = 0; i < prefix.size(); i++) {
            idx = prefix[i] - 'a';
            if (!current->children[idx]) {
                return false;
            }
            current = current->children[idx];
        }
        return true;
    }
};
