// Last updated: 3/30/2025, 12:44:03 PM
class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        int n = cost.size();
        int mini = INT_MAX;
        vector<int> ans;
        for(int i = 0; i < n ;i++){
            mini = min(mini, cost[i]);
            ans.push_back(mini);
        }
        return ans;
    }
};