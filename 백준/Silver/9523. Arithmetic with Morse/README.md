# [Silver III] Arithmetic with Morse - 9523 

[문제 링크](https://www.acmicpc.net/problem/9523) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

자료 구조, 구현, 수학, 파싱, 스택, 문자열

### 제출 일자

2024년 11월 20일 15:08:35

### 문제 설명

<p>Morse code is a method used to transmit text messages as a series of dots “<code>.</code>” and dashes “<code>-</code>”. For example, the letter “<code>A</code>” is represented with “<code>.-</code>” and the letter “<code>B</code>” with “<code>-...</code>”. This code has been used for several years in the army and civil applications, but you are going to use it to do math.</p>

<p>With this in mind, we assign values to dots and dashes, and to save space we use two additional characters. The following table shows the four allowed characters and their values.</p>

<table class="table table-bordered" style="width:40%">
	<thead>
		<tr>
			<th>Character</th>
			<th>Value</th>
			<th> </th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td>.</td>
			<td>1</td>
			<td> </td>
		</tr>
		<tr>
			<td><code>-</code></td>
			<td>5</td>
			<td> </td>
		</tr>
		<tr>
			<td><code>:</code></td>
			<td>2</td>
			<td>(two times “<code>.</code>”)</td>
		</tr>
		<tr>
			<td><code>=</code></td>
			<td>10</td>
			<td>(two times “<code>-</code>”)</td>
		</tr>
	</tbody>
</table>

<p>A Morse number is a string that only contains the above four characters; its value is the sum of the values assigned to each individual character. As an example, the value of “<code>=.-..</code>” is 10+1+5+1+1 = 18. Notice that each Morse number represents a unique value, but there are values that can be represented with several Morse numbers. For instance, there are three Morse numbers with value 3: “<code>...</code>”, “<code>.:</code>” and “<code>:.</code>”.</p>

<p>Well, numbers are ready. To form expressions we also need operators. We consider two arithmetic operators: “<code>+</code>” represents addition, while “<code>*</code>” represents multiplication. A Morse expression is a sequence of strings that interleaves Morse numbers and operators, that starts and ends with a Morse number, and contains at least one operator. Morse expressions can be evaluated by replacing each Morse number by its value, and then evaluating the obtained mathematical expression using the common operators precedence and associativity. For example, the value of the Morse expression “<code>=.-.. + ... * :.</code>” is 18 + 3 × 3 = 18 + (3 × 3) = 27. Given a Morse expression, print its value.</p>

### 입력 

 <p>The first line contains an integer N (1 ≤ N ≤ 4) representing the number of operators in the Morse expression. The second line contains 2N + 1 non-empty strings representing the Morse expression. The line interleaves Morse numbers and operators, being the first and last strings Morse numbers. Each Morse number is at most 7 characters long, where each character is either “<code>.</code>”, “<code>-</code>”, “<code>:</code>” or “<code>=</code>”. Each operator is either “<code>+</code>” or “<code>*</code>”.</p>

### 출력 

 <p>Output a line with an integer representing the value of the Morse expression.</p>

