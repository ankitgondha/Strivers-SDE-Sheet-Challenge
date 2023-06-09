class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = matrix.size();
        int j = matrix[0].size();

        int s=0;
        int e = i*j -1;




        while(s<=e){
        int mid = s + (e-s)/2;
            int ele = matrix[mid/j][mid%j];
            if(target==ele){
                return 1;
            }
            if (target<ele){
                e = mid-1;
            }
            if (target>ele){
                s=mid+1;
            }
        }
    return 0;
    }
};