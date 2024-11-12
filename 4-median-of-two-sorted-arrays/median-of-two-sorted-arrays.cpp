class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> temp;

        for(int num: nums1){
            temp.push_back(num);
        }

        for(int num: nums2){
            temp.push_back(num);
        }

        sort(temp.begin(), temp.end());

        int size = temp.size();
        double median = 0.0;

        if(size % 2 == 0){
            int index = size/2;
            median = (double(temp[index]) + double(temp[index-1])) / 2;
        }else{
            median = temp[size/2];
        }

        return median;
    }
};