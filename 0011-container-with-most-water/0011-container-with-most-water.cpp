class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_number;
        int ans=0;
        int i=0,j=height.size()-1;
        while(i<j){
            int min_pole=min(height[i],height[j]);
            ans=max(ans,min_pole*(j-i));
            if(height[i]<height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return ans;
    }
};