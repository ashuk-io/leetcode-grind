class Solution {
public:
    vector<int> plusOne(vector<int>& nums) {
        for (int i = nums.size()-1 ; i >= 0 ; i--){
            if (i == nums.size()-1){
                nums[i]++;
            }
            if (nums[i] == 10){
                nums[i] = 0;

                if(i != 0){
                    nums[i-1]++;
                }
                else{
                    nums.push_back(0);
                    nums[i] = 1;
                }
            }         
        }
        return nums;
    }

};