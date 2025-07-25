# [Gold V] Hike on a Graph - 6573 

[문제 링크](https://www.acmicpc.net/problem/6573) 

### 성능 요약

메모리: 3352 KB, 시간: 28 ms

### 분류

너비 우선 탐색, 그래프 이론, 그래프 탐색

### 제출 일자

2025년 7월 25일 23:55:45

### 문제 설명

<p>"Hike on a Graph" is a game that is played on a board on which an undirected graph is drawn. The graph is complete and has all loops, i.e. for any two locations there is exactly one arrow between them. The arrows are coloured. There are three players, and each of them has a piece. At the beginning of the game, the three pieces are in fixed locations on the graph. In turn, the players may do a move. A move consists of moving one's own piece along an arrow to a new location on the board. The following constraint is imposed on this: the piece may only be moved along arrows of the same colour as the arrow between the two opponents' pieces.</p>

<p>In the sixties ("make love not war") a one-person variant of the game emerged. In this variant one person moves all the three pieces, not necessarily one after the other, but of course only one at a time. Goal of this game is to get all pieces onto the same location, using as few moves as possible. Find out the smallest number of moves that is necessary to get all three pieces onto the same location, for a given board layout and starting positions.</p>

### 입력 

 <p>The input file contains several test cases. Each test case starts with the number <em>n</em>. Input is terminated by <em>n=0</em>. Otherwise, <em>1<=n<=50</em>. Then follow three integers <em>p<sub>1</sub>, p<sub>2</sub>, p<sub>3</sub></em> with <em>1<=p<sub>i</sub><=n</em> denoting the starting locations of the game pieces. The colours of the arrows are given next as a <em>m×m</em> matrix of whitespace-separated lower-case letters. The element <em>m<sub>ij</sub></em> denotes the colour of the arrow between the locations <em>i</em> and <em>j</em>. Since the graph is undirected, you can assume the matrix to be symmetrical.</p>

### 출력 

 <p>For each test case output on a single line the minimum number of moves required to get all three pieces onto the same location, or the word "impossible" if that is not possible for the given board and starting locations.</p>

