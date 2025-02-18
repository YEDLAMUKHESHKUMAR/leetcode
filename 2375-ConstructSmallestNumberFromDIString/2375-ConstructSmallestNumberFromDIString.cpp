class Solution {
public:
    string smallestNumber(string s) {
        // IIDID
        // 124365
        // 124356

        // DIDDI
        // 123456
        // 215436

        // DDDD
        // 32145
        int n = s.size();
        string ans = "";
        for(int i = 1; i<=n+1;i++){
            ans += to_string(i);
        }

        for(int i = 1; i<=n;i++){
            if((s[i - 1] == 'I' && ans[i] < ans[i - 1] ) || ( s[i-1] == 'D' && ans[i] > ans[i-1] )){
                swap(ans[i], ans[i-1]);
            }            
            for(int j = i - 1; j > 0 ; j--){
                if((s[j - 1] == 'I' && ans[j] < ans[j - 1] ) || ( s[j-1] == 'D' && ans[j] > ans[j-1] )){
                    swap(ans[j], ans[j-1]);
                }
                else break;
            }
        }

        return ans;
    }
};