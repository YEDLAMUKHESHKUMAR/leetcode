#include<string.h>
class Solution {
public:
    unsigned long long atonum(string s){
     unsigned long long num=0;
        
        for( char x: s){
            num=num*10 +(x-'0');
        }
        // cout<<s<<" "<<num<<endl;
        return num;
        
    }
    
    bool helper( string &s, int start,vector<string> &t){
        // cout<<"called";
        if(start==s.size()){
            //check
           
        
//             for(auto x: t){
//                 cout<<x<<" ";
//             }
            
                if(t.size()<=1){
                return false;
                }
            vector<unsigned long long> n(t.size());
            for(int i=0;i<t.size();i++){
                n[i]=atonum(t[i]);
            }
            
            for(int i=1;i<t.size();i++){
                // cout<<"\ncallong ato num\n";
                
                 // cout<<"callong ato num end\n";
                if((n[i-1] <= n[i]) || ((n[i-1]-n[i]) != 1) ) {
                     // cout<<"here\n";
                     // cout<<"fasle in loop "<<endl;
                    return false;
                   
                }
            }
             // cout<<"true in loop "<<endl;
            return true;
            
        }else{
            for( int i=start;i<s.size();i++){
                string ts=s.substr(start,i-start+1);
                t.push_back(ts);
                if(helper(s,i+1,t)){
                    return true;
                }
                t.pop_back();
            }
        }
        return false;
    }
    bool splitString(string s) {
        vector<string> v;
        
        // atonum("123");
        return helper(s,0,v);
        return false;
    }
};