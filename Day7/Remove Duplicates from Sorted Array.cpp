class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        int n= nums.size();
        vector<int>::iterator it;
 
        it = nums.end();
        it--;
        for(int i=n-1; i>0;i--){
            if(nums[i] == nums[i-1]){
                // nums.pop_back();
                nums.erase(it);
                count++;
            }
            it--;
        }
        return n-count;
    }
};