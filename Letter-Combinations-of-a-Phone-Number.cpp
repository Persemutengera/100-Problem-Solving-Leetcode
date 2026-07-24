class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        if (digits.empty()) return {};

        unordered_map<char, string> phone = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        vector<string> result;
        string current;

        backtrack(0, digits, phone, current, result);

        return result;
    }

private:
    void backtrack(int index, string &digits,
                   unordered_map<char, string> &phone,
                   string &current,
                   vector<string> &result) {

        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        string letters = phone[digits[index]];

        for (char c : letters) {
            current.push_back(c);
            backtrack(index + 1, digits, phone, current, result);
            current.pop_back(); // Backtrack
        }
    }
};
