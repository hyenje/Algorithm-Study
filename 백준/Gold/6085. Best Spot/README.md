# [Gold IV] Best Spot - 6085 

[문제 링크](https://www.acmicpc.net/problem/6085) 

### 성능 요약

메모리: 4068 KB, 시간: 104 ms

### 분류

플로이드–워셜, 그래프 이론, 최단 경로

### 제출 일자

2024년 11월 7일 23:46:11

### 문제 설명

<p>Bessie, always wishing to optimize her life, has realized that she really enjoys visiting F (1 <= F <= P) favorite pastures F_i of the P (1 <= P <= 500; 1 <= F_i <= P) total pastures (conveniently numbered 1..P) that compose Farmer John's holdings.</p>

<p>Bessie knows that she can navigate the C (1 <= C <= 8,000) bidirectional cowpaths (conveniently numbered 1..C) that connect various pastures to travel to any pasture on the entire farm. Associated with each path P_i is a time T_i (1 <= T_i <= 892) to traverse that path (in either direction) and two path endpoints a_i and b_i (1 <= a_i <= P; 1 <= b_i <= P).</p>

<p>Bessie wants to find the number of the best pasture to sleep in so that when she awakes, the average time to travel to any of her F favorite pastures is minimized.</p>

<p>By way of example, consider a farm laid out as the map below shows, where *'d pasture numbers are favorites. The bracketed numbers are times to traverse the cowpaths.</p>

<pre>            1*--[4]--2--[2]--3
                     |       |
                    [3]     [4]
                     |       |
                     4--[3]--5--[1]---6---[6]---7--[7]--8*
                     |       |        |         |
                    [3]     [2]      [1]       [3]
                     |       |        |         |
                    13*      9--[3]--10*--[1]--11*--[3]--12*
</pre>

<p>The following table shows distances for potential 'best place' of pastures 4, 5, 6, 7, 9, 10, 11, and 12:</p>

<pre>                       * * * * * * Favorites * * * * * *
 Potential      Pasture Pasture Pasture Pasture Pasture Pasture     Average
Best Pasture       1       8      10      11      12      13        Distance
------------      --      --      --      --      --      --      -----------
    4              7      16       5       6       9       3      46/6 = 7.67
    5             10      13       2       3       6       6      40/6 = 6.67
    6             11      12       1       2       5       7      38/6 = 6.33
    7             16       7       4       3       6      12      48/6 = 8.00
    9             12      14       3       4       7       8      48/6 = 8.00
   10             12      11       0       1       4       8      36/6 = 6.00 ** BEST
   11             13      10       1       0       3       9      36/6 = 6.00
   12             16      13       4       3       0      12      48/6 = 8.00
</pre>

<p>Thus, presuming these choices were the best ones (a program would have to check all of them somehow), the best place to sleep is pasture 10.</p>

### 입력 

 <ul>
	<li>Line 1: Three space-separated integers: P, F, and C</li>
	<li>Lines 2..F+1: Line i+2 contains a single integer: F_i</li>
	<li>Lines F+2..C+F+1: Line i+F+1 describes cowpath i with three space-separated integers: a_i, b_i, and T_i</li>
</ul>

### 출력 

 <ul>
	<li>Line 1: A single line with a single integer that is the best pasture in which to sleep. If more than one pasture is best, choose the smallest one.</li>
</ul>

