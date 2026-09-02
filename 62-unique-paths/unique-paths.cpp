class Solution {
public:
    int uniquePaths(int m, int n) {
        long long ans = 1;
        
        int k = min(m - 1, n - 1);
        int totalSteps = m + n - 2;
        
        for (int i = 1; i <= k; ++i) {
            ans = ans * (totalSteps - i + 1) / i;
        }
        
        return ans;
    }
};