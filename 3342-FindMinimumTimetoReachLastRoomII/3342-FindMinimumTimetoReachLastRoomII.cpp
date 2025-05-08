// Last updated: 5/8/2025, 11:11:06 AM
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();

        vector<vector<int>> mini(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, pair<int, pair<int, bool>>>, vector<pair<int, pair<int, pair<int, bool>>>>, greater<>> q;
        q.push({0, {0, {0, true}}});

        mini[0][0] = 0;

        vector<int> row = {-1, 0, 1, 0};
        vector<int> col = {0, 1, 0, -1};

        while (!q.empty()) {
            int t = q.top().first;
            int r = q.top().second.first;
            int c = q.top().second.second.first;
            bool plusOne = q.top().second.second.second;
            q.pop();
            if (r == n - 1 && c == m - 1) {
                return t;
            }
            int plus = plusOne == true ? 1 : 2;
            bool newP = true;
            if(plusOne == true){
                newP = false;
            }

            for (int i = 0; i < 4; i++) {
                int nrow = r + row[i];
                int ncol = c + col[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    int newT = max(t, arr[nrow][ncol]) ;
                    if (newT + plus < mini[nrow][ncol]) {
                        mini[nrow][ncol] = newT + plus ;
                        q.push({newT + plus, {nrow, {ncol, newP}}});
                    }
                }
            }
        }

        return mini[n - 1][m - 1];
    }
};