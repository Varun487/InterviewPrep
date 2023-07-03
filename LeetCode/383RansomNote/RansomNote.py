class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        # 2 Hashmaps -> Time:O(n+m), Space:O(n+m)
        mag_dict = {}
        for i in magazine:
            if i not in mag_dict:
                mag_dict[i] = 0
            mag_dict[i] += 1
        ransom_dict = {}
        for i in ransomNote:
            if i not in ransom_dict:
                ransom_dict[i] = 0
            ransom_dict[i] += 1
        for i in ransom_dict:
            if i not in mag_dict:
                return False
            elif ransom_dict[i] > mag_dict[i]:
                return False
        return True
