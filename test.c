#include <stdio.h>

enum state {
	real,
	fake
};

int main() {
	int a, b;
	 a = 2;
	 b = 3;

	if((a + b) == 5) {
		printf("%d\n", real);
	}
	return 0;
}
