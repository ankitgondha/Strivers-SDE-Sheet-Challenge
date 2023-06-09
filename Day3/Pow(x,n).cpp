class Solution {
    double solve(double x, int n, double &ans){
        if(n==0) return 1;

        if(n%2==0){
            return solve(x*x, n/2, ans);
        }
        else{
            return x *solve(x, n-1, ans);
        }
    }
public:
    double myPow(double x, int n) {
        if (n == INT_MAX) return (x == 1) ? 1 : (x == -1) ? -1 : 0;
        if (n == INT_MIN) return (x == 1 || x == -1) ? 1 : 0;
        double ans = 1;
        
        ans = solve(x, abs(n), ans );
        if(n<0){
            ans = 1/ans;
        }
        return ans;
    }
};