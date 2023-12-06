class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans = "";
        if(n==1){
            if(s[0] == ' ') return ans;
            return s;
        }
        string store = "";
        vector<string> rev;
        int i= 0;
        while(i<n){
            if(s[i]!=' '){
                store+=s[i];
                i++;
            }
            else{
                if(!store.empty()) rev.push_back(store);
                store = "";
                i++;
            }
        }
        if(!store.empty()) rev.push_back(store);
        for(int i=rev.size()-1;i>=0;i--){
            ans+=rev[i];
            if(i!=0) ans+=" ";
        }
        return ans;
    }
};