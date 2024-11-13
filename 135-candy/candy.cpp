class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> temp(n, 1);
        
        for(int i=0; i<ratings.size(); i++){
            if(i == 0){
                continue;
            }

            if(ratings[i-1] < ratings[i] && temp[i] <= temp[i-1]){
                temp[i] = temp[i - 1] + 1;
            }   
        }

        for(int i = n-1; i>=0; i--){
            if(i == n-1){
                continue;
            }

            if(ratings[i] > ratings[i+1] && temp[i] <= temp[i+1]){
                temp[i] = temp[i + 1] + 1;
            }
        }


        int sum = 0;
        for(int num: temp){
            sum += num;
        }


        return sum;
    }
};