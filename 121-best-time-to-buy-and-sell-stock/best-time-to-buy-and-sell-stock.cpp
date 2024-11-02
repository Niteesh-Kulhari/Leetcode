class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int maxProf = 0;

        // for(int i=0; i<prices.size(); i++){
        //     for(int j=i+1; j<prices.size(); j++){
        //         if(prices[j] - prices[i] > maxProf){
        //             maxProf = prices[j] - prices[i];
        //         }
        //     }
        // }

        // return maxProf;

        int maxProf = 0;
        int minPrice = INT_MAX;

        for(int i=0; i<prices.size(); i++){
            if(prices[i] < minPrice){
                minPrice = prices[i];
            }else if(prices[i] - minPrice > maxProf){
                maxProf = prices[i] - minPrice;
            }
        }

        return maxProf;
    }
};