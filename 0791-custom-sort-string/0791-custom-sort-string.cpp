class Solution {
public:
    string customSortString(string order, string s) {
        int n = order.size();
        int m = s.size();
        unordered_map<char,int> mp;
        for(int i = 0;i<m;i++){
            mp[s[i]]++;
        }
        string ans = "";
        for(int i = 0; i< n ; i++){
            if(mp.find(order[i]) != mp.end()){
                int size = mp[order[i]];
                while(size--){
                    ans+=order[i];
                }
                mp.erase(order[i]);
            }

        }
        for(auto i:mp){
            while(i.second--){
                ans+=i.first; 
            }
        }
        return ans;
    }
};