class Solution {
  public:
    bool checkKthBit(int n, int k) {
        //  code here
        string binaryStr = bitset<32>(n).to_string();
        int size=binaryStr.length();
        if(binaryStr[size-k-1]=='0') return false;
        else if(binaryStr[size-k-1]=='1') return true;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna