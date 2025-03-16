class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        // 1 2 3
        // 1 3 6
        // line sweep...
        int n = nums.size(), sum = 0;
        vector<int> linesweep(n + n + 2 , 0);
        for(int i = 0; i < n;i++){
            if(linesweep[i] != 0){
                sum += linesweep[i];
            }
            if(nums[i] < sum) return false;
            int leftOver = nums[i] - sum;
            if(leftOver > 0 && i + k > n) return false;
            linesweep[i] += leftOver;
            linesweep[i + k] -= leftOver;
            sum += leftOver;
            cout<<sum<<endl;
        }
        return true;
    }
};