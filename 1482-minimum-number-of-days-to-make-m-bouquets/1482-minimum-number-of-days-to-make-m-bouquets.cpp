class Solution {
public:
    bool solve(vector<int> &arr,int day,int m,int k){
        int longestAdjacentFlowers=0;
        for(int i=0;i<arr.size();i++){
            if( day >= arr[i]){
                longestAdjacentFlowers++;
                if(longestAdjacentFlowers == k) {
                    m--;
                    longestAdjacentFlowers = 0 ;
                }
            }
            else{
                longestAdjacentFlowers=0;
            }
            if(m==0){
                return true;
            }
        }
        if(m==0) return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        //You can always use binary search to find a MINIMUM or a MAXIMUM, this problem has the property that it wants you to find the minimum possible, and you have a defined maximum and minimum, we know number of days cannot be more than max and cannot be less than min, this exactly leads to binary search. 
        
        int mini=INT_MAX;
        int maxi=INT_MIN;
        int n=bloomDay.size();
        long long val = (long long)m  * (long long)k;

        if(val > n) return -1;
        for(int i=0;i<n;i++){
            mini = min(mini,bloomDay[i]);
            maxi=  max(maxi,bloomDay[i]);
        }
        int low = mini , high = maxi ;
        int ans = -1;
        while(low<=high){
            int mid = (low+high)/2;
            if(solve(bloomDay,mid,m,k)==true){
                ans=mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};