#include <stdio.h>
#include <math.h>


int print_2f(int x) {
	int a = x / 100;
	int b = x % 100;
	printf("%d.%02d", a, b);
}

int check_solution(long long a, long long b, long long c, long long d) {
	long long sum = (a + b + c + d);
	long long prod = (a * b * c * d);
	if (sum <= 2000 && prod == sum * 1000000) {
		print_2f(a);
		printf(" ");
		print_2f(b);
		printf(" ");
		print_2f(c);
		printf(" ");
		print_2f(d);
		printf("\n");
	}
}

int calculate_d(int a, int b, int c) {
	return (1000000 * (a+b+c)) / (a*b*c - 1000000);
}

int main() {
	int a, b, c, d;
	int a_limit = pow(20e8, 1.0/4);
	for (a = 1; a <= a_limit; ++a) {
		int b_limit = pow(20e8 / a, 1.0/3);
		for (b = a; b <= b_limit; ++b) {
			int c_limit = pow(20e8 / (a*b), 1.0/2);
			for (c = b; c <= c_limit; ++c) {
				if (a * b * c > 1000000) {
					d = calculate_d(a, b, c);
					if (d >= c) {
						check_solution(a, b, c, d);
					}
				}
			}
		}
	}

	return 0;
}