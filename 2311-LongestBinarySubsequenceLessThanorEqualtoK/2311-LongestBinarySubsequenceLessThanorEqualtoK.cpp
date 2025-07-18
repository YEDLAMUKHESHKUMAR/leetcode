// Last updated: 6/26/2025, 4:00:37 PM
class Solution {
public:
    int longestSubsequence(string s, int k) {
        // return 1;
        int n = s.size();
        long long pos = 0, sum = 0, len = 0, i;
        for(i = n - 1; i>= 0 && pos < 32; i--){
            if(s[i] == '1') sum += (1LL << pos);
            if(sum > k) break;
            len++;
            pos++;
        }
        cout<<len;
        for(int j = 0; j <= i; j++){
            if(s[j] == '0') len++;
        }
        return len;
    }
};