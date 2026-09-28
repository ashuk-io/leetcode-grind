class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        map<int, int> m;
        for(int x : nums)
            m[x]++;

        vector<int> ans;

        while(!m.empty()) {
            vector<int> remove;

            for(auto &[x, freq] : m) {
                ans.push_back(x);
                freq--;

                if(freq == 0)
                    remove.push_back(x);
            }

            for(int x : remove)
                m.erase(x);
        }

        return ans;
    }
};