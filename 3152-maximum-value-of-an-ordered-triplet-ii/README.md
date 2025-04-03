<h2><a href="https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii">3152. Maximum Value of an Ordered Triplet II</a></h2><h3>Medium</h3><hr><p>You are given a <strong>0-indexed</strong> integer array <code>nums</code>.</p>

<p>Return <em><strong>the maximum value over all triplets of indices</strong></em> <code>(i, j, k)</code> <em>such that</em> <code>i &lt; j &lt; k</code><em>. </em>If all such triplets have a negative value, return <code>0</code>.</p>

<p>The <strong>value of a triplet of indices</strong> <code>(i, j, k)</code> is equal to <code>(nums[i] - nums[j]) * nums[k]</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [12,6,1,2,7]
<strong>Output:</strong> 77
<strong>Explanation:</strong> The value of the triplet (0, 2, 4) is (nums[0] - nums[2]) * nums[4] = 77.
It can be shown that there are no ordered triplets of indices with a value greater than 77. 
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,10,3,4,19]
<strong>Output:</strong> 133
<strong>Explanation:</strong> The value of the triplet (1, 2, 4) is (nums[1] - nums[2]) * nums[4] = 133.
It can be shown that there are no ordered triplets of indices with a value greater than 133.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong> 0
<strong>Explanation:</strong> The only ordered triplet of indices (0, 1, 2) has a negative value of (nums[0] - nums[1]) * nums[2] = -3. Hence, the answer would be 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
</ul>

# Solution

## Optimized Approach (O(n) Solution)

### **Key Observations**
We need to maximize the expression:
```
(nums[i] - nums[j]) * nums[k]
```
where `i < j < k`.

To achieve this efficiently, the algorithm maintains:
1. **`highest`** → Maximum value seen so far (`nums[i]`).
2. **`highest_diff`** → Maximum difference (`nums[i] - nums[j]`) seen so far.
3. **`answer`** → Maximum triplet value found so far.

### **Step-by-Step Execution**
1. **Iterate through each element (`num`) in `nums`.**  
   Since we traverse left to right, `num` represents `nums[k]` in some triplet.
   
2. **Compute the triplet value:**  
   We check if we can get a better result using `highest_diff * num`, which represents:
   ```
   (nums[i] - nums[j]) * nums[k]
   ```
   Update `answer` if this new value is greater.

3. **Update `highest_diff`:**  
   - `highest_diff = max(highest_diff, highest - num);`  
   - This keeps track of the best `(nums[i] - nums[j])` value.

4. **Update `highest`:**  
   - `highest = max(highest, num);`  
   - This keeps track of the maximum `nums[i]` encountered so far.

5. **After the loop ends, `answer` holds the maximum triplet value.**

---

### **Dry Run Example**
#### **Input:**  
```cpp
nums = [12, 6, 1, 2, 7]
```
#### **Iteration-wise updates**
| num  | `answer = max(answer, highest_diff * num)` | `highest_diff = max(highest_diff, highest - num)` | `highest = max(highest, num)` |
|------|-------------------------------------------|-------------------------------------------|-----------------------------|
| 12   | `0`                                       | `0`                                       | `12`                        |
| 6    | `0`                                       | `12 - 6 = 6`                              | `12`                        |
| 1    | `0`                                       | `max(6, 12 - 1) = 11`                     | `12`                        |
| 2    | `max(0, 11 * 2) = 22`                     | `max(11, 12 - 2) = 11`                    | `12`                        |
| 7    | `max(22, 11 * 7) = 77`                    | `max(11, 12 - 7) = 11`                    | `12`                        |

#### **Final Answer:** `77`

---

### **Time Complexity Analysis**
- **`O(n)`** → We iterate through `nums` only **once**, updating three variables.
- **`O(1)` Space** → No extra memory is used, only three integer variables.

---

### **Why is this approach optimal?**
✅ **No extra loops** (unlike brute force `O(n³)`).  
✅ **No need to store prefix/suffix arrays** (like `O(n)` approaches).  
✅ **Maintains only the necessary information dynamically**.
