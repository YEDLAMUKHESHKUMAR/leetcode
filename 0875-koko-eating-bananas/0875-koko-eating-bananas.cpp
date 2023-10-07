class Solution {
public:
    int findMax(vector<int> &arr){
        int maxi=INT_MIN;
        int n=arr.size();
        for(int i=0;i<n;i++){
            maxi=max(maxi,arr[i]);
        }
        return maxi;
}
    long long canEat(int k , vector<int> &arr){
        long long ans = 0 ;
        for(int i=0;i<arr.size();i++){
            int hours= ceil(arr[i] / (double)k);
            ans+=hours;   
        }
        return ans;
    }


    int minEatingSpeed(vector<int>& piles, int h) {

        int maxi = findMax(piles);  // calling max function
        int low = 1 , high = maxi;
        int ans=-1;
        while(low <= high) {
            int mid = low + (high - low )/2;
            long long minHours = canEat(mid,piles); // checking if present mid is min K
            if(minHours <= h){
                ans=mid;
                high = mid - 1 ;
            }
            else{
                low = mid +1; 
            }
        }
        return ans;
    }
};