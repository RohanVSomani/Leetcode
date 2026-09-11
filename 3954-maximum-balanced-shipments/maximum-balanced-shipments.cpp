class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int cnt = 0;
        int maxi = weight[0];
        for(int i=1;i<weight.size();i++){
            if(weight[i]<maxi){
                cnt++;
                maxi = weight[i+1];
                i++;
            }
            else{
                maxi = weight[i];
            }
        }
        return cnt;
    }
};