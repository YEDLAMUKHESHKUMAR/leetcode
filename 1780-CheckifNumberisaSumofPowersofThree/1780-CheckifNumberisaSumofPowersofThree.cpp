class Solution {
public:
    bool checkPowersOfThree(int n) {
        vector<int> powers;
        int pow = 1;
        for(int i = 0; i<16;i++){
            powers.push_back(pow);
            pow *= 3;
        }
        for(int i = 15 ;i >= 0; i--){
            if(n >= powers[i]){
                n -= powers[i];
            }
        }
        return n > 0 ? false : true;
    }
};