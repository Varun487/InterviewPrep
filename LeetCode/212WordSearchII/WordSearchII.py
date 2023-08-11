class TrieNode:
    def __init__(self):
        self.children = {}
        self.endOfWord = False
    
    def add_word(self, word):
        curr = self
        for c in word:
            if c not in curr.children:
                curr.children[c] = TrieNode()
            curr = curr.children[c]
        curr.endOfWord = True

class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        # Trie + DFS -> Time:O(mn*4^(mn)), Space:O(4^(mn))
        root = TrieNode()
        for w in words:
            root.add_word(w)
        
        ROWS, COLS = len(board), len(board[0])
        ans, visited = set(), set()

        def dfs(r, c, node, word):
            if (r < 0 or c < 0 or r == ROWS or c == COLS
                or (r, c) in visited
                or board[r][c] not in node.children):
                return
            visited.add((r, c))
            node = node.children[board[r][c]]
            word += board[r][c]
            if node.endOfWord:
                ans.add(word)
            dfs(r + 1, c, node, word)
            dfs(r - 1, c, node, word)
            dfs(r, c + 1, node, word)
            dfs(r, c - 1, node, word)
            visited.remove((r, c))

        for i in range(ROWS):
            for j in range(COLS):
                dfs(i, j, root, "")

        return list(ans)
