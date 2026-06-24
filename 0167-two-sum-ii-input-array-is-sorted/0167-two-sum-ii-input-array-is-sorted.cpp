class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> pairs;
        int start = 0;
        int end = numbers.size()-1;
        while(start < end){
            if ( numbers[start] + numbers[end] > target){
                end--;
            }
            else if ( numbers[start] + numbers[end] < target){
                start++;
            }
            else{
                pairs.push_back(start+1);
                pairs.push_back(end+1);
                break;
            }
        }
        return pairs;
    }
};