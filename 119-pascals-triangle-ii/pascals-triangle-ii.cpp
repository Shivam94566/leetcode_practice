class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 1);
        long long current = 1;
        
        for (int k = 1; k <= rowIndex; ++k) {
            current = current * (rowIndex - k +1 ) / k;
            row[k] = current;
        }
        
        return row;
    }
};