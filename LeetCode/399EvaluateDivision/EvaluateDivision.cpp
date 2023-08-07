class Solution {
public:
    map<string,vector<map<string,double>>> adj;
    double bfs(string a, string b) {
        if (adj.find(a) == adj.end() || adj.find(b) == adj.end()) {
            return -1.0;
        }
        queue<map<string,double>> q;
        set<string> visited;
        map<string,double> m;
        m[a] = 1.0;
        q.push(m);
        visited.insert(a);
        while (!q.empty()) {
            map<string,double> node = q.front();
            q.pop();
            if (node.begin()->first == b) {
                return node[node.begin()->first];
            }
            for (int i = 0; i < adj[node.begin()->first].size(); i++) {
                if (visited.find(adj[node.begin()->first][i].begin()->first) == visited.end()) {
                    map<string,double> temp;
                    temp[adj[node.begin()->first][i].begin()->first] = adj[node.begin()->first][i].begin()->second*node.begin()->second;
                    q.push(temp);
                    visited.insert(adj[node.begin()->first][i].begin()->first);
                }
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // BFS -> Time:O(n.(v+e)), Space:O(v+e)
        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];

            map<string,double> m1;
            m1[b] = val;
            if (adj.find(a) == adj.end()) {
                vector<map<string,double>> p;
                adj[a] = p;
            }
            adj[a].push_back(m1);

            map<string,double> m2;
            m2[a] = 1/val;
            if (adj.find(b) == adj.end()) {
                vector<map<string,double>> p;
                adj[b] = p;
            }
            adj[b].push_back(m2);
        }
        vector<double> ans;
        for (int i = 0; i < queries.size(); i++) {
            ans.push_back(bfs(queries[i][0], queries[i][1]));
        }
        return ans;
    }
};
