class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int a=capacityA;
        int b=capacityB;
        if(plants.size()==1) return 0;
        int i=0,j=plants.size()-1;
        int refil=0;
        while(i<=j){
            if(i==j){
                if(a>=b){
                    if(a<plants[i]) {
                        refil++;
                    }
                    i++;

                }
                else{
                    if(b<plants[j]){
                        refil++;
                    }
                    j--;
                }
            }
            else{

            if(a<plants[i]){
                refil++;
                a=capacityA;
            }
            a=a-plants[i];
            i++;

            if(b<plants[j]){
                refil++;
                b=capacityB;
            }

            b=b-plants[j];
            j--;

            }
        }
        return refil;
    }
};