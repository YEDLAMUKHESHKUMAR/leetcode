class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        // notes :) 
        long long ans = 0;
        vector<int> values(n);
        for(int i = 0;i<roads.size();i++){
            values[roads[i][0]]++;
            values[roads[i][1]]++;
        }
        sort(values.begin(),values.end());
        long long val = n;
        for(int  i = n-1 ;i>=0;i--){
            ans =  ans + (val * values[i]);
            val--;
        }
        return ans;

    }
};