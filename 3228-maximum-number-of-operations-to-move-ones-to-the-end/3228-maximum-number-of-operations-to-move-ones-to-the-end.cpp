class Solution {
public:
    int maxOperations(string s) {
        int n = s.size();
        int prevans = 0;
        int ans = 0;
        int ind = n;
        for(int i = n -1 ;i>=0;i--){
            if(s[i] == '1'){
                // dude u have to store it .... instead of adding it again .. like suffix

                if((ind - i) > 1 ) prevans++; 
                ind =  i;
                ans+=prevans;
            }
        }
        return ans;
    }
};