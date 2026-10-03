 

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1,
                                  vector<string>& list2) {
        map<string, int> mp;
        mp[list1[0]] = INT_MIN;
        for (int i = 1; i < list1.size(); i++) {
            mp[list1[i]] = -i;
        }
        if (!mp.contains(list2[0]))
            mp[list2[0]] = INT_MIN;

        else {
            if (mp[list2[0]] != INT_MIN)
                mp[list2[0]] = abs(mp[list2[0]]);
            else
                mp[list2[0]] = 0;
        }

        for (int i = 1; i < list2.size(); i++) {
            if (mp.contains(list2[i])) {
                if (mp[list2[i]] != INT_MIN)
                    mp[list2[i]] = abs(mp[list2[i]]) + i;
                else
                    mp[list2[i]] = i;
            } else
                mp[list2[i]] = -i;
        }
        int minVal = INT_MAX;
        vector<string> ans;
        for (auto& it : mp) {
            if (it.second >= 0 && it.second < minVal) {
                minVal = it.second;
            }
        }
        for (auto& it : mp) {
            if (it.second >= 0 && it.second <= minVal) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};