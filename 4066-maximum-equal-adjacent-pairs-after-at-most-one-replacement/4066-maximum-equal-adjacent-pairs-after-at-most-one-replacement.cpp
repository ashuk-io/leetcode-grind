class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        map<pair<int,int>, int> m;
        int ans = 0, best = 0;

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i - 1]) {
                ans++;
            } else {
                int x = min(nums[i], nums[i - 1]);
                int y = max(nums[i], nums[i - 1]);
                m[{x, y}]++;
                best = max(best, m[{x, y}]);
            }
        }

        return ans + best;
    }
};