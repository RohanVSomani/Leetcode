class Solution {
public:
    int partitionString(string s) {
        unordered_set<char> se;
        int cnt = 0;
        for(char c:s){
            int size = se.size();
            se.insert(c);
            if(se.size() == size){
                cnt++;
                se.clear();
                se.insert(c);
            }
        }
        return cnt+1;
    }
};