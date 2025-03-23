// Last updated: 3/23/2025, 9:53:35 AM
class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        int cells = n * n;
        return min(maxWeight / w, cells);
    }
};