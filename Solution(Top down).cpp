// 💡 C++ Solution: Longest String Chain using Top-Down DP (Memoization)
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

        // If we matched all characters of parent, return true
        return j == parent.length();
    }

    // Memoization table to store subproblem results
    int dp[1001][1001];

    // 🔁 Recursive DP function to compute longest chain
    int func(vector<string>& words, int index, int prevelement) {
        // Base case: if all words are processed
        if (index >= words.size()) return 0;

        // Return cached result if already computed
        if (prevelement != -1 && dp[index][prevelement] != -1)
            return dp[index][prevelement];

        int take = 0;

        // Option 1: take current word if it's a valid successor
        if (prevelement == -1 || check(words[prevelement], words[index])) {
            take = 1 + func(words, index + 1, index);
        }

        // Option 2: skip current word
        int nottake = func(words, index + 1, prevelement);

        // Memoize and return the result
        if (prevelement != -1)
            return dp[index][prevelement] = max(take, nottake);

        return max(take, nottake);
    }

    // 🔃 Main function to initialize and start the process
    int longestStrChain(vector<string>& words) {
        // Initialize DP table with -1
        memset(dp, -1, sizeof(dp));

        // Sort words by length so shorter words come first
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.length() < b.length();
        });

        // Start recursive DP from index 0, with no previous element
        return func(words, 0, -1);
    }
};
