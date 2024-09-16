class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        // convert to minutes...and then sort it
        int n = timePoints.size();
        vector<int> minutes(n);
        for(int i = 0 ;i<n;i++){
            int hours = stoi(timePoints[i].substr(0,2));
            int minute = stoi(timePoints[i].substr(3));
            int totMin = hours * 60 + minute;
            minutes[i] = totMin;
        }
        sort(minutes.begin(),minutes.end());
        int mini = INT_MAX;
        for(int i = 0 ;i<minutes.size()-1;i++){
            mini = min(mini,minutes[i + 1] - minutes[i]);
        }
        mini = min(mini , 1440 - minutes[n-1] + minutes[0]); // for circular time
        return mini;

    }
};