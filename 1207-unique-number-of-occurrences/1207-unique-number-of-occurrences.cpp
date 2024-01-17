class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        int n=arr.size();
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        unordered_map<int,int> ans;
        for(auto i:mp){
            ans[i.second]++;
            if(ans[i.second]>1) return false;
        }
        return true;
    }
};