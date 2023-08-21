//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int Count(vector<vector<int> >& matrix) {
        // Code here
        int n=matrix.size();
        int m=matrix[0].size();
        // return n;
        // return m;
        int right,top,down,left;
        int ones=0;
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                int zero_count=0;
                if(matrix[i][j]==1){
                    left=j-1,right=j+1;
                    top=i-1,down=i+1;
                    if(top>=0 && matrix[top][j]==0){
                        zero_count++;
                    }
                    if(down<n && matrix[down][j]==0){
                        zero_count++;
                    }
                    
                    if(left>=0){
                        if(matrix[i][left]==0){
                            zero_count++;
                        }
                        if(top>=0 && matrix[top][left]==0){
                            zero_count++;
                        }
                        if(down<n && matrix[down][left]==0){
                            zero_count++;
                        }
                    }
                    if(right<m){
                        if(matrix[i][right]==0){
                            zero_count++;
                        }
                        if(top>=0 && matrix[top][right]==0){
                            zero_count++;
                        }
                        if(down<n && matrix[down][right]==0){
                            zero_count++;
                        }
                        
                    }
                    if(zero_count>0 && zero_count%2==0){
                        ones++;
                    }
                    
                }
                
                
            }
            
        }
        return ones;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends