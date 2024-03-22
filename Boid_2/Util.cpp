#include "Util.h"
#include <stdlib.h>

int tirage(int n) {
	return rand() % n;
}

int tirage(int i, int j) {
	int a = tirage(j);
	while ((a < i) || (a > j)) {
		a = tirage(j);
	}
	return a;
}