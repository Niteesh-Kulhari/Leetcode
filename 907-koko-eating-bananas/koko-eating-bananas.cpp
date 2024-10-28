class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans = INT_MAX;
        int lo = 1;
        int hi = *max_element(piles.begin(), piles.end());

        while( lo <= hi){
            int mid = lo + (hi - lo) / 2;
            bool exceeded = false;
            int hours = 0;
            for(int pile: piles){
                hours += (pile + (mid - 1)) / mid;

                if(hours > h){
                    exceeded = true;
                    break;
                }
            }

            if( hours <= h && ! exceeded){
                cout << mid << endl;
                ans = min(ans, mid);
                hi = mid - 1;
            }else{
                lo = mid + 1;
            }
        }


        return ans;
    }
};