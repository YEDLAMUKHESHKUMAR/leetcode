class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        if(n < 4) return 0;
        unordered_map<int,int> mp;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<n;i++) mp[nums[i]]++; // notes
        unordered_map<int,int> allProduct;
        for(int i = 0;i<n;i++){
            for(int j = i+1; j<n;j++){
                allProduct[nums[i] * nums[j]]++;
            }
        }
        int ans = 0;
        for(auto i:allProduct){
            int num = i.first;
            int valid = i.second;
            // for(int j = 1 ; j<= sqrt(num) ;j++){ // no need of this .... tle 
            //     if(j == num / j) continue;
            //     if(num % j == 0){
            //         if(mp.find(j) != mp.end() && mp.find(num / j) != mp.end() ){
            //             valid++;
            //         }
            //     }
            // }
            if(valid > 1 ){
                ans += (valid * (4 * (valid - 1)));  // :)
            }
            
        }
        return ans;

    }
};