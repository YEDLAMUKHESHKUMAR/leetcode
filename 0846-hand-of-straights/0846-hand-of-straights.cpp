class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n  = hand.size();
        if(n % groupSize != 0 ) return false; 
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[hand[i]]++;
        }
        sort(hand.begin(),hand.end());
        for(int i=n-1;i>=0;i--){
            if(mp.find(hand[i])==mp.end()) continue;
            int num = hand[i]  ;
            int k = groupSize  ;
            while(k!=0){
                if(mp.find(num) == mp.end()) return false;
                mp[num]--;
                if(mp[num]==0) mp.erase(num);
                num--;
                k--;
            }
        }
        return true;

    }
};