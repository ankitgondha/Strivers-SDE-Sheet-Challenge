// STL library 1 line solution 
// next_permutation(nums.begin(), nums.end());

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n= nums.size();
        int i=n-2;
        for(; i>=0; i--){
            if(nums[i+1]>nums[i])
                break;
                
        }
        if(i == -1)
            return reverse(nums.begin(), nums.end());
        
        for(int j=n-1; j>i; j--){
            if(nums[j]>nums[i])
                swap(nums[j], nums[i]);
                break;
        }   
        reverse(nums.begin() + i +1, nums.end());
        // next_permutation(nums.begin(), nums.end());
        return ;
    }
};