class Solution {
public:
    void solve(int i, int sum, int tar, string &s, bool &check){
        int n = s.size();
        // cout<<sum<<endl;
        if(i >= n){
            if(sum == tar) check = true;
            return;
        }
        int add = 0;
        for(int ind = i; ind < n; ind++){
            int num = (s[ind] - '0');
            add = add * 10 + num;
            solve(ind + 1, sum + add, tar, s, check);
        }
    }
    int punishmentNumber(int n) {
        // 1 9 10 36
        // 1296
        // bool check = false;
        // string t = "1296";
        // solve(0, 0, 36, t, check );
        // cout<<check;
        int ans = 0;
        for(int i = 1 ;i <= n; i++){
            int squ = i * i ;
            string s = to_string(squ);
            bool check = false;
            solve(0, 0, i, s, check);
            if(check) {
                ans += squ;
            }
        }
        return ans;
    }
};