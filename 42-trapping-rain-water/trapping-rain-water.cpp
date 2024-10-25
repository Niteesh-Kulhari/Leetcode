class Solution {
public:
    int trap(vector<int>& height) {
        int trap = 0;
        int left = 0;
        int right = height.size()-1;

        int Left_MAX = 0;
        int Right_MAX = 0;

        while( left < right){
            if( height[left] < height[right]){
                height[left] > Left_MAX ? Left_MAX = height[left] : trap += Left_MAX - height[left];
                left++;
            }else{
                height[right] > Right_MAX ? Right_MAX = height[right] : trap+= Right_MAX -height[right];
                right--;
            }
        }

        return trap;
    }
};