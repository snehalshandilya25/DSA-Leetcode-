class Solution {
public:
    int firstUniqChar(string s) {
        /* int freq[26] = {0};

        // Step 1: Count frequency of each character
        for(int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++;
        }

        // Step 2: Find the first non-repeating character
        for(int i = 0; i < s.length(); i++) {

            if(freq[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1; */

        int freq[26]={0};
        queue<pair<char,int>> q;

        for(int i=0;i<s.length();i++){
            char ch=s[i];
            freq[ch-'a']++;
            q.push({ch,i});
            while(!q.empty() && freq[q.front().first-'a']>1){
                q.pop();
            }
        }
         if(q.empty()){
                return -1;
            }
        return q.front().second;
    }
};