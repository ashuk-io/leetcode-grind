class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end());
        int ans = 0;
        int start  = 0;
        int end = nums.size() - 1;
        while ( start < end ){
            if ( nums[start] + nums[end] < target )
            {
                ans += end-start;
                start ++;
            }
            else {
                end --;
            }
        }
        return ans;
    }
};