class Solution {
public:
    bool halvesAreAlike(string s) {
        int first = 0 , second = 0;
        int n = s.size();
        int half = n/2;
        for(int i=0;i<n;i++){
            if( (s[i]=='a' ||s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u' ||s[i]=='A' ||s[i]=='E' ||s[i]=='I' ||s[i]=='O' ||s[i]=='U' )  ){
                
                if(i<half) first++;
                else second++;
            }
            
        }
        if(first == second) return true;
        return false;
    }
};