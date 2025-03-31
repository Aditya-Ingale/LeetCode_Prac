<h2><a href="https://leetcode.com/problems/put-marbles-in-bags">2681. Put Marbles in Bags</a></h2><h3>Hard</h3><hr><p>You have <code>k</code> bags. You are given a <strong>0-indexed</strong> integer array <code>weights</code> where <code>weights[i]</code> is the weight of the <code>i<sup>th</sup></code> marble. You are also given the integer <code>k.</code></p>

<p>Divide the marbles into the <code>k</code> bags according to the following rules:</p>

<ul>
	<li>No bag is empty.</li>
	<li>If the <code>i<sup>th</sup></code> marble and <code>j<sup>th</sup></code> marble are in a bag, then all marbles with an index between the <code>i<sup>th</sup></code> and <code>j<sup>th</sup></code> indices should also be in that same bag.</li>
	<li>If a bag consists of all the marbles with an index from <code>i</code> to <code>j</code> inclusively, then the cost of the bag is <code>weights[i] + weights[j]</code>.</li>
</ul>

<p>The <strong>score</strong> after distributing the marbles is the sum of the costs of all the <code>k</code> bags.</p>

<p>Return <em>the <strong>difference</strong> between the <strong>maximum</strong> and <strong>minimum</strong> scores among marble distributions</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> weights = [1,3,5,1], k = 2
<strong>Output:</strong> 4
<strong>Explanation:</strong> 
The distribution [1],[3,5,1] results in the minimal score of (1+1) + (3+1) = 6. 
The distribution [1,3],[5,1], results in the maximal score of (1+3) + (5+1) = 10. 
Thus, we return their difference 10 - 6 = 4.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> weights = [1, 3], k = 2
<strong>Output:</strong> 0
<strong>Explanation:</strong> The only distribution possible is [1],[3]. 
Since both the maximal and minimal score are the same, we return 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= weights.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= weights[i] &lt;= 10<sup>9</sup></code></li>
</ul>

# Solution

## Approach
To solve this problem efficiently, we use **greedy sorting and prefix sum technique**:

### Understanding the Partitioning:
- The marbles must be grouped in **continuous subarrays**.
- Instead of working directly with individual weights, we consider the sum of **adjacent pairs** because each partition boundary affects the total score.

### Compute Pairwise Sums:
- We generate a list of sums of adjacent pairs: `weights[i] + weights[i+1]`.
- These sums will help in determining where to split the array.

### Sorting the Pair Sums:
- We sort these pair sums in **ascending order**.
- The minimum possible score will take the **smallest (k-1) sums**.
- The maximum possible score will take the **largest (k-1) sums**.

### Calculate the Difference:
- The final answer is the difference between the sum of the largest `(k-1)` sums and the sum of the smallest `(k-1)` sums.

## Complexity Analysis
- **Computing pair sums** takes **O(n)**.
- **Sorting the sums** takes **O(n log n)**.
- **Calculating the scores** takes **O(k)**, but since `k ≤ n`, it is at most **O(n)**.
- **Total Complexity**: **O(n log n)** due to sorting.

This approach ensures efficiency, even for large inputs (`n ≤ 10^5`).

---

## Example Walkthrough

### Example 1:
```cpp
Input: weights = [1, 3, 5, 1], k = 2
```
**Pair sums:**
```cpp
[1+3, 3+5, 5+1] = [4, 8, 6]
```
**Sorted pair sums:** `[4, 6, 8]`

- **Minimum score sum:** `4` (smallest 1 sum)
- **Maximum score sum:** `8` (largest 1 sum)

Final Answer: `8 - 4 = 4`

---

### Example 2:
```cpp
Input: weights = [1, 3], k = 2
```
Only one possible way to split: `[1]` and `[3]`.

Both minimum and maximum scores are `4`, so the answer is `0`.

---
