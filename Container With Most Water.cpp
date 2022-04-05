class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0;
        int j=n-1;
        int maxArea=INT_MIN;
        while(i<j)
        {
            maxArea=max(min(height[i],height[j])*(j-i),maxArea);
            height[i]<height[j]?i++:j--;
        }
        return maxArea;
    }
};
