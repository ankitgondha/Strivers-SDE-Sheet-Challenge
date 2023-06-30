//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    private:
    bool isPossible(int A[], int N, int M, int mid){
        int pageSum =0;
        int stdcnt= 1;
        for(int i=0; i<N; i++){
            if(pageSum + A[i] <= mid){
                pageSum += A[i];
            }
            else{
                stdcnt++;
                if(A[i] > mid || stdcnt > M )
                    return false;
                    
                pageSum = A[i];
            }
            if(stdcnt > M)
                return false;
        }
        return true;
    }
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        int sum =0;
        for(int i=0; i<N; i++){
            sum += A[i];
        }
        if(M>N) return -1;
        int s =0, e = sum;
        int ans= -1;
        int mid = s+ (e-s)/2;
        while(s<=e){
            if(isPossible(A, N, M, mid)){
                ans = mid;
                e= mid - 1;
            }
            else{
                s = mid + 1;
            }
            mid = s+ (e-s)/2;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends