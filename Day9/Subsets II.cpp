class Solution {
    void solve(vector<int> &nums, int ind , int N, vector<vector<int>> &ans, vector<int>&temp){
        ans.push_back(temp);
        for(int i =ind; i<N;i++){
            if(i!=ind && nums[i]== nums[i-1]){
                continue;
            } 

            temp.push_back(nums[i]);
            solve(nums, i+1, N, ans, temp);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int N= nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        solve(nums, 0 , N, ans, temp);

        return ans;
    }
};