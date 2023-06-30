//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    int func(int mid, int n, int m){
        long long ans =1;
        for(int j= 0;j<n;j++){
	            ans *= mid;
                if(ans>m){
                    return 2;
                }
	        }
	        if(ans==m) return 1;
	        return 0;
    }
    
	public:
	int NthRoot(int n, int m)
	{
	    if(m==1) return 1;
	    int start =1, end = m;
	    int mid;
	    while(start <= end){
	       mid = (start + end ) /2;
	       int midN = func(mid, n ,m);
	        
	        if(midN == 1){
	            return mid;
	        }
	        
	        else if(midN ==0){
	            start = mid+1;
	        }
	        else{
	            end = mid -1;
	        }
	    }
	    return -1;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends