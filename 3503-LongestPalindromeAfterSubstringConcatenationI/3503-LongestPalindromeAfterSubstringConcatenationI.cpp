// Last updated: 3/30/2025, 12:44:18 PM
class Solution {
public:
    bool isPalindrome(string temp, string temp2 ){
        temp += temp2;
        for(int i = 0; i < temp.size() / 2 ; i++){
            if(temp[i] != temp[temp.size() - i - 1]){
                return false;
            }
        }
        return true;
    }
    int longestPalindrome(string s, string t) {
        int n = s.size();
        int m = t.size(), maxi = 0;
        for(int i = 0; i < n ;i++){
            string temp = "";
            for(int j = i ; j < n ;j++){
                temp += s[j];
                int s1 = temp.size();
                if(isPalindrome(temp,"")) maxi = max(maxi, s1);
                for(int i1 = 0; i1 < m ; i1++){
                    string temp1 ="";
                    for(int j1 = i1 ; j1 < m ; j1++){
                        temp1+= t[j1];
                        int s2 = temp1.size();
                        if(isPalindrome(temp1, "")) maxi = max(maxi, s2);
                        if(isPalindrome(temp, temp1)){
                            maxi = max(maxi, s1 + s2);
                        }
                    }
                }
            }
        }
        return maxi;
    }
};