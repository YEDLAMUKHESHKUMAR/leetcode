class ProductOfNumbers {
public:
    int recentZero = -1;
    vector<int> arr;
    vector<int> prefix;
    ProductOfNumbers() {
        
    }
    // 1 2 3 0 4 5   6   4
    // 1 2 6 0 4 20 120  480
    void add(int num) {
        if(num == 0) {
            recentZero = arr.size();
            arr.push_back(0);
            prefix.push_back(0);
        }
        else{
            arr.push_back(num);
            int m = prefix.size();
            if(prefix.empty() || prefix[prefix.size() - 1] == 0) prefix.push_back(num);
            else prefix.push_back( prefix[m-1] * num );
        }
    }
    
    int getProduct(int k) {
        int m = prefix.size();
        if(m - k  <= recentZero) return 0;
        if(m - k - 1 < 0 || prefix[m - k - 1] == 0) return prefix[m-1];
        return prefix[m - 1 ] / prefix[m - k - 1]; 
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */