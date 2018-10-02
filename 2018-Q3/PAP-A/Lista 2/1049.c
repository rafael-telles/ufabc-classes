#include <stdlib.h>
#include <stdio.h>

int main() {
    char buf1[128];
    char buf2[128];
    char buf3[128];

    fgets(buf1, 128, stdin);
    fgets(buf2, 128, stdin);
    fgets(buf3, 128, stdin);
    if (strcmp(buf1, "vertebrado\n") == 0) {
        if (strcmp(buf2, "ave\n") == 0) {
            if (strcmp(buf3, "carnivoro\n") == 0) {
                printf("aguia\n");
            } else if (strcmp(buf3, "onivoro\n") == 0) {
                printf("pomba\n");
            }
        } else if (strcmp(buf2, "mamifero\n") == 0) {
            if (strcmp(buf3, "onivoro\n") == 0) {
                printf("homem\n");
            } else if (strcmp(buf3, "herbivoro\n") == 0) {
                printf("vaca\n");
            }
        }
    } else if (strcmp(buf1, "invertebrado\n") == 0) {
        if (strcmp(buf2, "inseto\n") == 0) {
            if (strcmp(buf3, "hematofago\n") == 0) {
                printf("pulga\n");
            } else if (strcmp(buf3, "herbivoro\n") == 0) {
                printf("lagarta\n");
            }
        } else if (strcmp(buf2, "anelideo\n") == 0) {
            if (strcmp(buf3, "hematofago\n") == 0) {
                printf("sanguessuga\n");
            } else if (strcmp(buf3, "onivoro\n") == 0) {
                printf("minhoca\n");
            }
        }
    }

	return 0;
}