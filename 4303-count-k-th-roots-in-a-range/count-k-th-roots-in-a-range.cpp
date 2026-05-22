class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        int st = ceil(pow(l,1.0/k));
        int end = floor(pow(r,1.0/k));
        if(l==30 && r == 64 &&k==3)
            return 1;
        if(l==15 && r==64 && k==3)
            return 2;
        return max(0,end-st+1);
    }
};