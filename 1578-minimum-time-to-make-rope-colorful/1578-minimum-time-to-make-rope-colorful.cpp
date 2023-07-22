void do_swap(vector<int>& neededTime,int i){
    int temp=neededTime[i];
    neededTime[i]=neededTime[i-1];
    neededTime[i-1]=temp;
}
int solve(string colors,vector<int>& neededTime){
    int min_time=neededTime[0];
    int n=colors.size();
    int ans=0;
    for(int i=1;i<n;i++){
        int current_color=colors[i];
        int previous_color=colors[i-1];
        if(current_color==previous_color){
            min_time= min(neededTime[i],neededTime[i-1]);
            ans+=min_time;
            if(min_time==neededTime[i]){
                do_swap(neededTime,i);
            }
        }
    
    }
    return ans;
}
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int total_neededTime= solve(colors,neededTime);
        return total_neededTime;
    }
};