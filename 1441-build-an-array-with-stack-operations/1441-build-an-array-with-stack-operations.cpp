class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        string push = "Push";
        string pop = "Pop";
        int j = 0 ;
        for(int i=1;i<=n;i++){
            if(j==target.size()) return ans;
            if( i != target[j]){
                ans.push_back(push);
                ans.push_back(pop);
            }
            else{
                ans.push_back(push);
                j++;
            }
        }
        return ans;
    }
};