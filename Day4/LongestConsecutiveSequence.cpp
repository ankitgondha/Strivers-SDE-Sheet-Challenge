class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set <int>st;
        if(nums.size()==0) return 0;
        int longest = 1;
        int cnt = 0, max = 0;
        for(int i =0; i< nums.size(); i++){
            st.insert(nums[i]);
        }
        for(int it : st){
            if(st.find(it - 1) == st.end()){
                int cnt = 1;
                int x = it;
                while(st.find(x+1) != st.end()){
                    cnt++;
                    x++;
                }
                longest = cnt > longest? cnt :longest;
            }
        }
        return longest;
    }
};