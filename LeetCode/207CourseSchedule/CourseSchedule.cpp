class Solution {
public:
    bool dfs(int course, map<int,vector<int>> &prereq, set<int> &visited) {
        if (visited.find(course) != visited.end()) {
            return false;
        }
        if (prereq[course].size() == 0) {
            return true;
        }
        visited.insert(course);
        for (int i = 0; i < prereq[course].size(); i++) {
            if (!dfs(prereq[course][i], prereq, visited)) {
                return false;
            }
        }
        visited.erase(course);
        prereq[course].clear();
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // DFS -> Time:O(n+p), Space:O(p)
        map<int,vector<int>> prereq;
        set<int> visited;
        for (int i = 0; i < prerequisites.size(); i++) {
            if (prereq.find(prerequisites[i][0]) == prereq.end()) {
                vector<int> p;
                prereq[prerequisites[i][0]] = p;
            }
            prereq[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i, prereq, visited)) {
                return false;
            }
        }
        return true;
    }
};
