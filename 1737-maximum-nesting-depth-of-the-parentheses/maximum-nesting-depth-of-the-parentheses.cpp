class Solution {
public:
    int maxDepth(string s) {
        int st=0;
        int i =0;
        int maxi = INT_MIN;
        while(i<s.size()){
            char c = s[i];
            if(c=='(')
                st++;
            else if(c==')')
                st--;
            else
            cout<<"num\t";
            maxi = max(maxi,st);
            i++;
        }
        return maxi;
    }
};