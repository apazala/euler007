#include <iostream>
#include <cstdint>
#include <cmath>

using namespace std;

int primesList[14000];
int numprimes;

#define LIMIT 150000

int64_t iscompound[1 + (LIMIT>>6)];

void fillprimes(int upperBound);
int main(int argc, char **argv)
{
	fillprimes(LIMIT);
	
	
	
	cout << primesList[10000] << endl;
	
    return 0;
}


#define baisset(ba, i) ((ba)[(i)>>6] & (1ull << ((i) & 63))) != 0
#define baisclear(ba, i) ((ba)[(i)>>6] & (1ull << ((i) & 63))) == 0
#define baset(ba, i) (ba)[(i)>>6] |= (1ull << ((i) & 63))

void fillprimes(int upperBound) {
	int i, j;

	baset(iscompound, 0);
	baset(iscompound, 1);
	int sqrtUb = sqrt(upperBound);
	for (i = 2; i <= sqrtUb; i++) {
		if (baisclear(iscompound, i)) {
			primesList[numprimes++] = i;
			for (j = i*i; j <= upperBound; j += i) {
				baset(iscompound, j);
			}
		}
	}

	for (i = sqrtUb + 1; i <= upperBound; i++) {
		if (baisclear(iscompound, i)) {
			primesList[numprimes++] = i;
		}
	}

}