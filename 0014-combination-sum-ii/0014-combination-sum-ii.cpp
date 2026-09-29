class Solution {
    vector<vector<int>> ans;
    vector<int> curr;

    void f(const vector<int> & arr, int start, int target){
        if(target == 0){
            ans.push_back(curr);
            return;
        }

        for(int i = start; i < arr.size(); i++){
            if(i > start && arr[i - 1] == arr[i]) continue;

            if(arr[i] > target) break;

            curr.push_back(arr[i]);
            f(arr, i + 1, target - arr[i]);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        f(candidates, 0, target);
        
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna