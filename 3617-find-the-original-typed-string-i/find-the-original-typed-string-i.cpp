class Solution {
public:
    int possibleStringCount(string word) {
        int dist = 1;
        for(int i=1;i<word.size();i++){
            if(word[i-1] != word[i])
                dist++;
        }
        return word.size()+1-dist;
    }
};