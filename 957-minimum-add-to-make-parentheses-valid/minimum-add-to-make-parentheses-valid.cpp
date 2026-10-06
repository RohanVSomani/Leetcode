class Solution {
public:
    int minAddToMakeValid(string s) {
        int val = 0;
        int ans = 0;
       for(char c : s){
        if(c==')')
            val--;
        else
            val++;
        if(val == -1){
            val = 0;
            ans++;
        }
       }
       return ans + val;
    }
};