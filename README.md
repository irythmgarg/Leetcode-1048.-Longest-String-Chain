# Leetcode-1048.-Longest-String-Chain
# 🔗 Longest String Chain - Dynamic Programming Masterpiece!

## 📘 Problem Statement

Given a list of strings, return the length of the **longest possible word chain**. A word chain is a sequence of words where each word is formed by adding a single character to the previous word.

🔎 A word `A` is a predecessor of `B` if you can insert exactly one character anywhere in `A` to make it equal to `B`. For example, "abc" ➡️ "abac" is valid.

### 🧪 Example

```cpp
Input: words = ["a", "b", "ba", "bca", "bda", "bdca"]
Output: 4
Explanation: One of the longest chains is "a" -> "ba" -> "bda" -> "bdca"
```

---

## 🧠 Approach 1: Top-Down Dynamic Programming (Memoization)

✨ **Idea**:

* Sort the words by length.
* Use a recursive function with memoization to try building chains.
* If `check(parent, child)` is true, explore the next step in the chain.

🛠️ **Utility Function**: `check(parent, child)` returns true if `parent` is a valid predecessor of `child`.

### ⏱️ Time Complexity:

* Sorting: `O(n log n)`
* DP recursion: `O(n^2 * L)` where `L` is max word length

### 💾 Space Complexity:

* `O(n^2)` for memoization table
* Recursion stack: `O(n)`

---

## 🧠 Approach 2: Bottom-Up DP (Tabulation - LIS style)

✨ **Idea**:

* Sort the words based on length.
* Use DP to store the longest chain ending at each word.
* For every word `i`, compare it with all previous `j < i`. If `check(words[j], words[i])` is true, update `dp[i] = max(dp[i], dp[j]+1)`.

### ⏱️ Time Complexity:

* Sorting: `O(n log n)`
* DP loop: `O(n^2 * L)`

### 💾 Space Complexity:

* `O(n)` for the DP array

---

## 🔍 Utility Function: `check(parent, child)`

```cpp
bool check(string &parent, string &child) {
    if (parent.length() + 1 != child.length()) return false;
    int i = 0, j = 0;
    while (i < child.length()) {
        if (j < parent.length() && parent[j] == child[i]) j++;
        i++;
    }
    return j == parent.length();
}
```

---

## 🎨 Visualization

```
      "a"
       |
      "ba"
     /   \
"bda"   "bca"
     \
    "bdca" ⬅️ Max chain length = 4
```

---

## 👨‍💻 Author Info

> ✍️ Crafted with 💙 by **Ridham Garg**
> 🎓 **Thapar Institute of Engineering and Technology**
> 📧 [Ridhamgarg000@gmail.com](mailto:Ridhamgarg000@gmail.com)

---

> 🚀 Whether you're climbing strings or climbing dreams, just keep adding one step at a time! 🪜💫
