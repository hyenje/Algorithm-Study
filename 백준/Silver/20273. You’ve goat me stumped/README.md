# [Silver III] You’ve goat me stumped - 20273 

[문제 링크](https://www.acmicpc.net/problem/20273) 

### 성능 요약

메모리: 2032 KB, 시간: 0 ms

### 분류

기하학, 수학

### 제출 일자

2024년 11월 11일 23:56:28

### 문제 설명

<p>When leaving goats to graze in a field, in order to ensure that they remain in place, it is customary to drive a wooden stake in the middle of the field and tether the goat to it to ensure that it does not run away. This allows the goat to roam within a disk-shaped pasture.</p>

<p>In the far region of Straitmeadows, the fields are long and narrow. This odd geometry has led to an even more peculiar habit of the shepherds. They put a collar on the goat and pass a rope through it (so that the rope can move freely), and they then tie each end of the rope to a stake. This allows the goat to move along the rope but remain sufficiently close to the two stakes.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 333px; height: 138px;"></p>

<p>To ensure the goat doesn't starve, the shepherds need to know (very roughly) which area of grass the goat can graze in this fashion. You will assume that the goat and the stakes are 0-dimensional objects, that the rope is 1-dimensional, and that the field is a plane.</p>

### 입력 

 <p>The input file consists of multiple test cases. The first line of the input file consists of a single integer $c$ indicating the number of test cases. Each test case follows and consists of a single line which consists of two integers $\ell$ and $r$ separated by a single space. The integer $0 \leq \ell \leq 30$ indicates the distance between the two stakes in meters. The integer $\ell \leq r \leq 50$ indicates the length of the rope in meters. </p>

### 출력 

 <p>For each test case in the input, your program should produce one line consisting of a single integer which is the area of pasture that the goat can graze, rounded to the nearest hundred of square meters.</p>

