<h2><a href="https://leetcode.com/problems/partition-labels">768. Partition Labels</a></h2><h3>Medium</h3><hr><p>You are given a string <code>s</code>. We want to partition the string into as many parts as possible so that each letter appears in at most one part. For example, the string <code>&quot;ababcc&quot;</code> can be partitioned into <code>[&quot;abab&quot;, &quot;cc&quot;]</code>, but partitions such as <code>[&quot;aba&quot;, &quot;bcc&quot;]</code> or <code>[&quot;ab&quot;, &quot;ab&quot;, &quot;cc&quot;]</code> are invalid.</p>

<p>Note that the partition is done so that after concatenating all the parts in order, the resultant string should be <code>s</code>.</p>

<p>Return <em>a list of integers representing the size of these parts</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;ababcbacadefegdehijhklij&quot;
<strong>Output:</strong> [9,7,8]
<strong>Explanation:</strong>
The partition is &quot;ababcbaca&quot;, &quot;defegde&quot;, &quot;hijhklij&quot;.
This is a partition so that each letter appears in at most one part.
A partition like &quot;ababcbacadefegde&quot;, &quot;hijhklij&quot; is incorrect, because it splits s into less parts.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;eccbbbbdec&quot;
<strong>Output:</strong> [10]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 500</code></li>
	<li><code>s</code> consists of lowercase English letters.</li>
</ul>

# Solution

## Approach 
We solve this problem using a **greedy algorithm** with two steps:

### Step 1: Find the last occurrence of each character
We first scan through the string and store the **last index** where each character appears in an array `lastIndex[26]`. This helps us determine how far a character extends in the string.

### Step 2: Create partitions
We iterate through the string again, maintaining a variable `end` that keeps track of the **farthest last index** encountered. When we reach `end`, we create a partition because all characters seen so far belong in this partition.

## Explanation with Example
Let's take `s = "ababcbacadefegdehijhklij"`:
1. **Find last occurrences:**
   - `a` last appears at index `8`
   - `b` last appears at index `5`
   - `c` last appears at index `7`
   - `d` last appears at index `14`
   - ... (similarly for other letters)

2. **Partitioning the string:**
   - Start from index `0`, update `end` based on the farthest last occurrence of any character seen so far.
   - When `i == end`, a partition is formed.
   - Repeat until the string is fully partitioned.

## Time and Space Complexity
- **Time Complexity:** `O(N)`, since we scan the string twice.
- **Space Complexity:** `O(1)`, since we only store the last occurrences for 26 lowercase letters.
