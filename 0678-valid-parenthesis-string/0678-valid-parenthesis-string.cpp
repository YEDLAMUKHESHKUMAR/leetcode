class Solution {
public:
    bool checkValidString(string s) {
        // int openCount = 0;
        // int closeCount = 0;
        // int astrikCount = 0;
        //  for(int i = 0; i < s.length(); i++){
        //     if(s[i] == '(') openCount++;
        //     if(s[i] == '*') astrikCount++;
        //     if(s[i] == ')'){
        //         if(openCount>0) 
        //             openCount--;
        //         else if(astrikCount>0) 
        //             astrikCount--;
        //         else 
        //             return false;
        //     }
        // }
        stack<int> asterisk;
        stack<int> validPar;
        
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(') validPar.push(i);
            if(s[i] == '*') asterisk.push(i);
            if(s[i] == ')'){
                if(!validPar.empty()) 
                    validPar.pop();
                else if(!asterisk.empty()) 
                    asterisk.pop();
                else 
                    return false;
            }
        }
        
        while(!validPar.empty() && !asterisk.empty()){
            if(validPar.top() > asterisk.top()) return false;
            
            validPar.pop(); asterisk.pop();
        }
        
        return validPar.empty();
    }
};