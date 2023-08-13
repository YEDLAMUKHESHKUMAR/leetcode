class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int sum1=0,sum2=0;
        int n=player1.size();
        bool checkTen=0;
        for(int i=0;i<n;i++){
            int curr1=player1[i];
            int curr2=player2[i];
            
                if((i==1 && player1[0]==10) || i>=2 &&((player1[i-1]==10) || (player1[i-2]==10))){
                    curr1*=2;;
                }
                if((i==1 && player2[0]==10) || i>=2 &&((player2[i-1]==10) || (player2[i-2]==10))){
                    curr2*=2;;
                }
                
                sum1+=curr1;
                sum2+=curr2;
                
            
        }
        if(sum1==sum2) return 0;
        else if(sum1>sum2) return 1;
        return 2;
    }
};