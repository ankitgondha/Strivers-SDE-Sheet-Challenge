class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit=0,min=INT_MAX;
        for(int i=0 ; i<prices.size(); i++){
                if(prices[i]<min){
                    min=prices[i];
                }
                else if(prices[i]-min>maxprofit){
                    maxprofit=prices[i]-min;
                }
        }
        

        return maxprofit;
    }
};