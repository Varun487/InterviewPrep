class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        # Hashmap -> Time:O(mn), Space:O(mn)
        anagram_groups = defaultdict(list)
        for word in strs:
            count = [0 for i in range(26)]
            for c in word:
                count[ord(c) - ord('a')] += 1
            anagram_groups[tuple(count)].append(word)
        ans = []
        for i in anagram_groups:
            ans.append(anagram_groups[i])
        return ans
