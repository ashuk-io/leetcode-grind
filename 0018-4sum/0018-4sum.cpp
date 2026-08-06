class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for ( int i = 0 ; i < nums.size() ; i++){
            if( i > 0 && nums[i] == nums[i-1]) continue;

            for( int j = i+1 ; j < nums.size() ;){
                int start = j+1;
                int end = nums.size()-1;

                while (start < end){
                    long long sum = (long long)nums[i]+(long long)nums[j]+(long long)nums[start]+(long long)nums[end];

                    if(sum < target) start++;
                    else if(sum > target) end--;
                    else{
                        ans.push_back({nums[i],nums[j],nums[start],nums[end]});
                        start++; end--;
                        while(start < end && nums[start]==nums[start-1]) start++;
                    }
                }
                
                j++;
                while( j < nums.size() && nums[j] == nums[j-1]) j++;
            }
        }
        return ans;
    }
};