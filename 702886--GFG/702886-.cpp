class Solution {
    static bool cmp(string &a, string &b){
        if(a+b > b+a)return 1;
        return 0;
    }
  public:
    string findLargest(vector<int> &arr) {
        // code here
        vector<string> ans;
        for(auto i: arr){
            ans.push_back(to_string(i));
        }
        sort(ans.begin(), ans.end(), cmp);
        string str= "";
        for(auto i: ans){
            str+=i;
        }
        if(str[0]=='0' and str.back()=='0')return "0";
        return str;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna