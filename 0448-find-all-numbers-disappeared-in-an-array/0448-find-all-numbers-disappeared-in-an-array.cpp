class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
            while (i < n) {
            int correctPos = nums[i] - 1;
            if (nums[i] != nums[correctPos]) {
                swap(nums[i], nums[correctPos]);
            } else {
                i++;
            }
        }
        vector<int> ans;
        for (int k = 0; k < n; k++) {
            if (nums[k] != k + 1) {
                ans.push_back(k + 1);
            }
        }
        return ans;
    }
};