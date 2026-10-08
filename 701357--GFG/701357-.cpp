class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        int n = arr.size();
        //min heap 
        priority_queue<int , vector<int> , greater<int>> p ;
        
        for(int i=0;i<n;i++)
        p.push(arr[i]);
        
        int cost= 0;
        
        while(p.size()>1)
        {
            int rope = p.top();
            p.pop();
            rope+=p.top();
            p.pop();
            cost+=rope;
            p.push(rope);
        }
        
        return cost;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna