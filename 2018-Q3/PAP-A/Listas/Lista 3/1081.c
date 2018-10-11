#include <stdio.h>
#include <stdlib.h>

int print_indent(int depth) {
	int i;
	for (i = 0; i < depth; i++) {
		printf("  ");
	}
}

int dfs(int depth, int nv, int v, int* adj, int* visited) {
	visited[v] = 1;

	int i;
	int ret = 0;
	for (i = 0; i < nv; i++) {
		if (adj[v*nv + i]) {
			ret = 1;
			adj[v*nv + i] = 0;
			print_indent(depth);
			if (visited[i]) {
				printf("%d-%d\n", v, i);
			} else {
				printf("%d-%d pathR(G,%d)\n", v, i, i);
				dfs(depth + 1, nv, i, adj, visited);
				visited[i] = 1;
			}
		}
	}

	return ret;
}

int main() {
	int n;
	scanf("%d", &n);

	int case_n;
	for(case_n = 1; case_n <= n; case_n++) {
		printf("Caso %d:\n", case_n);
		int nv, ne;
		scanf("%d %d\n", &nv, &ne);

		int adj[nv*nv];
		int i;
		for (i = 0; i < nv*nv; i++) {
			adj[i] = 0;
		}
		int visited[nv];
		for (i = 0; i < nv; i++) {
			visited[i] = 0;
		}

		int v1, v2;		
		while (ne-- > 0) {
			scanf("%d %d\n", &v1, &v2);
			adj[v1 * nv + v2] = 1;
		}

		for (i = 0; i < nv; i++) {
			if(dfs(1, nv, i, adj, visited)) {
				printf("\n");
			}
		}
	}
}