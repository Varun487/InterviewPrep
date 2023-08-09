class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // BFS -> Time:O(n^2), Space:O(n^2)
        set<string> wordSet(wordList.begin(),wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) {
            return 0;
        }
        queue<map<string,int>> q;
        int level = 1;
        map<string,int> m;
        m[beginWord] = level;
        q.push(m);
        set<string> visited;
        visited.insert(beginWord);
        while (!q.empty()) {
            map<string,int> node = q.front();
            string word = node.begin()->first;
            level = node.begin()->second;
            q.pop();
            if (word == endWord) {
                return level;
            }
            for (int i = 0; i < word.size(); i++) {
                for (int j = 97; j < 123; j++) {
                    string modWord = word.substr(0, i) + char(j) + word.substr(i+1, word.size()-i);
                    if (wordSet.find(modWord) != wordSet.end() && 
                    visited.find(modWord) == visited.end()) {
                        visited.insert(modWord);
                        node.clear();
                        node[modWord] = level + 1;
                        q.push(node);
                    }
                }
            }
        }
        return 0;
    }
};
