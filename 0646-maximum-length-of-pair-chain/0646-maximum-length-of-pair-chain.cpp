class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        int maxi = pairs[0][1];
        int count = 1;
        for(int i = 0; i < n ; i++){
            if(pairs[i][0] <= maxi){
                maxi = min(maxi, pairs[i][1]);
            }
            else{
                count++;
                maxi = pairs[i][1];
            }
        }
        return count;
    }
};