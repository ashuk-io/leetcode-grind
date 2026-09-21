class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people, 0);

        int give = 1;
        int i = 0;

        while (candies > 0) {
            int amount = min(give, candies);

            ans[i] += amount;
            candies -= amount;

            give++;
            i = (i + 1) % num_people;
        }

        return ans;
    }
};