class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;
        unordered_set <int> s;
        int sum = 0;
        int a,b;
        for ( int i = 0 ; i < grid.size() ; i++){
            for ( int j = 0 ; j < grid.size() ; j++){
                sum += grid[i][j];
                  
                if ( s.find(grid[i][j]) != s.end()){
                    a = grid[i][j];
                    ans.push_back(a);

                }
                s.insert(grid[i][j]);
            }
        }
        b = ((grid.size()*grid.size()) * ((grid.size()*grid.size())+1)/2) + a - sum;
        ans.push_back(b);
        return ans;
    }
};