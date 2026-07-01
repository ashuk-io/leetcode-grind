class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;
        for ( int val : nums){
            if ( count == 0 ){
                candidate = val;
            }
            if (candidate == val){
                count++;           
            }
            else count--;
        }
        count = 0;
        for ( int val : nums ){
            if ( candidate == val){
                count++;
            }
        }
        if (count > nums.size()/2){
            return candidate;
        }
        return -1;
    }
};