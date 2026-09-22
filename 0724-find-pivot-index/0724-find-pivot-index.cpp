class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int suffix = accumulate(nums.begin(), nums.end() , 0);
        int prefix = 0;

        for ( int i = 0 ; i < nums.size() ; i++){
            suffix -= nums[i];
            if (suffix == prefix){
                return i;
            }
            prefix += nums[i];
        }
        
        return -1;
    }
};