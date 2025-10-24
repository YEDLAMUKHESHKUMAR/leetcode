class Solution {
public:
    int nextBeautifulNumber(int n) {
        if(n == 0) return 1;
        for(int i = n + 1; i<= 1224444 ; i++){
            vector<int> check(10, 0);
            int num = i;
            while(num != 0){
                int rem = num % 10;
                check[rem]++;
                num = num / 10;
            }
            int isPossible = true;
            for(int j = 0; j < 10; j++){
                if(check[j] > 0 && check[j] != j){
                    isPossible = false;
                    break;
                } 
            }
            
            if(isPossible) return i;
        }
        return 1224444;
    }
};