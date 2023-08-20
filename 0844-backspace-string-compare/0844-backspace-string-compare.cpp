class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int hash1=0,hash2=0;
        int i=s.size()-1,j=t.size()-1;
        // int i=n1-1,j=n2-1;
        while(true){
            hash1=0;
            while(i>=0 && (hash1>0 || s[i]== '#')){
                if(s[i]=='#'){
                    hash1++;
                }
                else{
                    hash1--;
                }
                i--;
            }
            hash2=0;
             while(j>=0 && (hash2>0 || t[j]== '#')){
                if(t[j]=='#'){
                    hash2++;
                }
                else{
                    hash2--;
                }
                j--;
            }
                if(i>=0 && j>=0 && s[i]==t[j]){
                    i--;
                    j--;
                }
                else{
                    break;
                }
            
        }
        if(i==-1 && j==-1) return true;
        return false;

        // while(i>=0 && j>=0){
        //     if(s[i]=='#'){
        //         hash1++;
        //         i--;
        //     }
        //     if(t[i]=='#'){
        //         hash2++;
        //         j--;
        //     }
        //     else {
        //         if(hash1>0){
        //             hash1--;
        //             i--;
        //         }
        //         if(hash2>0){
        //             hash2--;
        //             j--;
        //         }
        //         else if(s[i]==t[i]){
        //             i--;
        //             j--;
        //         }
        //         else{
        //             return false;
        //         }
        //     }
        // }
        // while(i>=0){
        //     if(s[i]=='#'){
        //         hash1++;
        //     }
        //     else if(hash1>0){
        //         s[i]='#';
        //         hash1--;
        //     }
        //     else{
        //         return false;
        //     }
        // }
        // while(j>=0){
        //     if(t[i]=='#'){
        //         hash2++;
        //     }
        //     else if(hash2>0){
        //         t[i]='#';
        //         hash2--;
        //     }
        //     else{
        //         return false;
        //     }
        // }
        
        // return true;
        // int hash=0;
        // for(int i=0;i<n1;i++){
        //     if(s[i]=='#'){
        //         hash++;
        //     }
        //     else if(hash>0){
        //         s[i]='#';
        //         hash--;
        //     }
        // }
        // hash=0;
        // for(int i=0;i<n2;i++){
            
        // }
    }
};