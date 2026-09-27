class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        int long sum1 = 0 , sum2 = 0;

        for (int x : source) sum1 += x;
        for (int x : target) sum2 += x;

        return sum1 == sum2;
    }
};