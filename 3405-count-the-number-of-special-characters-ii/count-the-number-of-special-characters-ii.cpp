class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,int> lowerCase;
        int cnt=0;
        for(int i =0;i<word.size();i++){
            char c = word[i];
            if(islower(c)){
                lowerCase[c]=i;
            }
        }
        for(int i=0;i<word.size();i++){
            char c = word[i];
            if(!islower(c)){
                char clower = tolower(c);
                if(lowerCase.contains(clower)){
                    if(lowerCase[clower]<i){
                    cnt++;
                    }
                    lowerCase[clower]=INT_MAX;
                }
            }
        }
        return cnt;
    }
};