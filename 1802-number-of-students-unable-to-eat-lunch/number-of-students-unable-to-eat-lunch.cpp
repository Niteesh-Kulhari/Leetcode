class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count0 = 0, count1 = 0;

        // Count the number of students preferring 0s and 1s
        for (int student : students) {
            if (student == 0) count0++;
            else count1++;
        }

        // Serve the sandwiches
        for (int sandwich : sandwiches) {
            if (sandwich == 0) {
                if (count0 > 0) count0--;  // Serve a student who wants 0
                else return count1;       // Remaining students want 1 but only 0s are left
            } else {
                if (count1 > 0) count1--;  // Serve a student who wants 1
                else return count0;       // Remaining students want 0 but only 1s are left
            }
        }

        return 0;
    }
};