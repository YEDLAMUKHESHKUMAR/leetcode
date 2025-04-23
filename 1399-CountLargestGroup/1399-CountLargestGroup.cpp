// Last updated: 4/23/2025, 4:31:27 PM
class Solution {
public:
    int getSum(int n){
        int sum = 0;
        while(n != 0){
            sum += (n % 10);
            n /= 10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        vector<int> groups(40, 0);
        int maxGroup = 0, freq, count = 0;
        for(int i = 1 ; i<= n ;i++){
            int sum = getSum(i);
            groups[sum]++;
            freq = groups[sum];
            maxGroup = max(maxGroup, freq);
        }
        for(int i = 0; i < 40 ;i++){
            if(groups[i] == maxGroup) count++;
        }
        return count;

    }
};