// Last updated: 3/25/2025, 9:39:59 PM
#define ll long long
class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<ll,ll>> width;
        vector<pair<ll,ll>> height;
        ll m = rectangles.size();
        for(auto i : rectangles){
            width.push_back({i[0], i[2]});
            height.push_back({i[1], i[3]});
        } 
        sort(width.begin(), width.end());
        sort(height.begin(), height.end());
        ll lines1 = 0 , lines2 =0, end = width[0].second;
        for(int i = 1 ; i < width.size() ; i++){
            if(width[i].first >= end){
                lines1++;
            }
            end = max(end, width[i].second);
            
        }
        if(lines1 >= 2) return true;
        end = height[0].second;
        for(int i = 1 ; i < height.size() ; i++){
            if(height[i].first >= end){
                lines2++;
            }
            end = max(end, height[i].second);
            
        }
        if(lines2 >= 2) return true;
        return false;
    }
};