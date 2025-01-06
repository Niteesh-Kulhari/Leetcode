class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count0 = 0, count1 = 0;

        for(int student: students){
            if(student == 0){
                count0++;
            }else{
                count1++;
            }
        }

        for(int sandwich: sandwiches){
            if(sandwich == 0){
                if(count0 > 0){
                    count0--;
                }else{
                    return count1;
                }
            }else if(sandwich == 1){
                if(count1 > 0){
                    count1--;
                }else{
                    return count0;
                }
            }
        }

        return 0;
    }
};