class Solution {
public:
    int numberOfSubstrings(string s) {
        // :) 
        // total no of possible substrings - no of substrings doesnot contain a,b,c 
        vector<int> freqOfABC(3,0);
        int n = s.size();
        int ans = 0;
        // long long totalSubarrays = n*(n+1)/2 ;  // :)
        int zeroOccurrence = 0 ;
        int j=0 , count=0;
        for(int i=0;i<n;i++){
            freqOfABC[s[i]-'a']++;
            if(freqOfABC[s[i]-'a'] == 1){
                count++;
            }
            while(j<n && count > 2){
                ans += (n-i) ;      // see notes for detailed explanation 
                freqOfABC[s[j]-'a']--;
                if(freqOfABC[s[j]-'a'] == 0){
                    count--;
                }
                j++;
            }
            // zeroOccurrence += i - j + 1;
        }
        // return n*(n+1)/2 - zeroOccurrence ;
        return ans;
    }
};