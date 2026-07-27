class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        const int INF = 1e9;

        vector<vector<int>> dist(n, vector<int>(n, INF));

        // Distance from a node to itself
        for (int i = 0; i < n; i++)
            dist[i][i] = 0;

        // Fill edge weights
        for (auto &e : edges) {
            int u = e[0], v = e[1], wt = e[2];
            dist[u][v] = wt;
            dist[v][u] = wt;
        }

        // Floyd-Warshall
        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][via] != INF && dist[via][j] != INF)
                        dist[i][j] = min(dist[i][j],
                                         dist[i][via] + dist[via][j]);
                }
            }
        }

        int city = -1;
        int minReachable = INT_MAX;

        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (dist[i][j] <= distanceThreshold)
                    cnt++;
            }

            // If tie, choose the city with larger index
            if (cnt <= minReachable) {
                minReachable = cnt;
                city = i;
            }
        }

        return city;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna