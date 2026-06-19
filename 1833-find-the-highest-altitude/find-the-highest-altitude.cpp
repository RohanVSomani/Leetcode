class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int alt = 0;
        int maxi = 0;
        for(int g: gain){
            alt+=g;
            maxi = max(maxi, alt);
        }
        return maxi;
    }
};