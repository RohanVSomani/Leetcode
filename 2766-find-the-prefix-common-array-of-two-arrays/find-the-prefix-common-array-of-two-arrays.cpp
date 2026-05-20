class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> va(A.size()+1,0);
        vector<int> vb(A.size()+1,0);
        vector<int> ans;
        for(int i=0;i<A.size();i++){
            va[A[i]]++;
            vb[B[i]]++;
            int cnt = 0;
            for(int i=0;i<va.size();i++){
                if(va[i]==vb[i])
                cnt+=va[i];
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};