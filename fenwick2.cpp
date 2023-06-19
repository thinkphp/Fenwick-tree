#include <stdio.h>

#define NX 100010

int T[ NX ], N, M, LogN;

void upd( int x, int y ) {
	for( ; x <= N; x += x & -x )
		T[x] += y;
}

int query( int x ) {
	int res = 0;
	for( ; x; x-= x & -x )
		res += T[x];
	return res;
}

int src( int x ) {
	int i, sum, step;

	sum = x;
	for( i = 0, step = LogN; step; step >>= 1 )
		if( (i+step <= N) && T[i+step] < x )
			i += step, x -= T[i];

	return ( query(i+1) == sum) ? i+1 : -1;

}

void cit() {
	int i, x, y, op;
	
	scanf( "%d%d", &N, &M );

	for( i = 1; i <= N; i++ ) {
		scanf( "%d", &x );
		upd( i, x );
	}

	for( LogN = 1; LogN <= N; LogN <<= 1 );
	LogN >>= 1;

	while( M-- ) {
		scanf( "%d", &op );
		switch( op ) {
			case 0: scanf( "%d%d", &x, &y ); upd( x, y ); break;
			case 1: scanf( "%d%d", &x, &y ); printf( "%d\n", query( y ) - query( x-1 ) ); break;
			case 2: scanf( "%d", &x ); printf( "%d\n", src( x ) ); break;
		}
	}
}

int main() {
	freopen( "aib.in", "r", stdin );
	freopen( "aib.out", "w", stdout );

	cit();

	return 0;
}
