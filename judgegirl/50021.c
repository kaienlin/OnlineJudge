#include <stdio.h>
#include "polynomial.h"

void init(Polynomial *poly, int coefficient[], int n) {
	poly->order = n - 1;
	for ( int i = 0; i < n; i++)
		poly->co[i] = coefficient[i];
}

Polynomial add(Polynomial *poly1, Polynomial *poly2) {
	int n = poly1->order > poly2->order ? poly1->order : poly2->order;
	Polynomial ret;
	int max_order = 0;
	for ( int i = 0; i <= n; i++) {
		ret.co[i] = poly1->co[i] + poly2->co[i];
		if ( ret.co[i] != 0 )
			max_order = i;
	}
	ret.order = max_order;
	return ret;
}

Polynomial multiply(Polynomial *poly1, Polynomial *poly2) {
	int n = poly1->order + poly2->order;
	Polynomial ret = {.order = n};
	for ( int i = 0; i <= n; i++)
		ret.co[i] = 0;
	for ( int i = 0; i <= poly1->order; i++)
		for ( int j = 0; j <= poly2->order; j++)
			ret.co[i+j] += poly1->co[i] * poly2->co[j];
	return ret;
}

void print(Polynomial *poly) {
	int n = poly->order;
	for ( int i = n; i >= 2; i--) {
		if ( poly->co[i] != 0 )
			printf("%+dx^%d", poly->co[i], i);
	}
	if ( poly->co[1] != 0 )
		printf("%+dx", poly->co[1]);
	if ( poly->co[0] != 0 )
		printf("%+d", poly->co[0]);
	putchar('\n');
}
