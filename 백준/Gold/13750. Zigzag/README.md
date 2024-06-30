# [Gold V] Zigzag - 13750 

[문제 링크](https://www.acmicpc.net/problem/13750) 

### 성능 요약

메모리: 5928 KB, 시간: 4 ms

### 분류

다이나믹 프로그래밍, 그리디 알고리즘

### 제출 일자

2024년 7월 1일 08:35:43

### 문제 설명

<p>A sequence of integers is said to Zigzag if adjacent elements alternate between strictly increasing and strictly decreasing. Note that the sequence may start by either increasing or decreasing. Given a sequence of integers, determine the length of the longest subsequence that Zigzags. For example, consider this sequence:</p>

<p>1 2 3 4 2</p>

<p>There are several Zigzagging subsequences of length 3:</p>

<p>1 3 2     1 4 2     2 3 2     2 4 2     3 4 2</p>

<p>But there are none of length greater than 3, so the answer is 3.</p>

### 입력 

 <p>Each input will consist of a single test case. Note that your program may be run multiple times on different inputs. The first line of input contains an integer n (1 ≤ n ≤ 1,000,000) which is the number of integers in the list. Each of the following n lines will have an integer k (1 ≤ k ≤ 1,000,000)</p>

### 출력 

 <p>Output a single integer, which is the length of the longest Zigzagging subsequence of the input list.</p>

