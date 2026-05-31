class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long planet = mass;
        for(int n:asteroids){
            if(planet>=n)
            planet+=n;
            else
            return false;
        }
        return true;
    }
};