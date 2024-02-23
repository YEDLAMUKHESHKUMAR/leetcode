class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        map<int,vector<pair<int,int>>> mp;
        for(int i=0;i<flights.size();i++){
            mp[flights[i][0]].push_back({flights[i][1],flights[i][2]}) ;// from.push({to,price})
        }
        vector<int> price (n,INT_MAX) ;
        queue<pair<int,int>> q; // {currPrice,currStop}
        q.push({0,src}) ; // initially at src 
        k++;  // for the case atmost 0 .. the while loop should run atleast one time..
        while(!q.empty() &&  k--){
            int size = q.size();
            for(int i=0;i<size;i++){
                auto stop = q.front();
                q.pop();
                int currStop = stop.second;
                for(int j = 0;j<mp[currStop].size();j++){
                    int priceToNextStop = mp[currStop][j].second;
                    int nextStop = mp[currStop][j].first;
                    if(priceToNextStop + stop.first < price[nextStop]){ 
                        int TotPriceForNextStop = priceToNextStop + stop.first;
                        q.push({TotPriceForNextStop , nextStop });
                        price[nextStop] = TotPriceForNextStop ; 
                    }
                }
            }
        }
        if(price[dst] == INT_MAX) return -1; // if it wasn't updated , means we can't reach there 
        return price[dst];
    }
};