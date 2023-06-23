class Solution {
    void solve(vector<int>& candidates, int target, vector<int>currComb, int ind, set<vector<int>>&ans ){
        if(target==0){
            ans.insert(currComb);
            return;
        }

        for(int i=ind;i<candidates.size();i++){
            if(i!=ind && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            currComb.push_back(candidates[i]);
            solve(candidates, target- candidates[i], currComb, i+1, ans);
            currComb.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> ans;
        vector<int> currComb;
        sort(candidates.begin(),candidates.end());
        solve(candidates, target, currComb, 0, ans);

        vector<vector<int>> v;
        for(auto it: ans){
            v.push_back(it);
        }

        return v;
    }
};