class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        set<vector<int>>s;
        sort(nums.begin(), nums.end());
        int n =nums.size();
        for(int i=0; i<n; i++){
            for(int j= i+1; j<n; j++){
                int k = j+1;
                int l = n-1;
                long long int sum =0;
                while(k<l){
                    sum= (long long)nums[i] + (long long)nums[j] + (long long)nums[k] +(long long)nums[l];
                    if(sum == target){
                        s.insert({nums[i] , nums[j] , nums[k] , nums[l]});
                        k++;
                        l--;
                    }
                    else if(sum<target){
                        k++;
                    }
                    else{
                        l--;
                    }
                }

            }
        }

        for(auto p : s){
            ans.push_back(p);
        }
        return ans;
    }
};