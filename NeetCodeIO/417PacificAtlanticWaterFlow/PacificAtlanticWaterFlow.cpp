class Solution {
public:
    void dfs(vector<vector<int>>& heights, int r, int c, set<pair<int,int>> visit, int prev) {
        pair<int,int> p(r, c);
        cout << r << c << endl;
        if (r < 0 || r >= heights.size() || c < 0 || c >= heights[0].size() ||
            visit.find(p) != visit.end() || heights[r][c] < prev) {
                return;
            }
        visit.insert(p);
        dfs(heights, r + 1, c, visit, heights[r][c]);
        dfs(heights, r - 1, c, visit, heights[r][c]);
        dfs(heights, r, c + 1, visit, heights[r][c]);
        dfs(heights, r, c - 1, visit, heights[r][c]);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // DFS -> Time:O((mn)^2), Space:O(mn)
        set<pair<int,int>> pac, atl;
        vector<vector<int>> ans;
        for (int i = 0; i < heights[0].size(); i++) {
            dfs(heights, 0, i, pac, heights[0][i]);
            dfs(heights, heights.size() - 1, i, atl, heights[heights.size() - 1][i]);
        }
        for (int i = 0; i < heights.size(); i++) {
            dfs(heights, i, 0, pac, heights[i][0]);
            dfs(heights, i, heights[0].size() - 1, atl, heights[i][heights[0].size() - 1]);
        }
        for (pair<int,int> p: pac) {
            cout << p.first << p.second << endl;
            if (atl.find(p) != atl.end()) {
                vector<int> temp;
                temp.push_back(p.first);
                temp.push_back(p.second);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
