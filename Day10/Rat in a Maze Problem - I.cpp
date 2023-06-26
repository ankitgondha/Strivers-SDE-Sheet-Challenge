//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    
    bool check(int y, int z, vector<vector<int>> &visited, vector<vector<int>> &m, int n){
        if((y>=0 && y<n) && (z>=0 && z<n)&& m[y][z]==1 && visited[y][z]==0 ){
            return true;
        }
        else{
            false;
        }
    }
    void solve(vector<vector<int>> &m, vector<string> &ans, int n , int i, int j, string temp, vector<vector<int>> visited){
        if(i==n-1&&j==n-1){
            ans.push_back(temp);
            return;
        }
        visited[i][j]=1;
        //down
            if(check(i+1, j ,visited, m , n)){
                temp.push_back('D');
                solve(m, ans , n, i+1 , j, temp, visited);
                temp.pop_back();
            }
            //right
            if(check(i, j+1, visited, m ,n)){
                temp.push_back('R');
                solve(m, ans , n, i , j+1, temp, visited);
                temp.pop_back();
            }
            //left
            if(check(i, j-1, visited, m ,n)){
                temp.push_back('L');
                solve(m, ans , n, i , j-1, temp, visited);
                temp.pop_back();
            }
            //Up
            if(check(i-1, j ,visited, m , n)){
                temp.push_back('U');
                solve(m, ans , n, i-1 , j, temp, visited);
                temp.pop_back();
            }
            visited[i][j]=0;
        
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        if(m[0][0]==0){
            return ans;
        }
        vector<vector<int>> visited = m;
        for(int i = 0; i<n; i++){
            for(int j= 0; j<n;j++){
                visited[i][j]=0;
                
            }
        }
        string temp = "";
        solve(m, ans , n, 0 , 0, temp, visited);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends