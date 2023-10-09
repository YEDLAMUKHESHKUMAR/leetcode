class Solution {
public:
    int capacity(vector<int> &arr , int mid , int days){
        int sum = 0;
        int count =1;
        for(int i=0;i<arr.size();i++){
            if(sum + arr[i] > mid){
                sum=0;
                count++;
            }
            sum += arr[i];
        }
        return count;
    }
    int shipWithinDays(vector<int>& arr, int days) {
        int sum=0;
        int maxi = INT_MIN;
        for(int i=0;i<arr.size();i++){
            maxi = max(maxi,arr[i]);
            sum += arr[i];
        }
        int low = maxi , high = sum ;
        int ans = 0; 
        while(low <= high){
            int mid = (low + high) / 2 ;
            int estimatedDays = capacity(arr,mid,days);
            if(estimatedDays <= days){
                ans = mid;
                high = mid - 1 ;
            }
            else{
                low = mid + 1 ;
            }
        }
        return ans;
    }
};