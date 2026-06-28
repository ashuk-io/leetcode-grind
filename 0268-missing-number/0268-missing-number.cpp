class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int sum = nums.size() * (nums.size() + 1)/2;
        return sum - accumulate(nums.begin(), nums.end(),0);
    }
};