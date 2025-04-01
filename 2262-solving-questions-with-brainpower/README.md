<h2><a href="https://leetcode.com/problems/solving-questions-with-brainpower">2262. Solving Questions With Brainpower</a></h2><h3>Medium</h3><hr><p>You are given a <strong>0-indexed</strong> 2D integer array <code>questions</code> where <code>questions[i] = [points<sub>i</sub>, brainpower<sub>i</sub>]</code>.</p>

<p>The array describes the questions of an exam, where you have to process the questions <strong>in order</strong> (i.e., starting from question <code>0</code>) and make a decision whether to <strong>solve</strong> or <strong>skip</strong> each question. Solving question <code>i</code> will <strong>earn</strong> you <code>points<sub>i</sub></code> points but you will be <strong>unable</strong> to solve each of the next <code>brainpower<sub>i</sub></code> questions. If you skip question <code>i</code>, you get to make the decision on the next question.</p>

<ul>
	<li>For example, given <code>questions = [[3, 2], [4, 3], [4, 4], [2, 5]]</code>:

	<ul>
		<li>If question <code>0</code> is solved, you will earn <code>3</code> points but you will be unable to solve questions <code>1</code> and <code>2</code>.</li>
		<li>If instead, question <code>0</code> is skipped and question <code>1</code> is solved, you will earn <code>4</code> points but you will be unable to solve questions <code>2</code> and <code>3</code>.</li>
	</ul>
	</li>
</ul>

<p>Return <em>the <strong>maximum</strong> points you can earn for the exam</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> questions = [[3,2],[4,3],[4,4],[2,5]]
<strong>Output:</strong> 5
<strong>Explanation:</strong> The maximum points can be earned by solving questions 0 and 3.
- Solve question 0: Earn 3 points, will be unable to solve the next 2 questions
- Unable to solve questions 1 and 2
- Solve question 3: Earn 2 points
Total points earned: 3 + 2 = 5. There is no other way to earn 5 or more points.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> questions = [[1,1],[2,2],[3,3],[4,4],[5,5]]
<strong>Output:</strong> 7
<strong>Explanation:</strong> The maximum points can be earned by solving questions 1 and 4.
- Skip question 0
- Solve question 1: Earn 2 points, will be unable to solve the next 2 questions
- Unable to solve questions 2 and 3
- Solve question 4: Earn 5 points
Total points earned: 2 + 5 = 7. There is no other way to earn 7 or more points.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= questions.length &lt;= 10<sup>5</sup></code></li>
	<li><code>questions[i].length == 2</code></li>
	<li><code>1 &lt;= points<sub>i</sub>, brainpower<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
</ul>

# Solution

# Most Points from Questions

## Approach

### 1. Understanding the Choices
At each question `i`, you have two options:
- **Solve it**: Earn points and move to the next valid question after skipping `brainpower[i]` questions.
- **Skip it**: Move to the next question without earning any points.

### 2. Using Dynamic Programming (DP)
We use a DP array `dp` where `dp[i]` represents the **maximum points you can earn starting from question `i`**.

### 3. Solving from the End
- We start from the last question and move backward to question `0`.
- If we solve question `i`, we add its points and jump to the next valid question.
- If we skip question `i`, we just take the maximum points from the next question.
- We store the maximum of both choices in `dp[i]`.

### 4. Time Complexity
- We go through the list once, making it **O(n) time complexity**.
- We use an extra `dp` array, making it **O(n) space complexity**.

## Example Walkthrough
### Input
```
questions = [[3,2],[4,3],[4,4],[2,5]]
```
### Steps
1. Solve question 0 → Earn 3 points, skip next 2 questions
2. Solve question 3 → Earn 2 points
3. Total = `3 + 2 = 5`

### Output
```
5
```


