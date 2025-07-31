# [Gold II] Key Knocking - 13955 

[문제 링크](https://www.acmicpc.net/problem/13955) 

### 성능 요약

메모리: 3776 KB, 시간: 16 ms

### 분류

많은 조건 분기, 해 구성하기

### 제출 일자

2025년 8월 1일 02:51:04

### 문제 설명

<p>Goran is recovering from his knee surgery and is experimenting with a smart card used for storing cryptographic keys. In this problem, a key is a bitstring of size 3n where n is a positive integer. Particular bits of the key are indexed with integers 1 through 3n left to right. Weight of a key is the number of pairs of different neighbouring bits increased by one. For example, the weight of the key “000” is 1, while the weight of the key “011010100” is 7.</p>

<p>He has discovered that he can tamper with the key by sending small jolts of electricity through the circuits of the smart card. In particular, he can reliably perform the following operation: pick two arbitrary neighbouring bits of the key and flip both of them. For example, one operation can change the key “000” to “110”.</p>

<p>Given a key of size 3n find any sequence of at most n operations that transforms the given key to a key of weight at least 2n. You may assume that a solution always exists.</p>

### 입력 

 <p>The first line contains a string consisting of digits “0” and “1” — the initial key. The length of the key is 3n where n is a positive integer such that 1 ≤ n ≤ 100 000.</p>

### 출력 

 <p>The first line should contain an integer m where 0 ≤ m ≤ n — the number of operations in your solution. The following line should contain m integers a<sub>1</sub>, a<sub>2</sub>, . . . , a<sub>m</sub> describing your solution. The number a<sub>k</sub> is the index of the left one of two bits being flipped in the k-th step.</p>

<p>If the initial key already has weight at least 2n you may output only the integer 0.</p>

