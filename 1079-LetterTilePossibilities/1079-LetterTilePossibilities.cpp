class Solution {
public:
    int numTilePossibilities(string tiles) {
        set<string> s;
        int n = tiles.size();
        for(int i = 1; i < (1 << n) ; i++){
            string temp = "" ;
            int num = i;
            for(int pos = 0; pos < 32 ;pos++){
                if( (num >> pos) & 1 ){
                    temp += tiles[pos];
                }
            }
            sort(temp.begin(), temp.end());
            // cout<<temp<<endl;
            // if(temp.size() == 1) s.insert(temp);
            // else{
                do{
                    s.insert(temp);
                    cout<<temp<<endl;
                }while(next_permutation(temp.begin(), temp.end()));
            // }
        }
        return s.size();

    }
};