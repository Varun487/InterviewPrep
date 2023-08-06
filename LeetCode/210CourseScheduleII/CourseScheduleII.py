class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        # DFS -> Time:O(n+p), Space:O(p)
        prereq = {i: [] for i in range(numCourses)}
        visited, cycle = set(), set()
        ans = []

        for crs, pre in prerequisites:
            prereq[crs].append(pre)

        def dfs(course):
            if course in cycle:
                return False
            if course in visited:
                return True
            cycle.add(course)
            for pre in prereq[course]:
                if not dfs(pre):
                    return False
            cycle.remove(course)
            visited.add(course)
            ans.append(course)
            return True

        for i in range(numCourses):
            if not dfs(i):
                return []
        
        return ans
