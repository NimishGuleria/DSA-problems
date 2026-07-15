class Solution {
public:
    static vector<int> findDegrees(vector<vector<int>>& matrix) {
        const int n=matrix.size();
        vector<int> deg(n, 0);
        for(int i=0; i<n; i++) 
            for(int j=0; j<i; j++){
                bool is1=matrix[i][j];
                deg[i]+=is1;
                deg[j]+=is1;
            }
        return deg;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna