class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_map<string, int> mp;
        for(auto i: nums) mp[i]++;
        for(int i = 0; i < (1 << n) ; i++){
            string temp = "";
            for(int pos = n - 1 ; pos >= 0; pos--){
                if( ( i >> pos ) & 1 ) temp += "1";
                else temp += "0";
            }
            if(mp.find(temp) == mp.end() ) return temp;
        }
        return "";
    }
};