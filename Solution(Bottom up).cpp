// 💡 C++ Solution: Longest String Chain using Bottom-Up DP (Tabulation)
// 📌 Author: Ridham Garg (Thapar Institute of Engineering and Technology)
// 📧 Email: Ridhamgarg000@gmail.com

class Solution {
public:

    // ✅ Utility function to check if 'child' can follow 'parent'
    // 'child' must have exactly one more character than 'parent'
    // and 'parent' must be a subsequence of 'child'
    bool check(string &parent, string &child) {
        if (parent.length() + 1 != child.length()) return false;

        int i = 0, j = 0;

        // Try to match all characters of parent in child (in order)
        while (i < child.length()) {
            if (j < parent.length() && parent[j] == child[i]) {
                j++;
            }
            i++;
        }

        // Return true only if all characters of parent matched
        return j == parent.length();
    }

    // 🔃 Main function using bottom-up DP to compute the longest chain
    int longestStrChain(vector<string>& words) {
        int n = words.size();

        // Step 1: Sort words by their lengths (shorter words first)
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.length() < b.length();
        });

        // Step 2: Initialize DP array, each word is at least a chain of length 1
        vector<int> dp(n, 1);
        int ans = 1;  // Stores the maximum chain length

        // Step 3: For each word, check all previous shorter words
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                // If words[j] can be a predecessor of words[i]
                if (check(words[j], words[i])) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    ans = max(ans, dp[i]);
                }
            }
        }

        // Step 4: Return the length of the longest chain
        return ans;
    }
};
