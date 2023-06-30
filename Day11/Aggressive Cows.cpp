//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
    
    bool isPossible(int n, int k, vector<int> &stalls, int mid){
        int cows = 1;
        int lastPos = stalls[0];
        for(int i=0; i<n ;i++){
            if(stalls[i]- lastPos >= mid){
                lastPos= stalls[i];
                cows++;
                if(cows==k)
                    return true;
            }
        }
        return false;
    }
public:

    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(), stalls.end());
        int s =0; 
        int e = -1;
        for(int i =0; i<n;i++){
            e=max(e, stalls[i]);
        }
        
        int ans = -1;
        
        while(s<=e){
            int mid = s +( e-s)/2;
            if(isPossible(n, k, stalls, mid)){
                ans = mid;
                s = mid + 1;
            }
            else
                e = mid - 1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends