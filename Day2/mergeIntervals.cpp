class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int m = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int flag = 0;

        for(int i =0; i<m; i++){
            int s = intervals[i][0];
            int e = intervals[i][1];
            int j= i+1;
            for(; j<m ; j++){
                
                if((intervals[j][0] <= e && intervals[j][0] >= s) || (intervals[j][1] <= e && intervals[j][1] >= s)|| (intervals[j][0] <= s && intervals[j][1] >= e)){
                    // ans.push_back({min(intervals[i][0], intervals[j][0]), max(intervals[i][1],intervals[j][1])});
                    s= min(s, intervals[j][0]);
                    e = max(e, intervals[j][1]);
                    flag++;
                }
                else{
                    // ans.push_back({intervals[i][0], intervals[i][1]});
                    break;
                }
            }
            // if(flag==0)
                ans.push_back({s, e});

            while(flag){
                i++;
                flag--;
            }
                // ans.push_back({i + 100, j + 99});
        }
        return ans;
    }
};