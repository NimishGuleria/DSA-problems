class Solution {
  public:
    void dfs(vector<vector<int>>& adj,  vector<bool> &visit, vector<int> &result, int u){
        if(visit[u]) return;
        visit[u]=true;
        result.push_back(u);
        for(int &v: adj[u]){
            if(!visit[v]){
                dfs(adj,visit,result,v);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n=adj.size();
        vector<int> result;
        vector<bool> visit(n,false);
        dfs(adj,visit,result,0);
        return result;
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna