class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        int maxi = target[0];
        int ans = maxi;
        for(int i = 1; i < n ;i++){
            if(target[i] > maxi ) {
                ans += (target[i] - maxi);
            }
            maxi = target[i] ;

        }
        return ans;

    }
};