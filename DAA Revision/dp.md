**Phase 2: Dynamic Programming (DP) - "The Smart Note-Taker"**

If Greedy is the "Impatient Optimist," DP is the **"Careful Planner."**

* **The Concept:** DP is just **Recursion + Memory**.
* **The Trap:** Most people try to memorize complex tables. **Don't.**
* **The Secret:** Every DP problem is actually a recursion problem where the sub-problems **repeat**. Instead of re-calculating them, we store the answer (memoization).

---

### **Pattern 1: The "1D Linear" Pattern (Climbing Stairs)**

**Scenario (LeetCode 70):**
You are climbing a staircase. It takes  steps to reach the top. Each time you can either climb **1 step** or **2 steps**. In how many distinct ways can you reach the top?

**The Intuition (Visualizing the Move):**
Imagine you are standing on Step 5. How did you get there?

1. You could have come from **Step 4** (took 1 step).
2. You could have come from **Step 3** (took 2 steps).

So, `Ways(5) = Ways(4) + Ways(3)`.
This looks exactly like Fibonacci!

**The Thought Process:**

1. **Base Cases:**
* Step 0: 1 way (Don't move).
* Step 1: 1 way (Take 1 step).


2. **Recurrence Relation:** `dp[i] = dp[i-1] + dp[i-2]`

**The Code (From Recursion to Optimization):**

**Version 1: Recursion (Slow - )**

```cpp
int climbStairs(int n) {
    if (n <= 1) return 1;
    return climbStairs(n-1) + climbStairs(n-2); // Re-calculates same steps repeatedly!
}

```

**Version 2: Memoization (Top-Down - )**

```cpp
int memo[100]; // Initialize with -1
int solve(int n) {
    if (n <= 1) return 1;
    if (memo[n] != -1) return memo[n]; // "Recall" the note
    return memo[n] = solve(n-1) + solve(n-2); // "Write" the note
}

```

**Version 3: Tabulation (Bottom-Up - )**
This is the true "DP" way. We build the answer from the bottom up.

```cpp
int climbStairs(int n) {
    if (n <= 1) return 1;
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

```

**Version 4: Space Optimization (Interview Pro -  Space)**
Notice you only need the *last two* numbers (`i-1` and `i-2`) to calculate the current one. You don't need the whole array.

```cpp
int climbStairs(int n) {
    int prev2 = 1, prev = 1;
    for (int i = 2; i <= n; i++) {
        int current = prev + prev2;
        prev2 = prev;
        prev = current;
    }
    return prev;
}

```

---

### **Pattern 2: The "Decision Making" Pattern (House Robber)**

**Scenario (LeetCode 198):**
You are a robber. Each house has money. **Constraint:** You cannot rob two adjacent houses (the alarm will trigger).

* Input: `[1, 2, 3, 1]`
* Output: 4 (Rob house 1 (1) + Rob house 3 (3) = 4).

**The Intuition:**
For every house `i`, you have exactly **two choices**:

1. **Rob it:** You get `money[i]`. But you *cannot* rob house `i-1`. You *must* come from `i-2`. -> `money[i] + dp[i-2]`.
2. **Skip it:** You don't get money from this house. But you keep whatever maximum you had at `i-1`. -> `dp[i-1]`.

**The Formula:**
`dp[i] = max( nums[i] + dp[i-2],  dp[i-1] )`

---

### **Pattern 3: The "2D Grid" Pattern (0/1 Knapsack)**

**Scenario:**
This is the "Parent" of 80% of Hard DP problems.
You have items with `weight` and `value`. You have a bag capacity `W`. You either **pick** an item or **leave** it.

**The State:**
We need *two* variables to track our state:

1. `index` (Which item are we considering?)
2. `current_weight` (How much capacity is left?)

`dp[index][weight]` = Max value using items up to `index` with remaining capacity `weight`.

**The Logic:**
For item `i`, weight `wt[i]`, value `val[i]`:

1. **Don't Pick:** `dp[i-1][w]` (Value stays same as previous item).
2. **Pick:** `val[i] + dp[i-1][w - wt[i]]` (Add value, subtract weight).
* *Constraint:* Can only pick if `wt[i] <= w`.



**The Formula:**
`dp[i][w] = max( Not_Pick, Pick )`

---

### **The "Coach's Challenge"**

To cement this, solve **House Robber** mentally right now.

* **Input:** `[2, 7, 9, 3, 1]`
* **Step 1:** House 0 (Value 2). Max = 2.
* **Step 2:** House 1 (Value 7). Max = 7 (7 > 2).
* **Step 3:** House 2 (Value 9).
* Choice A (Rob): `9 + 2` (from step 1) = 11.
* Choice B (Skip): `7` (from step 2).
* Max = 11.


* **Step 4:** House 3 (Value 3).
* Choice A (Rob): `3 + 7` (from step 2) = 10.
* Choice B (Skip): `11` (from step 3).
* Max = 11.


* **Step 5:** House 4 (Value 1).
* Choice A (Rob): `1 + 11` (from step 3) = 12.
* Choice B (Skip): `11` (from step 4).
* Max = 12.



**Answer:** 12.

**Question for you:**
Does this logic change if the houses are arranged in a **Circle** (First and Last are neighbors)? How would you handle that constraint?
*(This is LeetCode 213 - House Robber II).*


Based on your **DAA Main Topics** roadmap, here are the high-yield conceptual points and exam strategies to ensure you don't just "solve" problems, but "crush" the exam.

### **1. The "Cheat Codes" for Identifying the Algorithm**

In an exam, the biggest hurdle is knowing *which* approach to use. Here is your mental filter:

| Feature | **Greedy** | **Divide & Conquer** | **Dynamic Programming** |
| --- | --- | --- | --- |
| **Choice** | Makes the "best" local move immediately. | Breaks problem into *independent* chunks. | Makes a decision, then recurses, then *compares* results. |
| **Backtracking?** | **No.** Once a choice is made, it's final. | **No.** Solves sub-problems separately. | **Yes.** Implicitly explores all paths (smart brute-force). |
| **Key Indicator** | "Maximize/Minimize" + Sorting works. | "Split array/list" + Sub-problems don't overlap. | "Maximize/Minimize" + "Count ways" + Overlapping sub-problems. |
| **Example** | Activity Selection, Huffman Coding. | Merge Sort, Binary Search. | 0/1 Knapsack, LCS, Matrix Chain Multiplication. |

---

### **2. Conceptual Deep Dives (Exam Favorites)**

#### **A. Divide & Conquer: The Master Theorem**

Teachers love asking for the Time Complexity of recursive algorithms. You don't need to derive it every time; memorize the **Master Theorem** pattern.

* **Format:** 
* : Number of sub-problems (e.g., 2 in Merge Sort).
* : Factor by which input size shrinks (e.g., 2 in Merge Sort).
* : Time to split/merge (e.g.,  in Merge Sort).


* **Quick Checks:**
* If work at root > leaves  Root dominates ().
* If work at leaves > root  Leaves dominate ().
* If work is equal  Height times work ().



#### **B. Dynamic Programming: Tabulation vs. Memoization**

You mentioned "Tabulation, Memoization" in your notes. Know the difference because examiners often ask "Optimize space."

* **Memoization (Top-Down):**
* **Logic:** Write the recursive code  Add a map/array check at the top.
* **Pros:** Easy to write, solves only needed states.
* **Cons:** Stack overflow risk for deep recursion.


* **Tabulation (Bottom-Up):**
* **Logic:** Iterative loop filling a table (dp[0] to dp[n]).
* **Pros:** No recursion overhead, allows **Space Optimization** (e.g., reducing  array to 2 variables).



#### **C. Greedy: The "Proof by Contradiction"**

If an exam asks "Prove your Greedy algorithm works," use this standard template:

1. Assume there is an **Optimal Solution** that is different from your **Greedy Solution**.
2. Show that you can swap one element in the Optimal set with one from your Greedy set *without* hurting the score.
3. Conclude that the Greedy solution is therefore just as good as the Optimal one.

---

### **3. Exam Performance Strategy: "The 4-Step Answer"**

When you see a 10-mark question, do NOT just write code. Engineers lose marks for bad presentation. Structure your answer like this:

**Step 1: Define the Sub-structure**

* "Let  be the maximum value we can get ending at index ..."
* "We define the greedy choice property as selecting the interval with the earliest finish time."

**Step 2: The Recurrence Relation (Crucial)**

* Write the math before the code.
* *Example:* 

**Step 3: Pseudocode or Clean Code**

* Don't worry about syntax errors (missing semicolons are fine).
* Focus on logic flow. Use comments: `// Base Case`, `// Transition`.

**Step 4: Complexity Analysis**

* Always end with:
* **Time Complexity:**  (due to sorting).
* **Space Complexity:**  (for the DP array).



---

### **Coach's Final Drill**

**Scenario:** You are in the exam. You see the **"Longest Common Subsequence" (LCS)** problem.

* *Question:* "Find the length of the longest subsequence present in both strings."

**Mental Check:**

1. **Greedy?** No. Matching 'A' now might ruin a better match later.
2. **Divide & Conquer?** No. `LCS("ABC", "AC")` depends on `LCS("AB", "A")`. Overlapping sub-problems.
3. **DP?** Yes.
* *State:* `dp[i][j]` = LCS of `string1[0...i]` and `string2[0...j]`.
* *Relation:*
* If `s1[i] == s2[j]`: 
* Else: 





Write that relation down, and you have already secured 50% of the marks.

**Ready for the next topic or a specific practice problem?**