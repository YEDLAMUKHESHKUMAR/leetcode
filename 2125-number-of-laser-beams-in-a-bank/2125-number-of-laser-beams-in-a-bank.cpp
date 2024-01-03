class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int totalLasers = 0;
        int mul = 0;
        int n = bank.size();
        int m = bank[0].size();
        for(int i=0;i<n;i++){
            int sd = 0;
            for(int j=0;j<m;j++){
                if(bank[i][j] == '1'){
                    sd++;
                }
            }
            if(sd != 0){
                if(mul != 0){
                    totalLasers  = totalLasers + ( sd * mul );
                }
                mul = sd ;
            }
        }
        return totalLasers;
        
    }
};