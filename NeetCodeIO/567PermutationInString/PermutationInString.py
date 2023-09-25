class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        # Sliding window -> Time:O(n), Space:O(n)
        if len(s2) < len(s1):
            return False       
        d_s1, d_s2 = [0]*26, [0]*26
        for i in range(len(s1)):
            d_s1[ord(s1[i])-ord('a')] += 1
            d_s2[ord(s2[i])-ord('a')] += 1
        matches = 0
        for i in range(26):
            if d_s1[i] == d_s2[i]:
                matches += 1
        l = 0
        for r in range(len(s1), len(s2)):
            if matches == 26:
                return True
            index = ord(s2[r]) - ord('a')
            d_s2[index] += 1
            if d_s2[index] == d_s1[index]:
                matches += 1
            elif d_s2[index] == d_s1[index]+1:
                matches -= 1            
            index = ord(s2[l]) - ord('a')
            d_s2[index] -= 1
            if d_s2[index] == d_s1[index]:
                matches += 1
            elif d_s2[index] == d_s1[index]-1:
                matches -= 1            
            l +=1
        return matches == 26

        # # Slidiing window -> Time:O(n*m), Space:O(n)
        # d_s1 = {}
        # for i in s1:
        #     if i not in d_s1:
        #         d_s1[i] = 0
        #     d_s1[i] += 1
        # for i in range(0, len(s2)-len(s1)+1):
        #     d_s2 = {}
        #     s = s2[i:i+len(s1)]
        #     for c in s:
        #         if c not in d_s2:
        #             d_s2[c] = 0
        #         d_s2[c] += 1
        #     if d_s2 == d_s1:
        #         return True
        # return False
