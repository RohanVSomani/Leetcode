class Solution {
public:
    double angleClock(int hour, int minutes) {
        if(hour==12)
        hour=0;
        float mins = minutes*6;
        float diff =(float) minutes/2;
        float hr = hour*30;
        float ans = (hr+diff)-mins;
        cout<<mins<<" "<<diff<<" "<<hr;
        return min(abs(ans),360-abs(ans));
    }
};