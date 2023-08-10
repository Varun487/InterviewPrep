class TrieNode:
    def __init__(self):
        self.children = [None for i in range(26)]
        self.endOfWord = False

class Trie:
    # Space:O(ln) l=avgLengthOfWord, n=numOfWords
    def __init__(self):
        self.root = TrieNode()        

    def insert(self, word: str) -> None:
        # Time:O(n), Space:O(n), n=numOfCharactersInWord
        current = self.root
        for letter in word:
            idx = ord(letter) - 97
            if not current.children[idx]:
                current.children[idx] = TrieNode()
            current = current.children[idx]
        current.endOfWord = True

    def search(self, word: str) -> bool:
        # Time:O(n), Space:O(1)
        current = self.root
        for letter in word:
            idx = ord(letter) - 97
            if not current.children[idx]:
                return False
            current = current.children[idx]
        if current.endOfWord:
            return True
        return False

    def startsWith(self, prefix: str) -> bool:
        # Time:O(n), Space:O(1)
        current = self.root
        for letter in prefix:
            idx = ord(letter) - 97
            if not current.children[idx]:
                return False
            current = current.children[idx]
        return True
