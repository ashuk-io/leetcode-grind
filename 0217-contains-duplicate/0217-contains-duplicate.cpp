class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> visited;
        for ( int val : nums){
            if(visited.count(val) > 0){
                return true;
            }
            visited.insert(val);
        }
        return false;
    }
};