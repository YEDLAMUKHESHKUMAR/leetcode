class Solution {
public:
    int addMinimum(string s) {
        int n = s.size();
        string p = "abc";
        int j = 0, i = 0, ans = 0, m = p.size();
        while(i < n){
            if(s[i] != p[j]){
                ans++;
            }
            else{
                i++;
            }
            j = (j + 1 ) % m;
        }
        if(j < m && j != 0){
            ans += (m - j);
        }
        return ans;

    }
};