#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

typedef struct hmm {
	double x, y, r;
}st;

int main() {

	int t; scanf("%d", &t);
	st a, b;
	double distance;

while (t--) {
	scanf("%lf %lf %lf", &a.x, &a.y, &a.r);
	scanf("%lf %lf %lf", &b.x, &b.y, &b.r);

	distance = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
	if (a.x == b.x && a.y == b.y && a.r == b.r)
		printf("-1\n");
	else if (distance > a.r + b.r || distance + b.r < a.r || distance + a.r < b.r)
		printf("0\n");
	else if (distance == a.r + b.r || distance + a.r == b.r || distance + b.r == a.r)
		printf("1\n");
	else
		printf("2\n");
}

	return 0;
}