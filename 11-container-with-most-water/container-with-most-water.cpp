class Solution {
public:
    int maxArea(vector<int>& height) {
     int left = 0;
     int right = height.size()-1;

    int area = INT_MIN;

     while(left < right){
        int h = min(height[left], height[right]);
        int l = right - left;
        int calculatedArea = l * h;
        area = max(area, calculatedArea);
        if( height[left] < height[right]){
            left++;
        }else{
            right--;
        }
     }

     return area;   
    }
};