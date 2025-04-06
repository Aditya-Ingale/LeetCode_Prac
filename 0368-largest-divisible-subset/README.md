<h2><a href="https://leetcode.com/problems/largest-divisible-subset">368. Largest Divisible Subset</a></h2><h3>Medium</h3><hr><p>Given a set of <strong>distinct</strong> positive integers <code>nums</code>, return the largest subset <code>answer</code> such that every pair <code>(answer[i], answer[j])</code> of elements in this subset satisfies:</p>

<ul>
	<li><code>answer[i] % answer[j] == 0</code>, or</li>
	<li><code>answer[j] % answer[i] == 0</code></li>
</ul>

<p>If there are multiple solutions, return any of them.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong> [1,2]
<strong>Explanation:</strong> [1,3] is also accepted.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,4,8]
<strong>Output:</strong> [1,2,4,8]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 2 * 10<sup>9</sup></code></li>
	<li>All the integers in <code>nums</code> are <strong>unique</strong>.</li>
</ul>

# Solution

### 1. **Sort the Numbers**
Sorting helps because if a number is divisible by another, the smaller one must come first.  
Example: 8 is divisible by 4, 4 is divisible by 2, and 2 is divisible by 1.

### 2. **Dynamic Programming (DP)**
We use a DP array to keep track of the length of the largest divisible subset ending at each element.

- `dp[i]` = length of the largest divisible subset ending at `nums[i]`
- `prev[i]` = index of the previous element in that subset

### 3. **Build the DP Table**
For each number, we check all previous numbers to see if the current number is divisible by them.  
If yes, we update the `dp` and `prev` arrays.

### 4. **Reconstruct the Subset**
Once we find the maximum length subset (using the `dp` array), we backtrack using the `prev` array to get the actual numbers.

## Time and Space Complexity

- **Time:** O(n^2) — Two nested loops for the DP computation
- **Space:** O(n) — For `dp`, `prev`, and the result vector

## Notes
- Sorting ensures we only need to check `nums[i] % nums[j]`, not both ways.
- This solution is optimal and passes all constraints efficiently.

---
