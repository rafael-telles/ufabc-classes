#include <stdio.h>
#include <stdlib.h>

int find_component(int v, int V, int *adj, int* missing, int marker) {
	if (missing[v] != -1) return 0;
	
	missing[v] = marker;

	int i;
	for (i = 0; i < V; i++) {
		if (adj[v*V + i]) {
			find_component(i, V, adj, missing, marker);
		}
	}
}
int print_m(int V, int* missing) {
	int i;
	printf("MISSING: ");
	for (i = 0; i < V; i++) {
		printf("%d,", missing[i]);
	}
	printf("\n");
}

int main() {
	int n;
	scanf("%d", &n);

	int case_n;
	for(case_n = 1; case_n <= n; case_n++) {
		printf("Case #%d:\n", case_n);
		int V, E;
		scanf("%d %d\n", &V, &E);

		int adj[V][V];
		int v1, v2;
		for (v1 = 0; v1 < V; v1++) {
			for (v2 = 0; v2 < V; v2++) {
				adj[v1][v2] = 0;
			}
		}

		while (E-- > 0) {
			scanf("%lc %lc\n", &v1, &v2);
			adj[v1 - 'a'][v2 - 'a'] = 1;
			adj[v2 - 'a'][v1 - 'a'] = 1;
		}

		for (v1 = 0; v1 < V; v1++) {
			adj[v1][v1] = 1;
		}

		int missing[V];
		for (v1 = 0; v1 < V; v1++) {
			missing[v1] = -1;
		}

		int component_count = 0;
		for (v1 = 0; v1 < V; v1++) {
			if (missing[v1] != -1) continue;
			component_count++;
			find_component(v1, V, adj, missing, v1);
			for (v2 = 0; v2 < V; v2++) {
				if (missing[v2] == v1) {
					printf("%c,", 'a' + v2);
				}
			}
			printf("\n");
		}

		printf("%d connected components\n\n", component_count);
	}
}