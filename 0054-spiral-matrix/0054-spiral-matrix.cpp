class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {
        int row=m.size();
        int col=m[0].size();
        int up=0,left=0;
        int down=row-1,right=col-1;
        int go=1;
        vector<int> ans;
        while(up<=down && left<=right){
            if(go==1){
                for(int i=left;i<=right;i++){
                    ans.push_back(m[up][i]);
                }
                go=2;
                up++;
            }
            else if(go==2){
                for(int i=up;i<=down;i++){
                    ans.push_back(m[i][right]);
                }
                go=3;
                right--;
            }
            else if(go==3){
                for(int i=right;i>=left;i--){
                    ans.push_back(m[down][i]);
                }
                down--;
                go=4;
            }
            else{
                for(int i=down;i>=up;i--){
                    ans.push_back(m[i][left]);
                }
                go=1;
                left++;
            }
        }
        return ans;
    }
};