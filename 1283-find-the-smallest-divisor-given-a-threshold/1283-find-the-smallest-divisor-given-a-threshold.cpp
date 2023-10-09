class Solution {
public:
    int isLesser(vector<int> &arr,int mid){
        int sum = 0;
        for(int i=0;i<arr.size();i++){
            int divisor = arr[i] / mid ;
            sum += divisor;
            if(arr[i] % mid !=0){
                sum++;
            }
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi= max(maxi,nums[i]);
        }
        int low = 1 , high = maxi ;
        int ans ;
        while(low <= high){
            int mid = (low + high)/2;
            int temp = isLesser(nums,mid);
            if(temp <= threshold){
                ans = mid ;
                high = mid - 1;
            }
            else{
                low = mid + 1 ;
            }
        }
        return ans;
    }
};