class Solution:
    original_new = {}

    def bfs(self, node):
        q = []
        q.append(node)
        visited = set()
        while q:
            front = q.pop(0)
            new_node = None
            if front:
                new_node = Node(front.val)
                for neighbor in front.neighbors:
                    if (neighbor,) not in visited:
                        q.append(neighbor)
            self.original_new[(front,)] = (new_node,)
            visited.add((front,))

    def cloneGraph(self, node: 'Node') -> 'Node':
        # BFS -> Time:O(n), Space:O(n)
        self.bfs(node)
        for key in self.original_new:
            original_node = key[0]
            new_node = self.original_new[key][0]
            if original_node:
                for neighbor in original_node.neighbors:
                    new_node.neighbors.append(self.original_new[(neighbor,)][0])
        return self.original_new[(node,)][0]
