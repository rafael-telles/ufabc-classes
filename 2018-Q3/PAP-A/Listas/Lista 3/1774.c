#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int getMinIndex(int *mstKeys, int *mstSet, int n) {
	int min = INT_MAX;
	int minIndex = -1;
	while (--n >= 0) {
		if (mstKeys[n] <= min && mstSet[n] == 0) {
			min = mstKeys[n];
			minIndex = n;
		}
	}

	return minIndex;
}

int main() {
	int nV, nE;
	scanf("%d %d", &nV, &nE);

	int adj[nV][nV];

	int i, j, k;
	for (i = 0; i < nV; i++) {
		for (j = 0; j < nV; j++) {
			adj[i][j] = INT_MAX;
		}
	}

	int p;
	for (k = 0; k < nE; k++) {
		scanf("%d %d %d", &i, &j, &p);
		adj[i - 1][j - 1] = p;
		adj[j - 1][i - 1] = p;
	}

	int mstCount = 0;
	int mstSet[nV];
	int mstKeys[nV];
	for (i = 0; i < nV; i++) {
		mstSet[i] = 0;
		mstKeys[i] = INT_MAX;
	}

	mstKeys[0] = 0;
	while (mstCount < nV) {
		int minIndex = getMinIndex(mstKeys, mstSet, nV);
		mstSet[minIndex] = 1;
		mstCount++;

		for (i = 0; i < nV; i++) {
			if (adj[minIndex][i] < mstKeys[i] && mstSet[i] == 0) {
				mstKeys[i] = adj[minIndex][i];
			}
		}
	}

	int r = 0;
	for (i = 0; i < nV; i++) {
		r += mstKeys[i];
	}
	printf("%d\n", r);

	return 0;
}