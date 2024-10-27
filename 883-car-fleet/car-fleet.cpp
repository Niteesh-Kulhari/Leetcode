class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,float>> positions;
        int n = position.size();

        for(int i=0; i<n; i++){
            double time=(double)(target-position[i])/speed[i];
            positions.push_back({position[i], time});
        }
        sort(positions.begin(), positions.end());

        float maxTime = 0.0;
        int count = 0;
        for(int i=n-1; i>=0; i--){
            float time = positions[i].second;

            if(time > maxTime){
                count++;
                maxTime = time;
            }
        }

        return count;
    }
};