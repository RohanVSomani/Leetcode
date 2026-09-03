class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev = {1,1};
        if(rowIndex == 1)
            return prev;
        if(rowIndex == 0)
            return {1};
        for(int i = 1;i<rowIndex;i++){
            vector<int> curr = {1};
            for(int i=1;i<prev.size();i++){
                curr.push_back(prev[i]+prev[i-1]);
            }
            curr.push_back(1);
            prev = curr;
        }
        return prev;
    }
};