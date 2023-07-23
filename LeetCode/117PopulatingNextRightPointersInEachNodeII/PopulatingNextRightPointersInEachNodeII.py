class Solution:
    def connect(self, root: 'Node') -> 'Node':
        # BFS -> Time:O(n), Space:O(n)
        if root:
            q = []
            q.append(root)
            while q:
                prev = None
                for i in range(len(q)):
                    top = q.pop(0)
                    top.next = prev
                    prev = top
                    if top.right:
                        q.append(top.right)
                    if top.left:
                        q.append(top.left)
        return root
