class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        // BFS -> Time:O(n^2), Space:O(n^2)
        set<string> geneBank(bank.begin(),bank.end());
        if (geneBank.find(endGene) == geneBank.end()) {
            return -1;
        }
        queue<map<string,int>> q;
        vector<string> geneChars{"A", "C", "G", "T"};
        int level = 0;
        map<string,int> m;
        m[startGene] = level;
        q.push(m);
        set<string> visited;
        visited.insert(startGene);
        while (!q.empty()) {
            map<string,int> node = q.front();
            string gene = node.begin()->first;
            level = node.begin()->second;
            q.pop();
            if (gene == endGene) {
                return level;
            }
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 4; j++) {
                    string modGene = gene.substr(0, i) + geneChars[j] + gene.substr(i+1, 8-i);
                    if (geneBank.find(modGene) != geneBank.end() && 
                    visited.find(modGene) == visited.end()) {
                        visited.insert(modGene);
                        node.clear();
                        node[modGene] = level + 1;
                        q.push(node);
                    }
                }
            }
        }
        return -1;
    }
};
