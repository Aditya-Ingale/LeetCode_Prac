<h2><a href="https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid">2160. Minimum Operations to Make a Uni-Value Grid</a></h2><h3>Medium</h3><hr><p>You are given a 2D integer <code>grid</code> of size <code>m x n</code> and an integer <code>x</code>. In one operation, you can <strong>add</strong> <code>x</code> to or <strong>subtract</strong> <code>x</code> from any element in the <code>grid</code>.</p>

<p>A <strong>uni-value grid</strong> is a grid where all the elements of it are equal.</p>

<p>Return <em>the <strong>minimum</strong> number of operations to make the grid <strong>uni-value</strong></em>. If it is not possible, return <code>-1</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/09/21/gridtxt.png" style="width: 164px; height: 165px;" />
<pre>
<strong>Input:</strong> grid = [[2,4],[6,8]], x = 2
<strong>Output:</strong> 4
<strong>Explanation:</strong> We can make every element equal to 4 by doing the following: 
- Add x to 2 once.
- Subtract x from 6 once.
- Subtract x from 8 twice.
A total of 4 operations were used.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/09/21/gridtxt-1.png" style="width: 164px; height: 165px;" />
<pre>
<strong>Input:</strong> grid = [[1,5],[2,3]], x = 1
<strong>Output:</strong> 5
<strong>Explanation:</strong> We can make every element equal to 3.
</pre>

<p><strong class="example">Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/09/21/gridtxt-2.png" style="width: 164px; height: 165px;" />
<pre>
<strong>Input:</strong> grid = [[1,2],[3,4]], x = 2
<strong>Output:</strong> -1
<strong>Explanation:</strong> It is impossible to make every element equal.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= m * n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= x, grid[i][j] &lt;= 10<sup>4</sup></code></li>
</ul>

# Solution

## Optimized Approach
1. **Flatten the Grid:** Convert the 2D grid into a 1D array.
2. **Find the Median Efficiently:** Instead of sorting, use `nth_element` to get the median in `O(n)` time.
3. **Check Feasibility:** If any difference `(num - median)` is not divisible by `x`, return `-1`.
4. **Calculate Operations:** Sum up `(abs(num - median) / x)` for all elements.

### Complexity Analysis
- **Flattening the Grid:** `O(m * n)`
- **Finding the Median:** `O(m * n)` (using `nth_element` instead of sorting)
- **Computing Operations:** `O(m * n)`

**Overall Complexity:** `O(m * n)`, which is more efficient than the previous `O(m * n log(m * n))` approach.

## Example Walkthrough
### Example 1
#### Input:
```cpp
grid = [[2,4],[6,8]], x = 2
```
#### Output:
```
4
```
#### Explanation:
Operations to make all elements `4`:
- Add `x` to `2` once.
- Subtract `x` from `6` once.
- Subtract `x` from `8` twice.

### Example 2
#### Input:
```cpp
grid = [[1,5],[2,3]], x = 1
```
#### Output:
```
5
```
#### Explanation:
Operations to make all elements `3`.

### Example 3
#### Input:
```cpp
grid = [[1,2],[3,4]], x = 2
```
#### Output:
```
-1
```
#### Explanation:
Cannot make all elements equal as the differences are not multiples of `x`. 
