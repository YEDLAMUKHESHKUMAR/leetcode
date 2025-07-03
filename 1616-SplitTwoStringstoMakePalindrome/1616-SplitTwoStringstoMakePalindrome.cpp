// Last updated: 7/3/2025, 9:32:26 PM
class Solution {
public:
    bool solve(string& a, string &b){
        int n = a.size(), m = b.size();
        int end = 0;
        for(int i = 0; i < n / 2; i++){
            if(b[i] != b[ n - i - 1]){
                end = i + 1;
            }
        }
        cout<<min(m / 2 , end)<<endl;
        bool gone1 = true, gone2 = true;
        for(int i = 0; i < min(m / 2, end) ;i++){
            if(a[i] != b[n - i - 1]) gone1 = false;
            if(a[n - i - 1] != b[i]) gone2 = false;
        }
        if(gone1 || gone2) return true;
        return false;
    }
    bool checkPalindromeFormation(string a, string b) {
        return solve(a, b) | solve(b, a); // :)
    }
};