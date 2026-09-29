class Solution {
public:
    int maxSubarray(vector<int>& nums) {
        int l = 0, ans = 1;
        unordered_map<long long, int> mp;

        for(int r = 0; r < nums.size(); r++) {
            while(mp[nums[r]] > 0) {
                for(int i = l + 1; i < r; i++) {
                    long long a = nums[l], b = nums[i];
                    mp[a + b]--;
                    mp[abs(a - b)]--;
                }
                l++;
            }

            for(int i = l; i < r; i++) {
                long long a = nums[i], b = nums[r];
                mp[a + b]++;
                mp[abs(a - b)]++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};