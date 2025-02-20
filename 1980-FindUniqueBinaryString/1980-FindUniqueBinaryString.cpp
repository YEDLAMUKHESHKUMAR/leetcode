class Solution {
public:
    void solve(string temp, int n, unordered_map<string, int> &mp, bool &flag, string &ans){
        if(temp.size() == n){
            if(mp.find(temp) == mp.end()){
                ans = temp; 
                flag = true;
            }
            return;
        }
        if(flag == true) return;

        solve(temp + "0" , n, mp, flag, ans);
        solve(temp + "1" , n, mp, flag, ans);
        
    }
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<string, int> mp; // back tracking approach...bit solution previous submission...
        for(auto i : nums) mp[i]++;
        string ans = "";
        bool flag = false;
        solve("", nums.size(), mp, flag, ans);
        return ans;
    }
};