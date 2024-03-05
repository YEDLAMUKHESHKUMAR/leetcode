class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int i = 0 , j = n - 1 ;
        int ans  = n;
        while(i<j){
            char c  = s[i];
            if(s[i] != s[j]) break;
            while(i<j && s[i]==c){
                i++;
            }
            i--; // i just came one step back leaving a character for j to take it
            while(i<j && s[j]==c){
                j--;
            }
            i++; // j might took it or not...we are  back to our position
            if(i==j) return 1;
            if(i>j) return 0;
            ans = min(ans,j-i+1);
        }
        return ans;
        
    }
};