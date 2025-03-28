<h2><a href="https://leetcode.com/problems/maximum-number-of-points-from-grid-queries">2588. Maximum Number of Points From Grid Queries</a></h2><h3>Hard</h3><hr><p>You are given an <code>m x n</code> integer matrix <code>grid</code> and an array <code>queries</code> of size <code>k</code>.</p>

<p>Find an array <code>answer</code> of size <code>k</code> such that for each integer <code>queries[i]</code> you start in the <strong>top left</strong> cell of the matrix and repeat the following process:</p>

<ul>
	<li>If <code>queries[i]</code> is <strong>strictly</strong> greater than the value of the current cell that you are in, then you get one point if it is your first time visiting this cell, and you can move to any <strong>adjacent</strong> cell in all <code>4</code> directions: up, down, left, and right.</li>
	<li>Otherwise, you do not get any points, and you end this process.</li>
</ul>

<p>After the process, <code>answer[i]</code> is the <strong>maximum</strong> number of points you can get. <strong>Note</strong> that for each query you are allowed to visit the same cell <strong>multiple</strong> times.</p>

<p>Return <em>the resulting array</em> <code>answer</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2025/03/15/image1.png" style="width: 571px; height: 152px;" />
<pre>
<strong>Input:</strong> grid = [[1,2,3],[2,5,7],[3,5,1]], queries = [5,6,2]
<strong>Output:</strong> [5,8,1]
<strong>Explanation:</strong> The diagrams above show which cells we visit to get points for each query.</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/10/20/yetgriddrawio-2.png" />
<pre>
<strong>Input:</strong> grid = [[5,2,1],[1,1,2]], queries = [3]
<strong>Output:</strong> [0]
<strong>Explanation:</strong> We can not get any points because the value of the top left cell is already greater than or equal to 3.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>2 &lt;= m, n &lt;= 1000</code></li>
	<li><code>4 &lt;= m * n &lt;= 10<sup>5</sup></code></li>
	<li><code>k == queries.length</code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= grid[i][j], queries[i] &lt;= 10<sup>6</sup></code></li>
</ul>

# Solution

## Optimized Approach
### 1. **Sorting Queries**
Instead of handling queries in order, we first **sort** them. This allows us to process them in increasing order efficiently.

### 2. **Priority Queue (Min-Heap)**
We use a **min-heap (priority queue)** to always process the smallest cell value first. The heap stores pairs of `{cell_value, position}`.

### 3. **Processing Queries Efficiently**
For each query:
- We pop cells from the heap **as long as their value is less than the query**.
- Every time we pop a cell, we count it and mark it as visited.
- We push all its **unvisited neighbors** into the heap.
- When the heap's top cell is **greater than or equal** to the query, we stop processing.
- The current count is stored as the answer for this query.

### 4. **Storing Results Efficiently**
Since queries are sorted, we store results in an array and reorder them back to their original positions after processing.

## Time Complexity
- **Sorting queries**: `O(k log k)`
- **Heap operations**: `O(m * n log (m * n))` in total, since each cell is pushed into the heap at most once.
- **Final complexity**: `O((m * n + k) log (m * n))`

## Example Walkthrough
### Input:
```cpp
grid = [[1,2,3],
        [2,5,7],
        [3,5,1]]
queries = [5,6,2]
```

### Sorted Queries:
`[2, 5, 6]` (process in this order and store original positions)

### Processing Each Query:
1. **Query = 2**
   - Start at `(0,0)`, value `1 < 2`, collect `1` point.
   - Cannot move further, **Result = 1**.

2. **Query = 5**
   - Start again at `(0,0)`, process all cells with value `< 5`.
   - Collect `5` points before hitting `5`.
   - **Result = 5**.

3. **Query = 6**
   - Continue from previous state.
   - Process all new cells with value `< 6`.
   - Collect `8` points.
   - **Result = 8**.

### Final Output:
```cpp
[5, 8, 1]
```

This method efficiently processes large grids and multiple queries in a scalable way.

