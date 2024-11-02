class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0){
            return 0;
        }
        int minPrice = INT_MAX;
        int maxProf = 0;

        for(int i=0; i<prices.size(); i++){
            if(prices[i] < minPrice){
                minPrice = prices[i];
            }else {
                maxProf = max(maxProf, prices[i] - minPrice);
            }
        }

        return maxProf;
    }
};