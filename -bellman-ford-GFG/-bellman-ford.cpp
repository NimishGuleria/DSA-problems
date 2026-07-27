class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> dist(V,1e8);
        dist[src]=0;
        for(int i=0;i<V-1;i++){
            for(auto x:edges){
                int u=x[0];
                int v=x[1];
                int wt=x[2];
                if(dist[u]!=1e8 && dist[u]+wt<dist[v]){
                    dist[v]=dist[u]+wt;
                }
            }
        }
        //negativer cycle check 
        for(auto x:edges){
                int u=x[0];
                int v=x[1];
                int wt=x[2];
                if(dist[u]!=1e8 && dist[u]+wt<dist[v]){
                    return{-1};
        }
        }
        return dist;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna