<h2><a href="https://leetcode.com/problems/count-the-number-of-complete-components">2793. Count the Number of Complete Components</a></h2><h3>Medium</h3><hr><p>You are given an integer <code>n</code>. There is an <strong>undirected</strong> graph with <code>n</code> vertices, numbered from <code>0</code> to <code>n - 1</code>. You are given a 2D integer array <code>edges</code> where <code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> denotes that there exists an <strong>undirected</strong> edge connecting vertices <code>a<sub>i</sub></code> and <code>b<sub>i</sub></code>.</p>

<p>Return <em>the number of <strong>complete connected components</strong> of the graph</em>.</p>

<p>A <strong>connected component</strong> is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.</p>

<p>A connected component is said to be <b>complete</b> if there exists an edge between every pair of its vertices.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<p><strong class="example"><img alt="" src="https://assets.leetcode.com/uploads/2023/04/11/screenshot-from-2023-04-11-23-31-23.png" style="width: 671px; height: 270px;" /></strong></p>

<pre>
<strong>Input:</strong> n = 6, edges = [[0,1],[0,2],[1,2],[3,4]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> From the picture above, one can see that all of the components of this graph are complete.
</pre>

<p><strong class="example">Example 2:</strong></p>

<p><strong class="example"><img alt="" src="https://assets.leetcode.com/uploads/2023/04/11/screenshot-from-2023-04-11-23-32-00.png" style="width: 671px; height: 270px;" /></strong></p>

<pre>
<strong>Input:</strong> n = 6, edges = [[0,1],[0,2],[1,2],[3,4],[3,5]]
<strong>Output:</strong> 1
<strong>Explanation:</strong> The component containing vertices 0, 1, and 2 is complete since there is an edge between every pair of two vertices. On the other hand, the component containing vertices 3, 4, and 5 is not complete since there is no edge between vertices 4 and 5. Thus, the number of complete components in this graph is 1.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 50</code></li>
	<li><code>0 &lt;= edges.length &lt;= n * (n - 1) / 2</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt;= n - 1</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li>There are no repeated edges.</li>
</ul>


# Solution
# Counting Complete Connected Components in an Undirected Graph

## Problem Statement

You are given an **undirected graph** with `n` vertices, numbered from `0` to `n - 1`. You are also given a **2D integer array** `edges`, where `edges[i] = [a_i, b_i]` denotes an **undirected edge** connecting vertices `a_i` and `b_i`.

A **connected component** is a subgraph where:
- There exists a **path** between every pair of vertices within that component.
- No vertex of the component shares an edge with a vertex outside the component.

A connected component is **complete** if there exists an **edge between every pair** of its vertices.

### Example 1
#### **Input:**
```cpp
n = 6
edges = {{0,1}, {0,2}, {1,2}, {3,4}}
```
#### **Graph Representation:**
```
Component 1: 0 - 1 - 2 (Complete)
Component 2: 3 - 4 (Complete)
Component 3: 5 (Single node, Complete)
```
#### **Output:**
```cpp
3
```

### Example 2
#### **Input:**
```cpp
n = 6
edges = {{0,1}, {0,2}, {1,2}, {3,4}, {3,5}}
```
#### **Graph Representation:**
```
Component 1: 0 - 1 - 2 (Complete)
Component 2: 3 - 4 - 5 (Not Complete, missing 4-5 edge)
Component 3: 6 (Single node, Complete)
```
#### **Output:**
```cpp
1
```

---

## **Approach: Disjoint Set Union (DSU)**
To efficiently find connected components and determine if they are **complete**, we use **Disjoint Set Union (DSU) with Path Compression and Union by Rank**.

### **Data Structures Used**
- `par[i]`: Stores the **parent (representative)** of each node.
- `rank[i]`: Helps with **Union by Rank** to keep the tree balanced.
- `count[i]`: Stores the **size** of each connected component.
- `edge[i]`: Tracks the **number of edges** within each component.

### **Algorithm Steps**
1. **Initialize DSU**:
   - Each node is its own **parent**.
   - Set **count = 1** (each node is its own component initially).
   - Set **edge = 0** (no edges initially).

2. **Process Each Edge**:
   - Use **Find Parent (Path Compression)** to get root parent.
   - Use **Union by Rank** to merge components.
   - Update `count` and `edge` accordingly.

3. **Count Complete Components**:
   - A **component is complete** if it contains exactly `count * (count - 1) / 2` edges (fully connected graph formula).
   - Iterate over **parent nodes** and count how many satisfy this condition.

---

## **Time Complexity Analysis**
- **Find Parent (Path Compression)**: `O(α(n))` (near constant time)
- **Union by Rank**: `O(α(n))`
- **Processing `m` edges**: `O(m α(n))`
- **Final component check**: `O(n)`
- **Overall Complexity**: `O(n + m)` (Efficient for `n ≤ 50`)

---

## **Edge Cases Considered**
✅ **No edges (`edges = []`)**: Each node is its own complete component.
✅ **All nodes connected (clique)**: Should return `1`.
✅ **Multiple disconnected components**.
✅ **Graph with isolated nodes**.

---

## **Summary**
✅ **Efficiently finds connected components** using DSU.  
✅ **Uses Union by Rank & Path Compression** for optimization.  
✅ **Correctly checks for complete components** using edge count formula.  
✅ **Handles all edge cases optimally**.  

This **DSU-based approach** provides an optimal solution for counting **complete connected components** in an **undirected graph**. 🚀


