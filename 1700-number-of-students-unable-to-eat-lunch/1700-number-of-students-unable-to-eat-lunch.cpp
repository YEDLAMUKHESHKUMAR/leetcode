class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<int> v(2,0);
        int n = students.size();
        for(int i = 0;i<n;i++){
            v[students[i]]++;
        }
        for(int i = 0;i<n;i++){
            if(v[sandwiches[i]] <= 0){
                return n - i;
            }
            v[sandwiches[i]]--;
        }
        return 0;

    }
};