**Phase 1: The Greedy Philosophy ("The Impatient Optimist")**

Greedy is the algorithm of **immediate gratification**.
At every single step, you make the choice that looks **best right now**, without worrying about the future consequences.

* **The Gamble:** "If I make the best local move at every step, I will end up with the best global result."
* **The Catch:** It doesn't always work. (e.g., Shortest Path with negative edges).
* **The Key:** 90% of Greedy problems in interviews involve **Sorting** first. If the data isn't sorted, "greedy" choices are usually random and wrong.

---

### **Pattern 1: The Interval Problem (Activity Selection)**

**Scenario:**
You are in a meeting room. There are  meetings. Each has a `start_time` and `end_time`.

* **Goal:** Attend the **maximum number** of meetings possible.
* **Constraint:** You cannot attend two overlapping meetings.

**The Intuition:**
Imagine you have meetings: `[1, 2]`, `[3, 4]`, `[0, 6]`, `[5, 7]`, `[8, 9]`, `[5, 9]`.
Which one do you pick first?

* *Greedy Choice 1:* Pick the shortest meeting? (Maybe, but a short meeting in the middle might block two long ones).
* *Greedy Choice 2:* Pick the one that starts earliest? (No. A meeting `[0, 100]` starts early but blocks everyone else).
* *The Correct Greedy Choice:* **Pick the meeting that ENDS the soonest.**
* **Why?** The sooner a meeting finishes, the sooner the room is free for the next one. This maximizes the remaining time.



**The Algorithm:**

1. **Sort** all meetings by their **End Time**.
2. Select the first meeting (it ends earliest).
3. Keep a variable `last_end_time`.
4. Iterate through the rest:
* If `current_meeting.start > last_end_time`, you can attend it! Update `last_end_time`.
* Else, ignore it (it overlaps).



**The Code (C++):**

```cpp
struct Meeting {
    int start;
    int end;
    int pos; // To track original index if needed
};

// Comparator to sort by End Time
bool comparator(Meeting m1, Meeting m2) {
    if (m1.end < m2.end) return true;
    else if (m1.end > m2.end) return false;
    else return m1.pos < m2.pos; // Tie-breaker
}

class Solution {
public:
    int maxMeetings(int start[], int end[], int n) {
        vector<Meeting> meet(n);
        for (int i = 0; i < n; i++) {
            meet[i].start = start[i];
            meet[i].end = end[i];
            meet[i].pos = i + 1;
        }

        // STEP 1: SORT BY END TIME
        sort(meet.begin(), meet.end(), comparator);

        // STEP 2: GREEDY SELECTION
        int count = 1; // Always pick the first one
        int limit = meet[0].end;

        for (int i = 1; i < n; i++) {
            // If the next meeting starts AFTER the current one finishes
            if (meet[i].start > limit) {
                count++;
                limit = meet[i].end; // Update the finish time
            }
        }
        return count;
    }
};

```

---

### **Pattern 2: The Fractional Knapsack (The "Ratio" Pattern)**

**Scenario:**
You are a thief with a bag that can hold `W` kg. You see items with `value` and `weight`.

* **Goal:** Maximize total value in the bag.
* **Twist:** You can break items (take 50% of an item).

**The Intuition:**

* Item A: 10kg, Value 60 (Ratio: 6/kg)
* Item B: 20kg, Value 100 (Ratio: 5/kg)
* *Greedy Choice:* Don't pick the highest value. Don't pick the lightest weight. **Pick the highest Value-to-Weight Ratio.** It is "density". You want the most valuable "bang for your buck".

**The Code Logic:**

1. Calculate `ratio = value / weight` for every item.
2. **Sort** items by `ratio` (Descending).
3. Iterate:
* If the bag can hold the whole item, take it all. Subtract weight from capacity.
* If the bag cannot hold the whole item, take **fractional** part (remaining capacity / item weight) * item value.
* Break loop (bag is full).



---

### **The "Trap": When Greedy Fails**

**Coin Change Problem:**

* Coins: `[1, 3, 4]`
* Target: `6`

**Greedy approach:**

1. Pick largest coin : **4**. (Remaining: 2)
2. Pick largest coin : **1**. (Remaining: 1)
3. Pick largest coin : **1**. (Remaining: 0)

* **Result:** `4 + 1 + 1` = **3 coins**.

**Optimal approach:**

* `3 + 3` = **2 coins**.

**Lesson:** Greedy failed here because picking the "best now" (4) blocked the optimal future (3+3). This problem requires **Dynamic Programming**.

---

### **Summary Checklist for Greedy**

1. **Sorting is King:** If you aren't sorting, you probably aren't doing Greedy correctly.
2. **Visual Proof:** Draw the intervals or ratios. Does picking the "best" one leave the "most" resources for later?
3. **Complexity:** Usually  due to sorting.

**Next Step:**
I want you to solve the **"Lemonade Change"** problem (LeetCode 860) mentally right now.

* **Scenario:** You sell lemonade for $5. Customers pay with $5, $10, or $20. You must give correct change. Start with $0.
* **Question:** If a customer gives you $20, and you have (three $5 bills) AND (one $10 bill + one $5 bill), which set of bills do you give back as change?
* *Hint:* Which bill is more "valuable" to keep for future customers?