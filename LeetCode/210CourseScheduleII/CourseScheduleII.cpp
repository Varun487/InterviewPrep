class Solution {
public:
    vector<int> ans;
    map<int,vector<int>> prereq;
    set<int> visited, cycle;
    bool dfs(int course) {
        if (cycle.find(course) != cycle.end()) {
            return false;
        }
        if (visited.find(course) != visited.end()) {
            return true;
        }
        cycle.insert(course);
        for (int i = 0; i < prereq[course].size(); i++) {
            if (!dfs(prereq[course][i])) {
                return false;
            }
        }
        cycle.erase(course);
        visited.insert(course);
        ans.push_back(course);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // DFS -> Time:O(n+p), Space:O(p)
        for (int i = 0; i < prerequisites.size(); i++) {
            if (prereq.find(prerequisites[i][0]) == prereq.end()) {
                vector<int> p;
                prereq[prerequisites[i][0]] = p;
            }
            prereq[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i)) {
                ans.clear();
                return ans;
            }
        }
        return ans;
    }
};
