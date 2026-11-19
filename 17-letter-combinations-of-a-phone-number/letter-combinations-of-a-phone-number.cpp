class Solution {
public:
    vector<string> letterCombinations(string digits) {
         if(digits.empty()) {
            return {};
        }

        vector<string> mapping = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> ans;
        string temp = "";

        solve(0, digits, mapping, temp, ans);

        return ans;
    }

    void solve(int index, string &digits,
               vector<string> &mapping,
               string &temp, vector<string> &ans) {

        // Base case
        if(index == digits.size()) {
            ans.push_back(temp);
            return;
        }

        // Get letters corresponding to current digit
        string letters = mapping[digits[index] - '0'];

        // Try every possible letter
        for(char ch : letters) {

            temp.push_back(ch);

            solve(index + 1, digits, mapping, temp, ans);

            // Backtracking
            temp.pop_back();
        }
    }
};