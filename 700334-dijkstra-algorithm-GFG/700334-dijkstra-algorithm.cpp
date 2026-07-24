class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<int> dist(V,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<vector<pair<int,int>>> adj(V);
        
        for(auto x:edges){
            int u=x[0];
            int v=x[1];
            int w=x[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
            
        }
        
        dist[src]=0;
        pq.push({0,src});
        while(!pq.empty()){
            int node=pq.top().second;
            int curd=pq.top().first;
            pq.pop();
            if(curd>dist[node])continue;
            for(auto x:adj[node]){
                if(dist[node]+x.second<dist[x.first]){
                    pq.push({dist[node]+x.second,x.first});
                    dist[x.first]=dist[node]+x.second;
                }
            }
        }
        return dist;
    }
};



// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna