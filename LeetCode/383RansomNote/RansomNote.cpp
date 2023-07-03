class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // 2 hashmaps -> Time:O(n+m), Space:O(n+m)
        std::map<char, int> magazine_map;
        std::map<char, int> ransom_map;

        for (int i = 0; i < magazine.size(); i++) {
            magazine_map[magazine[i]]++;
        }
        for (int i = 0; i < ransomNote.size(); i++) {
            ransom_map[ransomNote[i]]++;
        }

        for (auto i:ransom_map) {
            if (magazine_map.find(i.first) == magazine_map.end()) {
                return false;
            }
            else if (ransom_map[i.first] > magazine_map[i.first]) {
                return false;
            }
        }

        return true;
    }
};
