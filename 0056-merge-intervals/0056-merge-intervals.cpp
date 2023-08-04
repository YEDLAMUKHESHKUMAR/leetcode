class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int n=arr.size();
        if(n==1) return arr;
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        int maxi=arr[0][1],mini=arr[0][0];
        for(int i=1;i<n;i++){
            if(arr[i][0]>maxi){
                ans.push_back({mini,maxi});
                mini=arr[i][0];
                maxi=arr[i][1];
            }
            else{
                if(arr[i][1]>maxi) maxi=arr[i][1];
            }

        }
        ans.push_back({mini,maxi});
        return ans;
    }
};