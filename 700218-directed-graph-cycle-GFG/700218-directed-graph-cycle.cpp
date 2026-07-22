class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        
        // by using topo sort 
        
        vector<int>indegree(V , 0) ;
        
        queue<int>Q ;
        
        vector<int>ans ;
        
        vector<vector<int>>adj(V) ;
        
        for(int i=0 ; i < edges.size() ; i++){
            int a = edges[i][0] ;
            int b = edges[i][1] ;
            
            adj[a].push_back(b) ;
            
        }
        
        for(int i=0 ; i < V ; i++){
            for(int x : adj[i]){
                indegree[x]++ ;
            }
        }
        
        for(int i=0 ; i < V ; i++){
            if(indegree[i] == 0){
                Q.push(i) ;
            }
        }
        
        while(!Q.empty()){
            int f = Q.front() ;
            Q.pop() ;
            
            ans.push_back(f) ;
            
            for(int x : adj[f]){
                indegree[x]-- ;
                
                if(indegree[x] == 0){
                    Q.push(x) ;
                }
            }
        }
        
        return ans.size() == V ? false : true  ;
        
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna