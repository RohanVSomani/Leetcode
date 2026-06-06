class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> even(26,0);
        vector<int> odd(26,0);
        for(int i =0;i<s1.size();i++){
            int c1 = (int)s1[i]-97 , c2 = (int)s2[i]-97;
            if(i%2==0){
                even[c1]++;
                even[c2]--;
            }
            else{
                odd[c1]++;
                odd[c2]--;
            }
        }
        for(int i=0;i<odd.size();i++){
            if(odd[i]!=0 || even[i]!=0)
            return false;
        }
        return true;
    }
};