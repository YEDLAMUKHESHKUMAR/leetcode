// Last updated: 6/15/2025, 12:17:33 AM
class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        int i = 0;
        while(s[i]=='9' && i < s.size()-1) i += 1;
        string maxi = s;
        for(char& ch:maxi) if(ch==s[i]) ch = '9';
        string mini = s;
        for(char& ch:mini) if(ch == s[0]) ch = '0';

        return stoi(maxi)-stoi(mini);
    }
};