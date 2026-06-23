class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<pair<int,int>> v;

        for(int i = 0; i < nums.size(); i++) {
            v.push_back({nums[i], i});
        }

        sort(v.begin(), v.end());

        int start = 0;
        int end = v.size() - 1;

        while(start < end) {
            int sum = v[start].first + v[end].first;

            if(sum < target) start++;
            else if(sum > target) end--;
            else {
                return {v[start].second, v[end].second};
            }
        }

        return {};
    }
};