class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(vector<int>& a, int target, int start, vector<int>& temp) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = start; i < a.size(); i++) {
            if (a[i] > target)
                continue;

            temp.push_back(a[i]);

            backtrack(a, target - a[i], i, temp);

            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        backtrack(candidates, target, 0, temp);
        return ans;
    }
};