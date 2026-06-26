class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivot = -1;
        for ( int i = nums.size()-2 ; i >= 0 ; i--){
            if (nums[i] < nums[i+1]){
                pivot = i;
                break;
            }
        }
        if ( pivot == -1){
            reverse(nums.begin(),nums.end());
            return;
        }
        for ( int i = nums.size()-1 ; i > pivot; i--){
            if(nums[i]>nums[pivot]) {
                swap(nums[i],nums[pivot]);
                break;
            }
        }

        int start = pivot+1;
        int end = nums.size()-1;
        while(start<=end){
            swap(nums[start],nums[end]);
            start++;
            end--;
        }
    }
};