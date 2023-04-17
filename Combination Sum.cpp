class Solution {
public:
    void generateSubsets(vector<int>& candidates, vector<vector<int>>& ans, vector<int> curState, int i, int target) {
        if(target<0)
            return;
        if(target==0)
        {
            ans.push_back(curState);
            return;
        }
        if(i==candidates.size())
            return;
        curState.push_back(candidates[i]);
        generateSubsets(candidates, ans, curState, i, target-candidates[i]);
        curState.pop_back();
        generateSubsets(candidates, ans, curState, i+1, target);

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curState;
        generateSubsets(candidates, ans, curState, 0, target);
        return ans;
    }
};
