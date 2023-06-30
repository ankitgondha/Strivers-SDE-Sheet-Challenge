class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<double> v(nums1.begin(), nums1.end());
        v.insert(v.end(), nums2.begin(), nums2.end());
        sort(v.begin(), v.end());

        int n = v.size();
        double ans= 0.0;
        if(n%2==1){
            ans = v[n/2];
        }
        else{
            ans = (v[(n-1)/2] + v[(n+1)/2]) /2;
        }
        return ans;
    }
};