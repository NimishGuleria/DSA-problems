class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        m, n = len(s), len(wordDict)

        def dfs(i, memo: dict):
            if i == m:
                return [""]

            if i not in memo:
                memo[i] = []
                for word in wordDict:
                    length = len(word)
                    if s[i:i+length] == word:
                        if dfs(i+length, memo):
                            for res in dfs(i+length, memo):
                                if res == "":
                                    memo[i].append(word)
                                else:
                                    memo[i].append(word + " " + res)
            return memo[i]
        
        return dfs(0, {})

# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna