class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int metalGarbage = 0;
        int glassGarbage = 0;
        int paperGarbage = 0;
        int G=0,M=0,P=0;
        int keepTrack = 0;
        int n = garbage.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<garbage[i].size();j++){
                if(garbage[i][j] == 'G'){
                    glassGarbage++;  
                    G=keepTrack; 
                }
                else if(garbage[i][j] == 'M'){
                    metalGarbage++;
                    M=keepTrack;;
                }
                else{
                    paperGarbage++;  
                    P=keepTrack; 
                }
            }
            if(i!=n-1) keepTrack+=travel[i];  
            

        }
        int ans = metalGarbage + paperGarbage + glassGarbage + M + P + G ;
        return ans;
    }
};