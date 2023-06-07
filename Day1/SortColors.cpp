class Solution {
public:
    void sortColors(vector<int>& nums) {
        int z = 0;
        int o = 0;
        int t = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]==0)
                z++;
            else if(nums[i]==1)
                o++;
            else
                t++;
        }
        int p = 0;
        while(z){
            nums[p] = 0;
            p++;
            z--;
        }
        while(o){
            nums[p] = 1;
            p++;
            o--;
        }
        while(t){
            nums[p] = 2;
            p++;
            t--;
        }
    }
};