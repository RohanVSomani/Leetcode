class Solution {
public:
    int maxProduct(int n) {
        vector<int> digs;
        int num = n;
        while(num!=0){
            int rem = num%10;
            digs.push_back(rem);
            num /= 10;
        }
        sort(digs.begin(), digs.end());
        int i = digs.size()-1;
        return digs[i]*digs[i-1];
    }

};