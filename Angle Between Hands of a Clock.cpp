class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minDeg=minutes*6.0;
        double hourDeg=minutes/2.0+(hour%12)*30;
        double ans=abs(minDeg-hourDeg);
        return ans>180.0?360.0-ans:ans;
    }
};
