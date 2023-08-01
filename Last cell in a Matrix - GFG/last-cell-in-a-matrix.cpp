//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> m, int r, int c){
        //code here
        bool m_right=true;
        bool m_left=false;
        bool m_up=false;
        bool m_down=false;
        int i=0,j=0;
        while(i>=0 && i<r && j>=0 && j<c){
            if(m_right==true){
                if(m[i][j]==0) j++;
                else{
                    m[i][j]=0;
                    m_right=false;
                    m_down=true;
                }
            }
            
            else if(m_down==true){
                if(m[i][j]==0) i++;
                else{
                    m[i][j]=0;
                    m_down=false;
                    m_left=true;
                }
            }
            
            else if(m_left==true){
                if(m[i][j]==0) j--;
                else{
                    m[i][j]=0;
                    m_left=false;
                    m_up=true;
                }
            }
            else{
                if(m[i][j]==0) i--;
                else{
                    m[i][j]=0;
                    m_up=false;
                    m_right=true;
                }
            }
        }
        if(m_right==true) return {i,j-1};
        else if(m_down==true) return {i-1,j};
        else if(m_left==true) return {i,j+1};
        else return {i+1,j};
    }
};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix, row, col);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends