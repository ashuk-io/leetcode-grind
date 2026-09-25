class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closestSum = INT_MAX / 2;

        for ( int i = 0 ; i < nums.size()-2 ; i++){
            int start = i+1 , end = nums.size()-1;

            while(start < end){
                int currentSum = nums[i] + nums[start] + nums[end];

                if (abs(currentSum - target) < abs(closestSum - target)){
                    closestSum = currentSum;
                }

                if (currentSum > target) end--;
                else if (currentSum < target) start++;
                else return currentSum;
            }

        }
        return closestSum; 

    }
};