class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for(int num: nums){
            minHeap.push(num);
            while(minHeap.size() > k){
                minHeap.pop();
            }
        }

        cout << minHeap.size() << endl;

        return minHeap.top();
    }
};