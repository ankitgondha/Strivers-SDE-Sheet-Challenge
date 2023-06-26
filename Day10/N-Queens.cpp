class Solution {
    void solve(int col, int n, vector<vector<string>>&ans, vector<string>&temp, vector<int>&leftRow, vector<int>&upperDia, vector<int>&lowerDia){
        if(col == n){
            ans.push_back(temp);
            return;
        }

        for(int row = 0; row<n; row++){
            if(leftRow[row]==0 && upperDia[n-1 + col -row] ==0 && lowerDia[row+col]==0){
                temp[row][col] ='Q';
                leftRow[row] = 1;
                upperDia[n-1 + col -row] = 1;
                lowerDia[row+col] = 1;

                solve(col+1, n, ans, temp, leftRow, upperDia, lowerDia);

                temp[row][col] ='.';
                leftRow[row] = 0;
                upperDia[n-1 + col -row] = 0;
                lowerDia[row+col] = 0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> temp;
        vector<int>leftRow(n,0), upperDia(2*n-1, 0), lowerDia(2*n -1, 0);
        string s(n, '.');
        for(int i=0;i<n;i++){
            temp.push_back(s);
        }
        solve(0, n, ans, temp, leftRow, upperDia, lowerDia);
        return ans;
    }
};