class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        vector<int> pref(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            pref[i + 1] = (pref[i] + nums[i]) % k;
            if (pref[i + 1] < 0)
                pref[i + 1] += k;
        }

        vector<int> first(k, nums.size() + 1);
        first[0] = 0;

        for (int i = 1; i <= nums.size(); i++) {
            if (first[pref[i]] == nums.size() + 1)
                first[pref[i]] = i;
        }

        vector<int> order;
        for (int r = 0; r < k; r++) {
            if (first[r] != nums.size() + 1)
                order.push_back(r);
        }

        sort(order.begin(), order.end(), [&](int a, int b) {
            return first[a] < first[b];
        });

        vector<int> ptr(k, 0);
        vector<int> best(k, nums.size() + 1);

        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            int v = (2LL * nums[i]) % k;
            if (v < 0)
                v += k;

            while (ptr[v] < order.size() &&
                   first[order[ptr[v]]] <= i) {
                int r = order[ptr[v]];
                int x = (r + v) % k;
                best[x] = min(best[x], first[r]);
                ptr[v]++;
            }

            int r = pref[i + 1];

            if (first[r] != nums.size() + 1)
                ans = max(ans, i + 1 - first[r]);

            if (best[r] != nums.size() + 1)
                ans = max(ans, i + 1 - best[r]);
        }
        return ans;
    }
};