#include <stdio.h>
#include <stdlib.h>

int dfs(int i, int N, int* adj, int* color, int c) {
	color[i] = c;
	
	int j;
	for (j = 0; j < N; j++) {
		if (adj[i*N + j] == 0) {
			if (color[j] == -1) {
				if (!dfs(j, N, adj, color, 1 - c)) {
					return 0;
				}
			} else if (color[j] == c) {
				return 0;
			}
		}
	}
	return 1;
}

int bipartido(int N, int* adj) {
	int color[N];
	int i;

	for (i = 0; i < N; i++) {
		color[i] = -1;
	}
	for (i = 0; i < N; i++) {
		if (color[i] == -1) {
			if (dfs(i, N, adj, color, 0)) {
				return 0;
			}
		}
	}
	return 1;
}

int main() {

	int N;
	scanf("%d", &N);

	int adj[N][N];
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			scanf("%d", &(adj[i][j]));
		}
	}

	if (bipartido(N, adj)) {
		printf("Fail!\n");
	} else {
		printf("Bazinga!\n");
	}


	return 0;
}