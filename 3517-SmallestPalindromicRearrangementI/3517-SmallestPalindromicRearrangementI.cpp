// Last updated: 4/13/2025, 9:33:38 AM
class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        vector<int> mp(26, 0);
        char ch = ' ';
        
        for(int i = 0; i < n; i++){
            mp[s[i] - 'a']++;
        }
        string firstHalf = "";
        for(int i = 0; i < 26 ;i++){
            if(mp[i] % 2 != 0){
                ch = char(i + 'a');
                mp[i]--;
            }
            while(mp[i] > 0 ){
                firstHalf += (char(i + 'a'));
                mp[i] -= 2;
            }
        }
        cout<<firstHalf<<endl;
        string secondHalf = "";
        for(int i = firstHalf.size() - 1; i>=0 ;i--){
            secondHalf += firstHalf[i];
        }
        if(ch != ' ') return firstHalf + ch + secondHalf;
        return firstHalf + secondHalf;
    }
};