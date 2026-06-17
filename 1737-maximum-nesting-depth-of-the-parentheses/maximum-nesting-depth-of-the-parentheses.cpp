class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int i =0;
        int maxi = INT_MIN;
        while(i<s.size()){
            char c = s[i];
            if(s[i]=='(')
                st.push(c);
            else if(c==')')
                st.pop();
            else
                cout<<"num\t";
            maxi = max(maxi,(int)st.size());
            i++;
        }
        return maxi;
    }
};