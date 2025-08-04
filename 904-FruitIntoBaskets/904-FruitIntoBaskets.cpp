// Last updated: 8/4/2025, 9:56:07 AM
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int j = 0, ans = 0;
        unordered_map<int,int> mp;
        for(int i = 0; i<n;i++){
            mp[fruits[i]]++;
            while((int) mp.size() >= 3){
                mp[fruits[j]]--;
                if(mp[fruits[j]] == 0) mp.erase(fruits[j]);
                j++;
            }
            ans = max(ans, i - j + 1);
        }   
        return ans;
    }
};