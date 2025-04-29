<h2><a href="https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times">3213. Count Subarrays Where Max Element Appears at Least K Times</a></h2><h3>Medium</h3><hr><p>You are given an integer array <code>nums</code> and a <strong>positive</strong> integer <code>k</code>.</p>

<p>Return <em>the number of subarrays where the <strong>maximum</strong> element of </em><code>nums</code><em> appears <strong>at least</strong> </em><code>k</code><em> times in that subarray.</em></p>

<p>A <strong>subarray</strong> is a contiguous sequence of elements within an array.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,3,2,3,3], k = 2
<strong>Output:</strong> 6
<strong>Explanation:</strong> The subarrays that contain the element 3 at least 2 times are: [1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,4,2,1], k = 3
<strong>Output:</strong> 0
<strong>Explanation:</strong> No subarray contains the element 4 at least 3 times.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>5</sup></code></li>
</ul>

# Solution

## Summary
- The sliding window moves right forward.
- When the count of maxVal in the window becomes ≥ k, the window is valid.
- For every such valid window, the number of subarrays ending at right and starting from [left ... right] is (n - right), because all these are valid.
- Shrink left until the window becomes invalid again.


## Sliding Window Explanation
### Step 1: Identify the Maximum Value
```
maxVal = max(nums) = 3
```
We want subarrays where 3 appears at least k = 2 times.

### Step 2: Initialize
```
left = 0        // start of sliding window
count = 0       // number of times maxVal appears in window
result = 0      // final count of valid subarrays
```

## Step 3: Iterate with Right Pointer (Sliding Window)

### 👉 right = 0, nums[0] = 1
- Not `maxVal` → `count` remains 0  
- `count < k` → do nothing

---

### 👉 right = 1, nums[1] = 3
- `maxVal` → `count = 1`  
- `count < k` → do nothing

---

### 👉 right = 2, nums[2] = 2
- Not `maxVal` → `count = 1`  
- `count < k` → do nothing

---

### 👉 right = 3, nums[3] = 3
- `maxVal` → `count = 2` ✅ (Valid Window!)

**While `count >= k`:**
- Add `(n - right) = 5 - 3 = 2` subarrays:
  - [0,3] → `[1,3,2,3]`
  - [1,3] → `[3,2,3]`

**Shrink from left:**
- `nums[0] = 1` → not `maxVal` → `count = 2`
- `left = 1`
- `nums[1] = 3` → `maxVal` → decrement `count = 1`
- `left = 2`

✅ `result = 2`

---

### 👉 right = 4, nums[4] = 3
- `maxVal` → `count = 2` ✅

**While `count >= k`:**
- Add `(n - right) = 1` for each valid `left`:
  - `left = 2` → `[2,4] = [2,3,3]`
  - `left = 3` → `[3,4] = [3,3]`

**Shrink from left:**
- `nums[2] = 2` → not `maxVal` → `count = 2`
- `left = 3`
- `nums[3] = 3` → `maxVal` → decrement `count = 1`
- `left = 4`

✅ `result = 2 (previous) + 2 (current) = 4`

---

## ✅ Final Result: `6` Valid Subarrays

1. `[1,3,2,3]`  
2. `[1,3,2,3,3]`  
3. `[3,2,3]`  
4. `[3,2,3,3]`  
5. `[2,3,3]`  
6. `[3,3]`

