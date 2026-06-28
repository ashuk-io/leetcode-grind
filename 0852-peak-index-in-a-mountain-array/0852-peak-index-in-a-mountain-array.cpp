class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0 , end = arr.size();
        while (start <= end){
            int mid = start + (end - start)/2;
            if (arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) return mid;
            if ( arr[mid] < arr[mid+1]) start = mid;
            else end = mid;
            
        }
        return start;
    }
};