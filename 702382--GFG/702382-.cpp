class Solution {
public:
void sort012(vector<int>& arr) {
/* APPROACH - 1
sort(arr.begin(), arr.end()); */
 
int n = arr.size();
int zeroes = 0;
int ones = 0;
for (int i = 0; i<n; i++) {if (arr[i] == 0) {zeroes++; }
else if (arr[i] == 1) {ones++; }
}
for (int i = 0; i<zeroes; i++) {arr[i] = 0; }
for (int i = zeroes; i<zeroes + ones; i++) {arr[i] = 1; }
for (int i = zeroes + ones; i<n; i++) {arr[i] = 2; }
 
}
};
 

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna