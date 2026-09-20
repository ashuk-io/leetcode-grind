class Solution {
public:
    int findMin(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int smallest = nums[0];
        for(int i = 0 ; i < nums.size() ; i++){
            smallest = min(smallest,nums[i]);
        }
    return smallest;
    }
};