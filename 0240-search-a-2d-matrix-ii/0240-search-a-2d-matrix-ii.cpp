class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int i = 0 ; i < matrix.size() ; i++){
            int st = 0 , end = matrix[0].size()-1;
            while(st <= end){
                int mid = st + ( end - st )/2;
                if(matrix[i][mid] == target) return true;
                else if ( target > matrix[i][mid]) st = mid+1;
                else end = mid-1;
            }
        }
        return false;
    }
};