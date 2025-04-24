<h2><a href="https://leetcode.com/problems/count-complete-subarrays-in-an-array">2856. Count Complete Subarrays in an Array</a></h2><h3>Medium</h3><hr><p>You are given an array <code>nums</code> consisting of <strong>positive</strong> integers.</p>

<p>We call a subarray of an array <strong>complete</strong> if the following condition is satisfied:</p>

<ul>
	<li>The number of <strong>distinct</strong> elements in the subarray is equal to the number of distinct elements in the whole array.</li>
</ul>

<p>Return <em>the number of <strong>complete</strong> subarrays</em>.</p>

<p>A <strong>subarray</strong> is a contiguous non-empty part of an array.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,3,1,2,2]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The complete subarrays are the following: [1,3,1,2], [1,3,1,2,2], [3,1,2] and [3,1,2,2].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [5,5,5,5]
<strong>Output:</strong> 10
<strong>Explanation:</strong> The array consists only of the integer 5, so any subarray is complete. The number of subarrays that we can choose is 10.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 2000</code></li>
</ul>

# Solution

## Optimized Approach (Two Pointers + Hash Map)

### Step-by-Step:

#### 1. Find Total Unique Elements
- Use a `set` to find how many unique elements exist in the original array.
- Let's call this number `totalDistinct`.

#### 2. Sub-problem: Count subarrays with at most K distinct elements
- We use a **sliding window (two pointers)** approach with a **hash map** to keep track of the frequency of each number in the current window.

#### 3. Key Trick:
- To count subarrays that have **exactly `K` distinct elements**, use the formula:
- exactlyK = atMostK(K) - atMostK(K - 1)
- This subtracts the number of subarrays with up to `K - 1` distinct elements from the number with up to `K`.

#### 4. Return the result:
- Use the above formula with `K = totalDistinct` to get the number of **complete subarrays**.
- countCompleteSubarrays = atMostK(totalDistinct) - atMostK(totalDistinct - 1)
 
