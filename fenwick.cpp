#include <bits/stdc++.h>
#define FIN "aib.in"
#define FOUT "aib.out"

using namespace std;

int N, M, fen[ 100005 ];

void update(int x, int val) {

     for( ;x<=N; x+=x^(x-1)&x) {

          fen[x] += val;
     }
}

int query(int x) {

    int ans;

    for(ans = 0; x; x-=x^(x-1)&x) {

        ans += fen[x];
    }
    return ans;
}

int search(int x) {

    int log, index;

    for(log = 1; log < N; log <<= 1);

    for(index = 0; log; log>>=1) {

        if(index+log<=N && fen[index+log]<=x)

           index += log, x-=fen[index];
    }

    return (!x ? index : -1);
}

int main(void)
{
    int i, v, tip, a, b;

    freopen(FIN, "r", stdin);
    //freopen(FOUT, "w", stdout);

    scanf("%d %d", &N, &M);

    for(int i = 1; i <= N; ++i) {
        cin>>v;
        update(i,v);
    }

    for( ; M; M--) {

      cin>>tip;

      if(tip == 0) {

        cin>>a>>b;
        update(a,b);

      } else if(tip == 1) {

        cin>>a>>b;

        cout<<query(b)-query(a-1)<<endl;

      } else if(tip == 2) {

        cin>>a;

        printf("%d\n", (!a ? -1 : search(a)));
      }
    }
}
