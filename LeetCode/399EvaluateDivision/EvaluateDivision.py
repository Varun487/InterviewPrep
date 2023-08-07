class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        # BFS -> Time:O(n.(v+e)), Space:O(v+e)
        adj = {}
        for i in range(len(equations)):
            a,b = equations[i]
            if a not in adj:
                adj[a] = []
            if b not in adj:
                adj[b] = []
            adj[a].append([b, values[i]])
            adj[b].append([a, 1/values[i]])
        def bfs(src, target):
            if src not in adj or target not in adj:
                return -1
            q = []
            visited = set()
            q.append([src, 1])
            visited.add(src)
            while q:
                n, w = q.pop(0)
                if n == target:
                    return w
                for neighbour, weight in adj[n]:
                    if neighbour not in visited:
                        q.append([neighbour, w * weight])
                        visited.add(neighbour)
            return -1
        ans = []
        for q in queries:
            ans.append(bfs(q[0], q[1]))
        return ans
