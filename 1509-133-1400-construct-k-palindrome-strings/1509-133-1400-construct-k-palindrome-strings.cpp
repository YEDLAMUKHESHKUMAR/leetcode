class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        if(n < k) return false;
        vector<int> mp(26,0);
        for(int i = 0 ; i <n ;i++){
            mp[s[i] - 'a']++;  // :)
        }
        int odd = 0;
        int even2 = 0;
        for(int i = 0 ; i<26 ;i++){
            if(mp[i] % 2 != 0){
                odd++;
                mp[i]--;
            }
            even2 += (mp[i] / 2);
        }
        if(odd > k) return false;
        return true; // :) this (return true)  proof took time to realize, see, if n >= k, we can always make palindrome right?...
        // now we put all the odd chars ( extras ) , in 1 palindrome each.. 
        // now we left with (k - odd) palindromes...
        // we can play with evens as we want...it doesn't matter how we put (either one in each, and later put more)
        // at the end we can put, since n >= k ... we already took care of n < k ... 
        // so even if we just take largest even count and put 1 char in each palindrome, we only be left with "atmost" one odd char of it...
        //and booyah, we can put this odd char of it , in any of the palindrome (because we used this char once in each palindrome, so put this odd char in that palind, to make it even...)  

    }
};