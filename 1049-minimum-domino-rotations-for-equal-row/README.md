<h2><a href="https://leetcode.com/problems/minimum-domino-rotations-for-equal-row">1049. Minimum Domino Rotations For Equal Row</a></h2><h3>Medium</h3><hr><p>In a row of dominoes, <code>tops[i]</code> and <code>bottoms[i]</code> represent the top and bottom halves of the <code>i<sup>th</sup></code> domino. (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)</p>

<p>We may rotate the <code>i<sup>th</sup></code> domino, so that <code>tops[i]</code> and <code>bottoms[i]</code> swap values.</p>

<p>Return the minimum number of rotations so that all the values in <code>tops</code> are the same, or all the values in <code>bottoms</code> are the same.</p>

<p>If it cannot be done, return <code>-1</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/05/14/domino.png" style="height: 300px; width: 421px;" />
<pre>
<strong>Input:</strong> tops = [2,1,2,4,2,2], bottoms = [5,2,6,2,3,2]
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
The first figure represents the dominoes as given by tops and bottoms: before we do any rotations.
If we rotate the second and fourth dominoes, we can make every value in the top row equal to 2, as indicated by the second figure.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> tops = [3,5,1,2,3], bottoms = [3,6,3,3,4]
<strong>Output:</strong> -1
<strong>Explanation:</strong> 
In this case, it is not possible to rotate the dominoes to make one row of values equal.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= tops.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>bottoms.length == tops.length</code></li>
	<li><code>1 &lt;= tops[i], bottoms[i] &lt;= 6</code></li>
</ul>


# Solution

# Domino Rotations - Minimum Moves to Uniform Row

##  Problem Recap

You are given two arrays:

- `tops[i]` = number on the **top** half of the *i-th* domino  
- `bottoms[i]` = number on the **bottom** half of the *i-th* domino  

Each domino can be **rotated** (i.e., swap top and bottom values).  
Your goal is to **make all values in either `tops` or `bottoms` the same**, using the **minimum number of rotations**.  

If it's **impossible**, return `-1`.

---

##  Key Insight

To make all values in `tops` or `bottoms` the same:
- That number **must appear in every domino**, either on the top or bottom.
- So, the **only two possible candidates** to check are:
  - `tops[0]`
  - `bottoms[0]`

Why only these two?  
Because if a number does **not appear in the first domino**, it **can’t possibly** be present in all dominoes (since we only rotate, not replace values).

---

##  Algorithm Breakdown

We try both possible candidates:

1. Try to make **all values equal to `tops[0]`**
2. If that fails, try to make **all values equal to `bottoms[0]`**

### For a given candidate number:
Loop through each domino:
- If **neither top nor bottom** has the candidate → return `-1`
- If **top ≠ candidate** → rotate this domino to bring candidate to top → `rotateTop++`
- If **bottom ≠ candidate** → rotate this domino to bring candidate to bottom → `rotateBottom++`

The **minimum** of `rotateTop` and `rotateBottom` is the answer for that candidate.

---

## Example Walkthrough

```cpp
tops    = [2, 1, 2, 4, 2, 2]
bottoms = [5, 2, 6, 2, 3, 2]
```

- Try candidate = tops[0] = 2:
  - Domino 0: top = 2 → ✅
  - Domino 1: top = 1, bottom = 2 → rotate to bring 2 to top → rotateTop++
  - Domino 2: top = 2 → ✅
  - Domino 3: top = 4, bottom = 2 → rotate to bring 2 to top → rotateTop++
  - Domino 4: top = 2 → ✅
  - Domino 5: top = 2 → ✅
- We needed 2 rotations to make all tops = 2 → ✅ Return 2
