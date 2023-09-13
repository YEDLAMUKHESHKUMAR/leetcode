class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n=temp.size();
        stack<pair<int,int>> s;
        vector<int> ans;
        ans.push_back(0);
        s.push({temp[n-1],0});
        int i=n-2;
        while(i>=0){
            int days=1;
            while(!s.empty() && temp[i]>=s.top().first){
                days+=s.top().second;
                s.pop();
            }
            if(s.empty()){
            days=0;
            }
            ans.push_back(days);
            s.push({temp[i],days});
            i--;
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
};