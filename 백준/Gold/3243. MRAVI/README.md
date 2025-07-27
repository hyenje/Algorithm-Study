# [Gold IV] MRAVI - 3243 

[문제 링크](https://www.acmicpc.net/problem/3243) 

### 성능 요약

메모리: 3080 KB, 시간: 36 ms

### 분류

애드 혹

### 제출 일자

2025년 7월 27일 16:25:48

### 문제 설명

<p>One of most valued jobs in ant population is traffic officer. The reason is narrow tunnels of ant hole in which ants who go in opposite directions can’t pass near each other. Luckily, in the tunnel there are some spots where ant can stand and let other ants pass. Ants can pass each other at both exits of the tunnel without a problem.</p>

<p>Traffic officer knows the length of the tunnel as well as locations of every spots. Every morning he receives the list of arrival times of every ant to each tunnel exit. His mission is to organize traffic and enable all ants to pass the tunnel. That, of course, can be achieved in different (faster or slower) ways, but in that time, when last ant passes the tunnel, our friend ends his shift, so it’s crucial for him to make them pass as quickly as possible. Speed of every ant is 1 cm/s. In one spot there can be any number of ants and we can ignore length</p>

<p>of ants and width of spots as well. Write the program that calculates minimum time when all ants will pass the tunnel. </p>

### 입력 

 <p>In the first line of input file there are integers D and U, between which is single space, 1 ≤ D ≤ 1,000,000, 1 ≤ U ≤ 100,000, D > U, D is the length of the tunnel in cm, and U is the number of spots. In next U lines there are locations of spots from left to right in increasing sequence.</p>

<p>In next line there is integer L, 1 ≤ L ≤ 100,000, number of ants that come to left side of the tunnel. In next L lines there are arrival times of every ant to left side of the tunnel (the numbers are less or equal to 2,000,000).</p>

<p>In next line there is integer R, 1 ≤ R ≤ 100,000, number of ants that come to right side of the tunnel. In next L lines there are arrival times of every ant to right side of the tunnel (the numbers are less or equal to 2,000,000). </p>

### 출력 

 <p>In only line of output file you should print the number from the text of the problem.</p>

