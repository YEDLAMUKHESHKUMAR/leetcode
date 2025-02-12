#define printv(a) {for(auto u:a) cout<<u<<" "; cout<<endl;}
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        // 4 7 7 9 9 9 
        vector<int> maxi(100, -1);
        vector<int> secondMaxi(100, -1);
        vector<int> sums;
        int n = nums.size(), maxIndex , prevElement;
        for(int i = 0; i<n;i++){
            int num = nums[i], sum = 0;
            while(num!= 0){
                sum += (num % 10);
                num /= 10;
            }
            sums.push_back(sum);
            if(maxi[sum] == -1) {
                maxi[sum] = i;
            }
            else{
                maxIndex = maxi[sum];
                prevElement = nums[maxIndex];
                if(nums[i] > prevElement){
                    maxi[sum] = i;
                }
            }
        }
        printv(sums);
        printv(maxi);

        for(int i = 0; i<sums.size();i++){
            int sum = sums[i];
            if(maxi[sum] == i) continue;
            if(secondMaxi[sum] == -1) secondMaxi[sum] = i;
            else{
                maxIndex = secondMaxi[sum];
                prevElement = nums[maxIndex];
                if(nums[i] > prevElement){
                    secondMaxi[sum] = i;
                }
            }

        }

        printv(secondMaxi);

        int maxAns = -1, num1, num2;
        for(int i = 0; i<100;i++){
            if(maxi[i] == -1 || secondMaxi[i] == -1) continue;
            num1 = nums[maxi[i]] , num2 = nums[secondMaxi[i]];
            maxAns = max(maxAns, num1 + num2);
        }
        return maxAns;

    }
};