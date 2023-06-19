class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        This is greedy approach. It won't work for amt =11 and coins = [9, 5,6,1]
        
        sort(coins.begin(), coins.end());
        int n = coins.size();
        int cnt =0;
        for(int i = n-1;i>=0;i--){
            if(coins[i] <= amount){
                int temp = amount / coins[i];
                cnt += temp;
                amount -= (temp * coins[i]);
            }
            if(amount==0) break;
        }
        return amount>0?-1:cnt;
    }
};