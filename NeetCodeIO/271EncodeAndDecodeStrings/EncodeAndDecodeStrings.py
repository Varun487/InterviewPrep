class Solution:
    """
    @param: strs: a list of strings
    @return: encodes a list of strings to a single string.
    """
    def encode(self, strs):
        ans = ""
        for word in strs:
            ans += str(len(word))+"#"+word
        return ans

    """
    @param: str: A string
    @return: decodes a single string to a list of strings
    """
    def decode(self, str):
        ans = []
        i = 0
        while i < len(str):
        	j = i
        	while str[j] != "#":
        		j += 1
        	length = int(str[i:j])
        	ans.append(str[j+1:j+1+length])
        	i = j + 1 + length
        return ans
