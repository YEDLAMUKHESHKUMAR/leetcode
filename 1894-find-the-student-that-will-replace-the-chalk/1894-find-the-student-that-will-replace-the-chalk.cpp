class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0 ;
        int n = chalk.size();         // :)
        for(int i=0;i<n;i++){
            sum += chalk[i];
        }
        long long remainingChalk = (long long)k % sum;
        if(remainingChalk == n-1) return n-1;
        if(remainingChalk == 0) return 0;
        int ans;
        for(int i=0;i<n;i++){
            if(chalk[i] >= remainingChalk){
                ans = i;
                break;
            }
            remainingChalk -= chalk[i];
            
        }
        return ans;
        
    }
};