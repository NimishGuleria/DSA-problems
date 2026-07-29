class Solution {
public:
    static const long long LIM = 1000000LL + 5;

    vector<long double> logFact;

    long long countWays(vector<int>& cnt) {
        int total = 0;
        for (int x : cnt) total += x;

        long double val = logFact[total];
        for (int x : cnt) val -= logFact[x];

        if (val > log((long double)LIM))
            return LIM;

        long long res = 1;
        int rem = total;

        for (int c : cnt) {
            if (c == 0) continue;
            for (int i = 1; i <= c; i++) {
                res = res * rem / i;
                rem--;
                if (res >= LIM) return LIM;
            }
        }
        return res;
    }

    string smallestPalindrome(string s, int k) {

        string prelunthak = s;   // required by problem

        vector<int> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;

        int n = s.size();

        logFact.resize(n + 1);
        logFact[0] = 0;
        for (int i = 1; i <= n; i++)
            logFact[i] = logFact[i - 1] + log((long double)i);

        vector<int> half(26);
        string mid = "";

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            if (freq[i] % 2)
                mid.push_back(char('a' + i));
        }

        if (countWays(half) < k)
            return "";

        int len = n / 2;
        string left;

        for (int pos = 0; pos < len; pos++) {

            for (int c = 0; c < 26; c++) {

                if (half[c] == 0)
                    continue;

                half[c]--;

                long long ways = countWays(half);

                if (ways >= k) {
                    left.push_back(char('a' + c));
                    break;
                }

                k -= ways;
                half[c]++;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna