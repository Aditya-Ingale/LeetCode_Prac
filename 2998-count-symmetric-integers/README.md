<h2><a href="https://leetcode.com/problems/count-symmetric-integers">2998.   Count Symmetric Integers</a></h2><h3>Easy</h3><hr><p>You are given two positive integers <code>low</code> and <code>high</code>.</p>

<p>An integer <code>x</code> consisting of <code>2 * n</code> digits is <strong>symmetric</strong> if the sum of the first <code>n</code> digits of <code>x</code> is equal to the sum of the last <code>n</code> digits of <code>x</code>. Numbers with an odd number of digits are never symmetric.</p>

<p>Return <em>the <strong>number of symmetric</strong> integers in the range</em> <code>[low, high]</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> low = 1, high = 100
<strong>Output:</strong> 9
<strong>Explanation:</strong> There are 9 symmetric integers between 1 and 100: 11, 22, 33, 44, 55, 66, 77, 88, and 99.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> low = 1200, high = 1230
<strong>Output:</strong> 4
<strong>Explanation:</strong> There are 4 symmetric integers between 1200 and 1230: 1203, 1212, 1221, and 1230.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= low &lt;= high &lt;= 10<sup>4</sup></code></li>
</ul>

# Solution

## Approach: Digit-by-Digit Check (Efficient)

This approach only checks **2-digit and 4-digit numbers** (because only they can be symmetric within the range `1` to `9999`, which is `10^4`).

---

### 🔍 Step-by-Step Logic

1. **Loop through each number** from `low` to `high`.

2. For each number:

   #### 👉 If it’s a 2-digit number (`10` to `99`):

   - Extract the first digit and second digit using math:
     ```cpp
     int d1 = i / 10;   // First digit
     int d2 = i % 10;   // Second digit
     ```

   - If both digits are the same → it's symmetric (e.g., `33`, `44`).

   #### 👉 If it’s a 4-digit number (`1000` to `9999`):

   - Extract each digit using division and modulo:
     ```cpp
     int d1 = i / 1000;        // Thousands place
     int d2 = (i / 100) % 10;  // Hundreds place
     int d3 = (i / 10) % 10;   // Tens place
     int d4 = i % 10;          // Units place
     ```

   - Check if the **sum of the first two digits equals the sum of the last two digits**:
     ```cpp
     if (d1 + d2 == d3 + d4)
     ```
     - If yes, the number is symmetric (e.g., `1212`, `1230`).

3. **Increment the count** for each symmetric number found.

4. **Return the total count** at the end.
