class Solution {
public:
    int numberOfWays(string s) {
        int totalSeats = 0;
        bool secondChair = false;
        int MOD = 1e9+7;
        int n = s.size();
        int startingCut = 0;
        for(int i=0;i<n;i++){
            if(s[i] == 'S'){
                totalSeats++;
                
            }
            if(totalSeats == 2 && secondChair == false) {
                startingCut = i;
                secondChair = true;
            }
        }
        if(totalSeats % 2 != 0  || totalSeats==0) return 0;
        if(totalSeats == 2 || totalSeats == n) return 1;

        long long totalCuts = 1 ;
        int noOfSeats = 2;
        for(int i = startingCut+1 ; i < n ;i++ ){
            int tempCuts = 1;
            while(i<n && noOfSeats == 2 ){
                if(s[i] == 'S') noOfSeats = 1;
                else{
                    tempCuts++;
                }
                i++;
            }
            if(noOfSeats == 1){
                totalCuts = (totalCuts * tempCuts) % MOD ;
            }
            while(i<n && noOfSeats == 1){
                if(s[i] == 'S') noOfSeats = 2 ;
                else i++;
            }
        }
        return totalCuts % MOD;

    }
};