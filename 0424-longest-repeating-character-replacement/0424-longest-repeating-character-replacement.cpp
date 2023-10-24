class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> mp(26,0);
        int j=0;
        int maxCharCount = 0 ;      // good one 
        int maxLength = 0;
        int n=s.size();
        for(int i=0;i<n;i++){
            mp[s[i]-'A']++;
            if(maxCharCount < mp[s[i] - 'A']){
                maxCharCount = mp[s[i] - 'A'];
            }
            while(i - j - maxCharCount+1 > k ){
                mp[s[j] - 'A']--;
                j++;
                for(int m = 0;m<26;m++){
                    if(maxCharCount < mp[m]){
                        maxCharCount = mp[m];
                    }
                }
            }
            maxLength = max(maxLength , i-j+1);

        }
        return maxLength;
    }
};