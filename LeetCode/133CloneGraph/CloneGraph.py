"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:

    original_new = {None:None}
    visited = set()

    def dfs(self, node):
        if node == None or node in self.visited:
            return
        self.original_new[node] = Node(node.val)
        self.visited.add(node)
        for n in node.neighbors:
            self.dfs(n)

    # def bfs(self, node):
    #     q = []
    #     q.append(node)
    #     visited = set()
    #     while q:
    #         front = q.pop(0)
    #         new_node = None
    #         if front:
    #             new_node = Node(front.val)
    #             for neighbor in front.neighbors:
    #                 if (neighbor,) not in visited:
    #                     q.append(neighbor)
    #         self.original_new[(front,)] = (new_node,)
    #         visited.add((front,))

    def cloneGraph(self, node: 'Node') -> 'Node':
        self.dfs(node)
        for n in self.original_new:
            if n:
                for neigh in n.neighbors:
                    self.original_new[n].neighbors.append(self.original_new[neigh])
        return self.original_new[node]

    #     self.bfs(node)
    #     for key in self.original_new:
    #         original_node = key[0]
    #         new_node = self.original_new[key][0]
    #         if original_node:
    #             for neighbor in original_node.neighbors:
    #                 new_node.neighbors.append(self.original_new[(neighbor,)][0])
    #     return self.original_new[(node,)][0]
