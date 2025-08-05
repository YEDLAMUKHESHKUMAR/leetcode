// Last updated: 8/5/2025, 10:56:48 AM
class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        vector<int> suffix(n + 1, 0);
        prefix[0] = 1;
        int inc = 1;
        for(int i = 1 ; i < n ;i++){
            if(nums[i] > nums[i - 1]) inc++;
            prefix[i] = inc;
        }
        suffix[n - 1] = 1;
        inc = 1;
        for(int i = n - 2;i>=0 ;i-- ){
            if(nums[i] > nums[ i + 1]) inc++;
            suffix[i] = inc;
        }
        vector<int> good;
        for(int i = k ; i < n-k ;i++){
            int l = prefix[ i - 1];
            l = l - ( i - k  >= 0 ? prefix[i - k ] : 0 );
            if(l > 0) continue;
            int r = suffix[i + 1];
            r = r - ( i + k  < n ? suffix[i + k ] : 0 );
            if(r > 0) continue;
            good.push_back(i);

        }
        
        return good;
        
    }
};