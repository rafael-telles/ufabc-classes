#include <stdlib.h>
#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	while (n-- > 0) {
		char linha[50];
		scanf("%s", linha);

        int offset;
        scanf("%d", &offset);

        int i;
        for (i = 0; i < 50; i++) {
        	if (linha[i] == '\0' || linha[i] == '\n') {
				linha[i] = '\0';
        		break;
        	}
        	linha[i] -= offset;
        	if (linha[i] < 'A') {
        		linha[i] += 26;
        	}
        	printf("%c", linha[i]);
        }
        printf("\n");
	}
}