class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        # BFS -> Time:O(n^2), Space:O(n^2)
        word_set = set(wordList)
        if endWord not in word_set:
            return 0
        q = []
        visited = set()
        q.append([beginWord, 1])
        visited.add(beginWord)
        while q:
            word, level = q.pop(0)
            if word == endWord:
                return level
            for i in range(len(word)):
                for j in range(ord("a"), ord("z")+1):
                    mod_word = word[:i] + chr(j) + word[i+1:]
                    if mod_word in word_set and mod_word not in visited:
                        q.append([mod_word, level + 1])
                        visited.add(mod_word)
        return 0
