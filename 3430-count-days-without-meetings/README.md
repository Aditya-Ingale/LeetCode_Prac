<h2><a href="https://leetcode.com/problems/count-days-without-meetings">3430. Count Days Without Meetings</a></h2><h3>Medium</h3><hr><p>You are given a positive integer <code>days</code> representing the total number of days an employee is available for work (starting from day 1). You are also given a 2D array <code>meetings</code> of size <code>n</code> where, <code>meetings[i] = [start_i, end_i]</code> represents the starting and ending days of meeting <code>i</code> (inclusive).</p>

<p>Return the count of days when the employee is available for work but no meetings are scheduled.</p>

<p><strong>Note: </strong>The meetings may overlap.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">days = 10, meetings = [[5,7],[1,3],[9,10]]</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>

<p>There is no meeting scheduled on the 4<sup>th</sup> and 8<sup>th</sup> days.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">days = 5, meetings = [[2,4],[1,3]]</span></p>

<p><strong>Output:</strong> <span class="example-io">1</span></p>

<p><strong>Explanation:</strong></p>

<p>There is no meeting scheduled on the 5<sup>th </sup>day.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">days = 6, meetings = [[1,6]]</span></p>

<p><strong>Output:</strong> 0</p>

<p><strong>Explanation:</strong></p>

<p>Meetings are scheduled for all working days.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= days &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= meetings.length &lt;= 10<sup>5</sup></code></li>
	<li><code>meetings[i].length == 2</code></li>
	<li><code><font face="monospace">1 &lt;= meetings[i][0] &lt;= meetings[i][1] &lt;= days</font></code></li>
</ul>

# Solution

# Count Available Work Days

### 1. Sort Meetings
- Sort the `meetings` array by the starting day.

### 2. Merge Overlapping Intervals
- Use a variable `lastEnd` to track the last occupied day.
- Iterate through the sorted `meetings` and check if there are gaps between consecutive meetings.

### 3. Count Free Days
- If there is a gap between `lastEnd` and the next meeting, count those days as free.
- If there are free days after the last meeting until `days`, count those too.

---

---

## Time Complexity Analysis
- **Sorting the meetings**: \(O(n \log n)\)
- **Iterating through meetings**: \(O(n)\)
- **Total Complexity**: \(O(n \log n)\), which is efficient for large inputs.

---

## Edge Cases Considered
✅ All days are occupied (`meetings = [[1, days]]`).

✅ No meetings at all (`meetings = []`).

✅ Meetings with full overlap (`meetings = [[1,3], [2,4], [3,5]]`).

✅ Meetings with gaps (`meetings = [[1,2], [4,5], [7,8]]`).

---

## Alternative Approaches
### 1. Using a Set (Inefficient for large `days`)
- Store occupied days in a `set<int>` and count the remaining ones.
- **Drawback:** If `days` is large (e.g., \(10^9\)), it requires too much memory.

### 2. Using a Boolean Array (Only for small `days` values)
- Mark occupied days in an array and count unmarked days.
- **Drawback:** Not feasible for large `days`.

This implementation is optimized for large constraints. 🚀

