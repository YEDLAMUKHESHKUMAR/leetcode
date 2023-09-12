class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        stack<int> s;
        vector<int> ans;
        int n=nums.size();
        for(int i=n-1;i>=0;i--){
            s.push(nums[i]);
        }
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && nums[i]>=s.top()){
                s.pop();
            }
            if(s.empty()){
                ans.push_back(-1);
            }
            else{
                ans.push_back(s.top());
            }
            s.push(nums[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        // int n=nums.size();
        // vector<int> ans(n) ;
        // int lastmax=nums[n-1];
        // int frontmax=nums[0],i=n-1,j=1;
        // while(i>=0 && j<n){
        //     if(nums[i]<lastmax){
        //         ans[i]=lastmax;
        //     }
        //     else if(nums[i]<frontmax){
        //         ans[i]=frontmax;
        //     }
        //     else{
        //         if(!(nums[i]<lastmax)){
        //             lastmax=nums[i];
        //         }
        //         if(!(nums[i]<frontmax)){
        //             if(frontmax<nums[j]){
        //                 frontmax=nums[j];
        //                 j++;
        //             }
        //         }
        //     }
        //     i--;

        // }
        // return ans;
    }
};