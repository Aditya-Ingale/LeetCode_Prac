<h2><a href="https://leetcode.com/problems/count-the-number-of-ideal-arrays">2415. Count the Number of Ideal Arrays</a></h2><h3>Hard</h3><hr><p>You are given two integers <code>n</code> and <code>maxValue</code>, which are used to describe an <strong>ideal</strong> array.</p>

<p>A <strong>0-indexed</strong> integer array <code>arr</code> of length <code>n</code> is considered <strong>ideal</strong> if the following conditions hold:</p>

<ul>
	<li>Every <code>arr[i]</code> is a value from <code>1</code> to <code>maxValue</code>, for <code>0 &lt;= i &lt; n</code>.</li>
	<li>Every <code>arr[i]</code> is divisible by <code>arr[i - 1]</code>, for <code>0 &lt; i &lt; n</code>.</li>
</ul>

<p>Return <em>the number of <strong>distinct</strong> ideal arrays of length </em><code>n</code>. Since the answer may be very large, return it modulo <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 2, maxValue = 5
<strong>Output:</strong> 10
<strong>Explanation:</strong> The following are the possible ideal arrays:
- Arrays starting with the value 1 (5 arrays): [1,1], [1,2], [1,3], [1,4], [1,5]
- Arrays starting with the value 2 (2 arrays): [2,2], [2,4]
- Arrays starting with the value 3 (1 array): [3,3]
- Arrays starting with the value 4 (1 array): [4,4]
- Arrays starting with the value 5 (1 array): [5,5]
There are a total of 5 + 2 + 1 + 1 + 1 = 10 distinct ideal arrays.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 5, maxValue = 3
<strong>Output:</strong> 11
<strong>Explanation:</strong> The following are the possible ideal arrays:
- Arrays starting with the value 1 (9 arrays): 
   - With no other distinct values (1 array): [1,1,1,1,1] 
   - With 2<sup>nd</sup> distinct value 2 (4 arrays): [1,1,1,1,2], [1,1,1,2,2], [1,1,2,2,2], [1,2,2,2,2]
   - With 2<sup>nd</sup> distinct value 3 (4 arrays): [1,1,1,1,3], [1,1,1,3,3], [1,1,3,3,3], [1,3,3,3,3]
- Arrays starting with the value 2 (1 array): [2,2,2,2,2]
- Arrays starting with the value 3 (1 array): [3,3,3,3,3]
There are a total of 9 + 1 + 1 = 11 distinct ideal arrays.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= maxValue &lt;= 10<sup>4</sup></code></li>
</ul>

# Solution

### Input:
- n = 2, maxValue = 5

### Output:
- 10


### Explanation:
We list all ideal arrays of length 2:
- Starting with 1: [1,1], [1,2], [1,3], [1,4], [1,5]
- Starting with 2: [2,2], [2,4]
- Starting with 3: [3,3]
- Starting with 4: [4,4]
- Starting with 5: [5,5]

Total = **10**

---

## 🧠 Key Idea

An ideal array must follow the pattern:
- arr[i] % arr[i-1] == 0

That means the current element is a multiple of the previous one.

For example:
- `[1, 2, 4, 4]` is valid
- `[2, 3]` is invalid because 3 is not divisible by 2

---

## Optimized Approach 

We use:
1. **Dynamic Programming (DP)** to count all valid multiplication-based sequences for values up to `maxValue`.
2. **Combinatorics** (nCr = combinations) to calculate how many ways we can place values in an array of length `n`.

### Steps:
1. For every number from `1` to `maxValue`, build all sequences where each element is divisible by the previous one.
2. Track how many sequences of each length exist.
3. For every sequence of length `k`, the number of ways to place it in an array of size `n` is:
C(n-1, k-1)

This is because we can fix one number and choose `k-1` positions out of `n-1` remaining places.

---

## Combinatorics Optimization

Instead of building a huge combination table (which causes runtime error), we:
- Precompute factorials and modular inverses.
- Use this to compute `C(n, r)` efficiently in constant time using:
C(n, r) = fact[n] / (fact[r] * fact[n - r])


---

## 🔧 OOP Design

We split the logic into two clean classes:
- `Combinatorics`: handles factorials and combination calculations
- `IdealArrayCounter`: handles the dynamic programming and final counting

This makes the code easier to test, extend, and reuse.

---

## 🕒 Time & Space Complexity

- **Time Complexity:** `O(maxValue * log(maxValue) * log(maxValue))` (very efficient for n, maxValue ≤ 10⁴)
- **Space Complexity:** `O(maxValue * log(maxValue))` for the DP table

---
