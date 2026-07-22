class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int lo = 0;
        int high = m*n - 1;
        while(lo <= high)
        {
            int mid = (lo + high) / 2;
            int i = mid / n;
            int j = mid % n;
            int ele = matrix[i][j];
            if(ele > target)
                high = mid - 1;
            else if(ele < target)
                lo = mid + 1;
            else 
                return true;
        }
        return false;
    }
};
