class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // brute force : two for loops to count every number occurences ... TC : O(N^2)      SC: O(1)
        // ok : sort it....and count it by checking adjacent elements  .....TC : O(Nlog(N))  SC: O(1) 
        // better : use hash map to store the frequencies ..................TC : O(N)        SC: O(N)
        // OPTIMAL : ??  but major observation is ... you can get atmost two answers...and you may need
        // to traverse the array two times..but how?? -_- 

        int ans1=INT_MIN,ans2=INT_MIN;
        int count1=0,count2=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(ans1==nums[i]){
                count1++;
            }
            else if(ans2==nums[i]){
                count2++;
            }
            else if(count1==0){
                ans1=nums[i];
                count1=1;
            }
            else if(count2==0){
                ans2=nums[i];
                count2=1;
            }
            else{
                count1--;
                count2--;
            }
        }
        vector<int> res;
        int n_by_three=n/3;
        count1=0, count2=0;

        // if(n_by_three==0) return nums;
        for(auto i:nums){
            if(i==ans1){
                count1++;
            }
            if(i==ans2){
                count2++;
            }
        }
            if(count1> n_by_three){
                res.push_back(ans1);
                
            }
            if(count2> n_by_three){
                res.push_back(ans2);
                
            }
        
        return res;
    }
};