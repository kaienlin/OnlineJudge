#include <stdio.h>

int main()
{
	int N;
	scanf("%d", &N);
	char filename[16];
	FILE *fin[16];
	for ( int i = 0; i < N; i++) {
		scanf("%s", filename);
		fin[i] = fopen(filename, "rb");
	}
	int num[16], done = 0;
	for ( int i = 0; i < N; i++)
		fread(&num[i], sizeof(int), 1, fin[i]);
	while (1) {
		int min = __INT_MAX__, min_idx = -1;
		for ( int i = 0; i < N; i++) {
			if ( num[i] < min ) {
				min = num[i];
				min_idx = i;
			}
		}
		printf("%d\n", min);
		int f = fread(&num[min_idx], sizeof(int), 1, fin[min_idx]);
		if ( f == 0 ) {
			num[min_idx] = __INT_MAX__;
			done++;
		}
		if ( done == N )
			break;
	}
	return 0;
}
