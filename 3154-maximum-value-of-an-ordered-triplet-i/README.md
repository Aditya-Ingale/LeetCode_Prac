<h2><a href="https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i">3154. Maximum Value of an Ordered Triplet I</a></h2><h3>Easy</h3><hr><p>You are given a <strong>0-indexed</strong> integer array <code>nums</code>.</p>

<p>Return <em><strong>the maximum value over all triplets of indices</strong></em> <code>(i, j, k)</code> <em>such that</em> <code>i &lt; j &lt; k</code>. If all such triplets have a negative value, return <code>0</code>.</p>

<p>The <strong>value of a triplet of indices</strong> <code>(i, j, k)</code> is equal to <code>(nums[i] - nums[j]) * nums[k]</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [12,6,1,2,7]
<strong>Output:</strong> 77
<strong>Explanation:</strong> The value of the triplet (0, 2, 4) is (nums[0] - nums[2]) * nums[4] = 77.
It can be shown that there are no ordered triplets of indices with a value greater than 77. 
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,10,3,4,19]
<strong>Output:</strong> 133
<strong>Explanation:</strong> The value of the triplet (1, 2, 4) is (nums[1] - nums[2]) * nums[4] = 133.
It can be shown that there are no ordered triplets of indices with a value greater than 133.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong> 0
<strong>Explanation:</strong> The only ordered triplet of indices (0, 1, 2) has a negative value of (nums[0] - nums[1]) * nums[2] = -3. Hence, the answer would be 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
</ul>

# Solution

# Maximum Triplet Value

## Problem Statement
Given a **0-indexed integer array** `nums`, find the maximum value among all **triplets** `(i, j, k)` such that:

- `i < j < k`
- The value is computed as:
  
  ```
  (nums[i] - nums[j]) * nums[k]
  ```
  
- If all such values are negative, return `0`.

## Approach

### **Optimized Approach: O(n) Time Complexity**
To efficiently find the maximum triplet value, we follow these steps:

1. **Track `maxLeft`** → This keeps track of the largest value `nums[i]` seen so far (leftmost element).
2. **Precompute `maxRight[k]`** → This stores the maximum value of `nums[k]` for all `k > j` (rightmost element).
3. **Iterate through `j` as the middle element**:
   - If `nums[i] > nums[j]` and `nums[k] > 0`, compute `(nums[i] - nums[j]) * nums[k]` and update `maxVal`.

### **Step-by-Step Explanation**

1. **Precompute `maxRight[k]`**:
   - We traverse `nums` in **reverse order** to store the largest value to the right of each index.

2. **Iterate through the array with `j` as the middle index**:
   - Track the maximum `nums[i]` value before `j` (`maxLeft`).
   - Use the precomputed `maxRight[j+1]` to get the best possible `nums[k]` value.
   - Compute and update the maximum triplet value if the conditions are met.
   - Update `maxLeft` after checking each `j`.

## **Example Walkthrough**

### Example 1:
**Input:** `[12,6,1,2,7]`

| Index | `nums`  | `maxLeft` | `maxRight` |
|--------|--------|-----------|------------|
| 0      | 12     | 12        | 12         |
| 1      | 6      | 12        | 7          |
| 2      | 1      | 12        | 7          |
| 3      | 2      | 12        | 7          |
| 4      | 7      | 12        | 7          |

- Best triplet: `(12 - 1) * 7 = 77`

**Output:** `77`

### Example 2:
**Input:** `[1,10,3,4,19]`

- Best triplet: `(10 - 3) * 19 = 133`

**Output:** `133`

### Example 3:
**Input:** `[1,2,3]`

- Only possible triplet is negative, so return `0`.

**Output:** `0`

---
# Time Complexity 
- O(n)
