class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n= nums.size();
        int p = n/3 +1;
        map<int, int> mp;
        for(auto i : nums){
            mp[i]++;
            if(mp[i] == p){
                ans.push_back(i);
            }
            if(ans.size()==2)
                break;
        }
        return ans;
    }
};