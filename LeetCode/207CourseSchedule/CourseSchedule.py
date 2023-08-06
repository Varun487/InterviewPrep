lass Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        # DFS -> Time:O(n+p), Space:O(p)
        prereq = {i:[] for i in range(numCourses)}
        visited = set()

        for crs, pre in prerequisites:
            prereq[crs].append(pre)
        
        def dfs(course):
            if course in visited:
                return False
            if not prereq[course]:
                return True
            visited.add(course)
            for crs in prereq[course]:
                if not dfs(crs):
                    return False
            visited.remove(course)
            prereq[course] = []
            return True

        for i in range(numCourses):
            if not dfs(i):
                return False
        return True
