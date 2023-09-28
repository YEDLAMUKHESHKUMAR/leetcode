class Solution {
public:
    void rotate(vector<vector<int>>& arr) {
        int i=0,j=0;
        int n=arr.size();
	    for(int i=0;i<n;i++){       // :) :) :) :) :)
	        for(j=i;j<n;j++){
	            swap(arr[i][j],arr[j][i]);
	        }
	    }
        for(int i=0;i<n;i++){
            for(int j=0;j<n/2;j++){
                swap(arr[i][j],arr[i][n-j-1]);
            }
        }
	}
    
};