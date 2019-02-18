#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXM 101
#define MAXN 100

void readMatrix(int n, int m, double matrix[][MAXM]) {
	for ( int i = 0; i < n; i++)
		for ( int j = 0; j <= m; j++)
			scanf("%lf", &matrix[i][j]);
}

void printMatrix(int n, int m, double matrix[][MAXM]) {
	for ( int i = 0; i < n; i++)
		for ( int j = 0; j <= m; j++)
			printf("%f%c", matrix[i][j], " \n"[j == m]);
}

void readTarget(int m, double target[]) {
	for ( int i = 0; i < m; i++)
		scanf("%lf", &target[i]);
}

int findPivotRow(int row_n, int begin, int col, double matrix[][MAXM]) {
	for ( int i = begin; i < row_n; i++)
		if ( matrix[i][col] != 0.0 )
			return i;
	return -1;
}

void swapRow(int idx_1, int idx_2, int m, double matrix[][MAXM]) {
	for ( int i = 0; i <= m; i++) {
		double tmp = matrix[idx_1][i];
		matrix[idx_1][i] = matrix[idx_2][i];
		matrix[idx_2][i] = tmp;
	}
}

void alter(double *x) {
	*x = *x * 1000 / 1000;
}

int eliminate(int n, int m, double matrix[][MAXM]) {
	for ( int i = 0; i < n - 1 && i < m - 1; i++) {
		int targetCol = i;
		int pivotRow = findPivotRow(n, i, targetCol, matrix);
		if ( pivotRow == -1 ) {
			continue; // all elems in this col is zero
		}
		if ( i != pivotRow ) // ensure the pivot(i-th row) != 0.0
			swapRow(i, pivotRow, m, matrix);
		double pivot = matrix[i][targetCol];
		for ( int j = i + 1; j < n; j++) { // for all rows under pivotRow
			double multiplier = matrix[j][targetCol] / pivot;
			int zero_cnt = 0;
			for ( int k = targetCol; k <= m; k++) { // for all rest columns in this row
				matrix[j][k] -= matrix[i][k] * multiplier;
				alter(&matrix[j][k]);
				if ( k != i && k != m )
					zero_cnt += (matrix[j][k] == 0.0);
			}
			// printMatrix(n, m, matrix);
			// puts("");
			// printf("zero count: %d\n", zero_cnt);
			if ( zero_cnt == m - targetCol - 1 ) { // not sure || contradictory
				if ( matrix[j][m] != 0.0 )
					return -1; // contradictory
			}
		}	
	}
	return 0;
}

int canSolve(int m, double row[]) {
	int nonzero_cnt = 0, idx = 0;
	for ( int i = 0; i < m; i++) {
		if ( row[i] != 0.0 ) {
			nonzero_cnt++;
			idx = i;
		}
	}
	if ( nonzero_cnt != 1 ) {
		if ( nonzero_cnt == 0 && row[m] != 0.0 )
			return -1;
		else
			return -2;
	} else {
		return idx;
	}
}

int backSubstitution(int n, int m, double matrix[][MAXM], double ans[]) {
	for ( int i = n - 1; i >= 0; i--) {
		int rowStat = canSolve(m, matrix[i]);
		if ( rowStat == -1 )
			return -1; // contradictory
		else if ( rowStat == -2 )
			continue; // still have possibility to be solved
		ans[rowStat] = matrix[i][m] / matrix[i][rowStat];
		for ( int j = i - 1; j >= 0; j--) {
			double multiplier = matrix[j][rowStat] / matrix[i][rowStat];
			matrix[j][rowStat] = 0.0;
			matrix[j][m] -= matrix[i][m] * multiplier;
		}
	}
	return 0;
}

int printAns(int m, double ans[], double t[]) {
	for ( int i = 0; i < m; i++) {
		if ( ans[i] == __DBL_MAX__ )
			printf("null ");
		else
			printf("%f ", ans[i]);
	}
	puts("");
	double out = 0.0;
	for ( int i = 0; i < m; i++) {
		if ( t[i] != 0.0 ) {
			if ( ans[i] != __DBL_MAX__ )
				out += ans[i];
			else
				return -2;
		}
	}
	printf("%d\n", (int)round(out));
	return 0;
}

int main()
{
	int n, m;
	double matrix[MAXN][MAXM] = {0.0};
	double target[MAXM] = {0.0};
	while ( scanf("%d %d", &n, &m) != EOF ) {
		readMatrix(n, m, matrix);
		readTarget(m, target);
		int eli_stat = eliminate(n, m, matrix);
		printMatrix(n, m, matrix);
		if ( eli_stat == -1 ) {
			puts("contradictory");
			continue;
		}
		double ans[MAXM];
		for ( int i = 0; i < m; i++)
			ans[i] = __DBL_MAX__;
		int backSub_stat = backSubstitution(n, m, matrix, ans);
		if ( backSub_stat == -1 ) {
			puts("contradictory");
			continue;
		} else if ( backSub_stat == -2 ) {
			puts("not sure");
			continue;
		}
		if ( printAns(m, ans, target) != 0 )
			puts("not sure");
	}
	return 0;
}
