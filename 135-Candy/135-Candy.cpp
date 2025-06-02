// Last updated: 6/2/2025, 9:26:18 PM
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> arr(n, 0);
        vector<int> arr2(n, 0);
        arr[0] = 1;
        for(int i = 1 ; i < n ;i++){
            int put = 1;
            if(ratings[i] > ratings[i - 1]){
                put = arr[i - 1] + 1;
            }
            // else if(ratings[i] < ratings[i-1]){
            //     put = arr[i - 1] - 1;
            // }
            if(put < 1) put = 1;
            arr[i] = put;
        }
        int candies = 0;
        arr2[n-1] = 1;

        for(int i = n - 2; i>= 0; i--){
            int put = 1;
            int next = arr2[i + 1];
            
            if(ratings[i] > ratings[i + 1]){
                put = next + 1;
            }
            if(put < 1) put = 1;
            // candies += max(put, arr[i]);
            arr2[i] = put;
        }
        for(int i = 0; i < n ;i++){
            // cout<<arr[i]<<" ";
            candies += max(arr[i], arr2[i]);
        }
        

        return candies;
    }
};