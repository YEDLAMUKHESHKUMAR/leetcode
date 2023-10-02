class Solution {
public:
    bool palindrome(string &s ,int st,int end){
        while(st<end){
            if(s[st++]!=s[end--]){
                return false;
            }
        }
        return true;
    }
    void solve(int ind,string &s,vector<string> &temp,vector<vector<string>> &ans){
        int n=s.size();
        if(ind==n){
            ans.push_back(temp);
        }
        else{
             for(int i = ind ; i<n;i++){
                if(palindrome(s,ind,i)){
                    temp.push_back(s.substr(ind,i - ind + 1 ));
                    solve(i+1,s,temp,ans);
                    temp.pop_back();
                }
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(0,s,temp,ans);
        return ans;
    }
};