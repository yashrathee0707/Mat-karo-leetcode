class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int start = 0;
        int end = m*n - 1;

        while(start <= end){
            int mid = start + (end - start) / 2; //1D
            //Conversion to 2D(row and column index)
            int midElement = matrix[mid / n][mid % n];

            if(midElement == target){
                return true;
            }
            else if(target > midElement){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return false;
    }
};