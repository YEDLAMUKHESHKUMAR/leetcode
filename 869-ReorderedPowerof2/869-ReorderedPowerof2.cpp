// Last updated: 8/10/2025, 4:04:39 PM
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        int i = 0;
        int num = 1;
        unordered_map<string,int> powers;
        while(num <= 1000000000){
            num = (1 << i);
            string s = to_string(num);
            sort(s.begin(), s.end());
            powers[s]++;
            i++;
        }
        string s = to_string(n);
        sort(s.begin(), s.end());
        if(powers[s] > 0) return true;
        return false;
    }

};