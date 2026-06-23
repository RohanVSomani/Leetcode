class Solution {
public:
    int findComplement(int num) {
        int n = num;
        int ans = 0;
        int i = 0;
        while(n!=1){
            int rem = n%2;
            n = n/2;
            if(rem == 0)
                ans+=(pow(2,i));
            i++;
        }
        return ans;
    }
};