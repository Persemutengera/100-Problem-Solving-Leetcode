class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     unordered_map<char, int> lastIndex;
     int left = 0;
     int maxLength = 0;

     for(int right = 0; right < s.size(); right++) {
        if(lastIndex.find(s[right]) != lastIndex.end() &&
        lastIndex[s[right]] >= left) {
            left = lastIndex[s[right]] + 1;
        }

        lastIndex[s[right]] = right;
        maxLength = max(maxLength, right - left + 1);

     }

     return maxLength;

    }
};
