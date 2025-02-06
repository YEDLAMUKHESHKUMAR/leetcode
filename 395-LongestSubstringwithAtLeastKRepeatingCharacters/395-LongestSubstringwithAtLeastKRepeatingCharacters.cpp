class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        int ans = 0;
        for (int uniq=1; uniq<=26; uniq++){
            vector<int> pre(26, 0);
            int j = 0, ucnt = 0;
            for (int i=0; i<n; i++){
                if (pre[s[i]-'a'] == 0) ucnt++;
                pre[s[i]-'a']++;
                while (ucnt > uniq){
                    if (pre[s[j]-'a'] == 1) ucnt--;
                    pre[s[j]-'a']--;
                    j++;
                }
                bool f = true;
                for (int ind=0; ind<26; ind++){
                    if (pre[ind] ==0 || pre[ind]>=k) continue;
                    f = false;
                    break;
                }
                if (f) ans = max(ans, i-j+1);
            }
        }
        return ans;
    }
};