class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() <= 1) return s.length();
        
        map<char, int> mp;
        int start = 0;
        int maxLen = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (mp.find(s[i]) != mp.end()) {
                // If the current character is already in the map, update the start position
                // to the next index of the repeated character.
                start = max(start, mp[s[i]] + 1);
            }
            
            // Update the character's last index in the map.
            mp[s[i]] = i;
            
            // Update the maximum length of the substring.
            maxLen = max(maxLen, i - start + 1);
        }
        
        return maxLen;
    }
};
        