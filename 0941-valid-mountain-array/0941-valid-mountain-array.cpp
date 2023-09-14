class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n=arr.size();
        if(n<3) return false;
        // first increasing then decreasing
        // if increasing or decreasing is done...it shouldn't be repeated 
        // two consequitive 
        bool increase=false;
        bool decrease=false;
        // int maxi=arr[0];
        int i=1;
        while(i<n && arr[i]>arr[i-1]){
            increase=true;
            i++;
        }
        if(increase==false) return false;
        while(i<n){
            if( !( arr[i]<arr[i-1] ) ){
                return false;
            }
            decrease=true;
            i++;
        }
        if(decrease==false) return false;
        return true;

    }
};