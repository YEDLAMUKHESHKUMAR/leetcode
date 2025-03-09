class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        // 0 1 0 1 0 0 1 0 1 0 1 0 0 1
        int n = colors.size();
        int ans = 0, c = 1;
        vector<int> nums;
        for(int i = 0; i < n ;i++){
            nums.push_back(colors[i]);
        }
        for(int i = 0; i < (k - 1) ; i++){
            nums.push_back(colors[i]);
        }
        for(int i = 0 ;i < nums.size() ;i++) cout<<nums[i]<<" ";
        for(int i = 1 ; i < nums.size(); i++){
            if(c >= k) ans++;
            if( ( nums[i] ^ nums[i - 1] ) == 0 ){ // opposite bits ... 
                c = 1;
            }
            else c++;
        }
        if(c >= k ) ans++;
        return ans;

    }
};