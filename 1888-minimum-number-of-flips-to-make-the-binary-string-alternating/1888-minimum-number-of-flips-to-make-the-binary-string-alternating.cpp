class Solution {
public:
    int solve(int k, string& s, string& target){
        int n = s.size();
        int ans = n;
        int minMisMatches = 0;
        for(int i = 0 ; i < k ; i++){
            if(s[i] != target[i]) minMisMatches++;
        }
        ans = n;
        for(int i = k ; i < n ; i++){
            if(s[i - k] != target[i - k]) minMisMatches--;
            if(s[i] != target[i]) minMisMatches++;
            ans = min(ans, minMisMatches);
        }
        return ans;
    }
    int minFlips(string s) {
        int m = s.size();
        s = s + s;
        int n = s.size();
        string stWithO = "";
        string stWithZ = "";
        for(int i = 0; i < n; i++){
            if(i % 2 == 0) {
                stWithZ += "0";
                stWithO += "1";
            }
            else{
                stWithO += "0";
                stWithZ += "1";
            }
        }
        int ans = min( solve(m, s, stWithZ), solve(m, s, stWithO));
        return ans;


    }
};