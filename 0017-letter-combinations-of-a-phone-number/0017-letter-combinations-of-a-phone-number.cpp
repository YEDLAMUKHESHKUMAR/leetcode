void solve(int ind,vector<string> &arr,string &s,vector<string> &ans){
    if(ind==arr.size()){
        ans.push_back(s);            // :) :) :) :) :)
        return;
    }
    for(int i=0;i<4;i++){
        if(i<arr[ind].size()){
            s.push_back(arr[ind][i]);
            solve(ind+1,arr,s,ans);
            s.pop_back();
        }
    }
}
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> pairs={"", "", "abc", "def", "ghi", "jkl","mno", "pqrs", "tuv", "wxyz"};
        vector<string> alphabets;
        for(auto digit:digits){
            alphabets.push_back(pairs[digit-'0']);
        }
        vector<string> ans;
        if(digits.empty()) return ans;
        string s;
        solve(0,alphabets,s,ans);
        return ans;








        // idea that i got is using recursion ..what i'll do is
        // if i have a phno combination like 234..then the letter combination will be like
        // abc,def,ghi...from this we have to generate all permutations ..for this letter 
        // combination the permutations you will get is 39 ..total 39 combinations you will get
        // 27+9+3 =39
        // so here i will make a recursion inside a for loop so that it will give all
        // permutations that we want 
        // for(int i=0;i<str.size();i++)
        //      retrieve the letter from str[index][i];
        //      recursion(index+1,......);
        // intially index=0,i=0..so the first letter 'a' will reterive..then index become 1.. 
        // then the second letter from second string will be retrieved ['d']...then index 
        // becomes 2 ..then the third letter from third string 'g' will be retrieved 
         //Note : here while executing last string with for loop the first letter and second 
        // letter will be remain as such ....then we will get like adg,adh,adi...then like 
        // aeg,aeh,aei....like this you can get all permutations 
        
        
        // vector<pair<string,string>> pairs={{"2","abc"},{"3","def"},{"4","ghi"},{"5","jkl"},{"6","mno"},{"7","pqrs"},{"8","tuv"},{"9","wxyz"}};

    }
    
};