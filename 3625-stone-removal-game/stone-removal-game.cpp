class Solution {
public:
    bool canAliceWin(int n) {
        int num = n;
        int curr = 10;
        while(num>=curr){
            num = num-curr;
            curr--; 
        }
        return curr%2 == 0?false:true;
        
    }
};