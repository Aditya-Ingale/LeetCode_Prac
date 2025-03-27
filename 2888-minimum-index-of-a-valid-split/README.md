<h2><a href="https://leetcode.com/problems/minimum-index-of-a-valid-split">2888. Minimum Index of a Valid Split</a></h2><h3>Medium</h3><hr><p>An element <code>x</code> of an integer array <code>arr</code> of length <code>m</code> is <strong>dominant</strong> if <strong>more than half</strong> the elements of <code>arr</code> have a value of <code>x</code>.</p>

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code> of length <code>n</code> with one <strong>dominant</strong> element.</p>

<p>You can split <code>nums</code> at an index <code>i</code> into two arrays <code>nums[0, ..., i]</code> and <code>nums[i + 1, ..., n - 1]</code>, but the split is only <strong>valid</strong> if:</p>

<ul>
	<li><code>0 &lt;= i &lt; n - 1</code></li>
	<li><code>nums[0, ..., i]</code>, and <code>nums[i + 1, ..., n - 1]</code> have the same dominant element.</li>
</ul>

<p>Here, <code>nums[i, ..., j]</code> denotes the subarray of <code>nums</code> starting at index <code>i</code> and ending at index <code>j</code>, both ends being inclusive. Particularly, if <code>j &lt; i</code> then <code>nums[i, ..., j]</code> denotes an empty subarray.</p>

<p>Return <em>the <strong>minimum</strong> index of a <strong>valid split</strong></em>. If no valid split exists, return <code>-1</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,2,2]
<strong>Output:</strong> 2
<strong>Explanation:</strong> We can split the array at index 2 to obtain arrays [1,2,2] and [2]. 
In array [1,2,2], element 2 is dominant since it occurs twice in the array and 2 * 2 &gt; 3. 
In array [2], element 2 is dominant since it occurs once in the array and 1 * 2 &gt; 1.
Both [1,2,2] and [2] have the same dominant element as nums, so this is a valid split. 
It can be shown that index 2 is the minimum index of a valid split. </pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,1,3,1,1,1,7,1,2,1]
<strong>Output:</strong> 4
<strong>Explanation:</strong> We can split the array at index 4 to obtain arrays [2,1,3,1,1] and [1,7,1,2,1].
In array [2,1,3,1,1], element 1 is dominant since it occurs thrice in the array and 3 * 2 &gt; 5.
In array [1,7,1,2,1], element 1 is dominant since it occurs thrice in the array and 3 * 2 &gt; 5.
Both [2,1,3,1,1] and [1,7,1,2,1] have the same dominant element as nums, so this is a valid split.
It can be shown that index 4 is the minimum index of a valid split.</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,3,3,3,7,2,2]
<strong>Output:</strong> -1
<strong>Explanation:</strong> It can be shown that there is no valid split.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>nums</code> has exactly one dominant element.</li>
</ul>


# Solution

## Approach

### Step 1: Find the Dominant Element
Since we are given that the array has exactly one dominant element, we can determine it using a frequency count.

- Use a hash map (`unordered_map`) to count the occurrences of each number.
- The dominant element must appear more than `n/2` times.

#### Example:
```cpp
nums = [2,1,3,1,1,1,7,1,2,1]
```

#### Frequency count:
```text
1 → 5 times
2 → 2 times
3 → 1 time
7 → 1 time
```
Since `1` appears more than `n/2 = 5` times, `1` is the dominant element.

---

### Step 2: Find the Minimum Valid Split
Now, we traverse `nums` and maintain:

- **Left side count (`leftCount`)** → Number of times the dominant element appears in the first part.
- **Right side count (`rightCount`)** → Number of times the dominant element appears in the second part.

At each index `i`, we check:

- If `leftCount * 2 > (i + 1)`, the left part is valid.
- If `rightCount * 2 > (n - i - 1)`, the right part is valid.
- If both conditions are met, return `i` as the minimum valid split.

#### Example Walkthrough:
For `nums = [2,1,3,1,1,1,7,1,2,1]`

| Index | Left Count | Right Count | Valid Split? |
|--------|------------|-------------|--------------|
| 0      | 0          | 5           | No           |
| 1      | 1          | 4           | No           |
| 2      | 1          | 4           | No           |
| 3      | 2          | 3           | No           |
| 4      | 3          | 2           | Yes (return 4) |

Thus, the minimum valid split is at index **4**.

---

## Complexity Analysis

- **Finding the dominant element** → `O(n)` (Using a hash map for frequency count).
- **Finding the minimum valid split** → `O(n)` (Single pass through `nums`).
- **Total Complexity** → `O(n)` (Efficient for `n` up to `10^5`).
