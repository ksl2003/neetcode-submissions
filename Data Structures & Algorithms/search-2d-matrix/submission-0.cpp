class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int low = 0, high = rows - 1;

        while(low <= high) {
            int mid = (low + high) / 2;

            if(matrix[mid][0] <= target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        int presRow = high;

        if(presRow < 0)
            return false;

        low = 0;
        high = cols - 1;

        while(low <= high) {
            int mid = (low + high) / 2;

            if(matrix[presRow][mid] == target)
                return true;
            else if(matrix[presRow][mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return false;
    }
};