class Solution {
  public:
    void DFS(int startNode,vector<vector<int>>&adjList,vector<int>&inDegree,vector<int>&visited,vector<int>&topo){
        visited[startNode] = 1;
        topo.push_back(startNode);
        
        for(int child : adjList[startNode]){
            inDegree[child]--;
            
            if(!visited[child] && inDegree[child] == 0){
                DFS(child,adjList,inDegree,visited,topo);
            }
        }
        
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int>topo;
        if(V == 0)return topo;
        
        vector<vector<int>>adjList(V);
        vector<int>inDegree(V);
        vector<int>visited(V,0);
        
        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            
            adjList[u].push_back(v);
            inDegree[v]++;
        }
        
        for(int i =0;i<V;i++){
            if(!visited[i] && inDegree[i] == 0){
                DFS(i,adjList,inDegree,visited,topo);
            }
        }
        
        return topo;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna