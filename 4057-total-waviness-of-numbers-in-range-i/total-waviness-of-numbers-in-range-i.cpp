class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int n = num1;
        int ans = 0;
        while(n<=num2){
            if((n/100) == 0){
                n++;
                continue;
            }
            int temp = n;
            int fullprev = temp % 10;
            temp = temp/10;
            int prev = temp%10;
            temp = temp/10;
            while(temp!=0){
                int curr = temp%10;
                if(prev<fullprev && prev<curr)
                    ans+=1;
                else if(prev>fullprev && prev>curr)
                    ans+=1;
                fullprev = prev;
                prev = curr;
                temp = temp/10;
            }
            n=n+1;
        }
        return ans;
    }
};