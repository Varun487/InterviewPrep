class TrieNode:
    def __init__(self):
        self.children = {}
        self.endOfWord = False

class WordDictionary:

    def __init__(self):
        self.root = TrieNode()

    def addWord(self, word: str) -> None:
        current = self.root
        for letter in word:
            if letter not in current.children:
                current.children[letter] = TrieNode()
            current = current.children[letter]
        current.endOfWord = True

    def search(self, word: str) -> bool:
        def dfs(startIndex, root):
            current = root
            for i in range(startIndex, len(word)):
                letter = word[i]
                if letter == ".":
                    for child in current.children.values():
                        if dfs(i+1, child):
                            return True
                    return False
                else:
                    if letter not in current.children:
                        return False
                    current = current.children[letter]
            return current.endOfWord
        return dfs(0, self.root)
