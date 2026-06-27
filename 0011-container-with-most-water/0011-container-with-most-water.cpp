class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int n = height.size();
        int start = 0, end = n-1;
        while(start<end){
            int area = min(height[start],height[end]) * (end-start);
            maxArea = max(maxArea,area);
            if (height[start] > height[end]) end--;
            else start++;          
        }
        return maxArea;
    }
};