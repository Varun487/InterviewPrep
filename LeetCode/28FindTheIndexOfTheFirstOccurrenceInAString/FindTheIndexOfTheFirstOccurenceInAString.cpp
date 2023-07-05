class Solution {
public:
    int strStr(string haystack, string needle) {
        // Double pass -> Time:O(nm), Space:O(1) n=len(haystack),m=len(needle)
        int j, start, i = 0;
        while (i < haystack.size()) {
            start = 0;
            while (start < needle.size() && needle[start] == haystack[start+i]){
                start++;
            }
            if (start == needle.size()) {
                return i;
            }
            i++;
        }
        return -1;
    }
};
