class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
        int row=m.size();
        int col=m[0].size();
        bool check=false;
        bool check2=false;
        for(int i=0;i<row;i++){
            if(m[i][0]==0) check=true;
            for(int j=0;j<col;j++){              // :) :) :) 
                if(i==0 && m[i][j]==0){
                    check2=true;
                }
                if(m[i][j]==0){
                    m[i][0]=0;
                    m[0][j]=0;
                }
            }
        }
        for(int j=1;j<col;j++){
            if(m[0][j]==0){
                for(int i=1;i<row;i++){
                    m[i][j]=0;
                }
            }
        }
        for(int i=1;i<row;i++){
            if(m[i][0]==0){
                
                for(int j=0;j<col;j++){
                    m[i][j]=0;
                }
            }
        }
        if(check==true){
            for(int i=0;i<row;i++){
                m[i][0]=0;
            }
        }
        if(check2==true){
            for(int j=0;j<col;j++){
                m[0][j]=0;
            }
        }
        
    }
};