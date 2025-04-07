<h2><a href="https://leetcode.com/problems/partition-equal-subset-sum">416. Partition Equal Subset Sum</a></h2><h3>Medium</h3><hr><p>Given an integer array <code>nums</code>, return <code>true</code> <em>if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or </em><code>false</code><em> otherwise</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,5,11,5]
<strong>Output:</strong> true
<strong>Explanation:</strong> The array can be partitioned as [1, 5, 5] and [11].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3,5]
<strong>Output:</strong> false
<strong>Explanation:</strong> The array cannot be partitioned into equal sum subsets.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 200</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
</ul>


# Solution

### 🔍 Step-by-step Breakdown:

1. **Total Sum**: 
   - First, calculate the total sum of the array.
   - If the total sum is **odd**, it's impossible to divide it into two equal parts (you can't split an odd number evenly).

2. **Target Sum**:
   - If the total sum is even, we aim to find **a subset** whose sum is **half of the total sum** (i.e., `target = totalSum / 2`).
   - If such a subset exists, the rest of the elements automatically form the second subset with the same sum.

3. **Dynamic Programming (1D)**:
   - Use a `dp` array where `dp[i]` represents whether a subset with sum `i` is possible.
   - Initialize `dp[0] = true` (a subset sum of 0 is always possible with an empty set).
   - For every number in the array, update the `dp` array **in reverse** to avoid using the same number multiple times.

### Why Reverse Loop?
- When updating `dp[j] = dp[j] || dp[j - num]`, we go backwards to make sure we don’t reuse the same `num` multiple times in this iteration.

---

## Time and Space Complexity

- **Time Complexity**: `O(n * sum/2)` where `n` is the number of elements.
- **Space Complexity**: `O(sum/2)` due to the 1D `dp` array.

