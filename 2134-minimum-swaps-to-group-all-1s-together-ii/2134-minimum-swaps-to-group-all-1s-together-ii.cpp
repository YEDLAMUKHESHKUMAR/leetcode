class Solution{
public:
    int minSwaps(vector<int> &nums){
        int totalOnes = 0, n = nums.size();   // don't know why my approach failed ... gonna figure it out soon.....
        for (auto it : nums)
            if (it == 1) totalOnes++;
		
        int maxOnesInWindow = 0, onesInCurrWindow = 0, i = 0;
        for (i = 0; i < totalOnes; i++)
            if (nums[i] == 1) maxOnesInWindow++;
        
		onesInCurrWindow = maxOnesInWindow;		
        for (int i = totalOnes; i < n + totalOnes; i++){
            onesInCurrWindow += (nums[i % n] - nums[i - totalOnes]);
            maxOnesInWindow = max(onesInCurrWindow, maxOnesInWindow);
        }
        return totalOnes - maxOnesInWindow;
    }
};