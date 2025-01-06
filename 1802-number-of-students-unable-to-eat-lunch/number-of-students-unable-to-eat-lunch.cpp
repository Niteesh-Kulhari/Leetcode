class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> sandwich;
        queue<int> student;

        for(int num: students){
            student.push(num);
        }

        for(int num: sandwiches){
            sandwich.push(num);
        }
        int unable = 0;

        while(!sandwich.empty() && !student.empty()){
            if(sandwich.front() == student.front()){
                sandwich.pop();
                student.pop();
                unable = 0;
            }else{
                int temp = student.front();
                student.pop();
                student.push(temp);
                unable++;
            }

            if(unable == student.size()){
                break;
            }
        }

        return student.size();
    }
};