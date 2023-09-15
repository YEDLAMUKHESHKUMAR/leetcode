class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n=s1.size();
        unordered_map<char,int> odd;
        unordered_map<char,int> even;
        for(int i=0;i<n;i++){
            if(i%2==0) even[s1[i]]++;
            else odd[s1[i]]++;
        }
        for(int i=0;i<n;i++){
            if(i%2==0){
                if(even[s2[i]]==0) return false;
                even[s2[i]]--;
            }
            else {
                if(odd[s2[i]]==0) return false;
                odd[s2[i]]--;
            }
        }
        return true;
        // for(int i=0;i<n;i++){
        //     bool isequal=false;
        //     int j=i;
        //     while(j<n){
        //         if(s1[j]==s2[i]){
        //             swap(s1[j],s1[i]);
        //             isequal=true;
        //             break;
        //         }
        //         j+=2;
        //     }
        //     if(isequal==false) return false;
        // }        
        // return true;
    }
};