class Solution {
public:
    long long minimumSteps(string s) {
        long long steps = 0;
        int n = s.size();
        int j = n-1;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1'){
                steps += (j-i);
                j--;
            }
        }
        return steps;
    }
};