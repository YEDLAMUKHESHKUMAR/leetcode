class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
        if(n==1){
            return stones[0];
        }
        int ans;
        int top1,top2;
        priority_queue<int> p(stones.begin(), stones.end());
        while(p.size()>1){
            top1=p.top();
            p.pop();
            top2=p.top();
            p.pop();
            ans=top1-top2;
            if(ans!=0){
                p.push(ans);
            }
        }
        if(p.empty()) return 0;
        return p.top();
    }
};