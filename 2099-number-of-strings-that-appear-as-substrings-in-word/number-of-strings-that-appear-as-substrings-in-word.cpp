class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt = 0;
        for(string s:patterns){
            int len = s.size();
            if(len > word.size())continue;
            for(int i = 0;i<=word.size()-len;i++){
                if(s == word.substr(i,len)){
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};