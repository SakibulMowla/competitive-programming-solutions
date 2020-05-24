#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAXN 10

typedef struct Board Board;
struct Board {
   int n;
   char b[MAXN][MAXN];
};

/* rotate 90 degree clockwise: [r, c] -> [c, n+1 - r] */
Board
rotate(Board b)
{
   Board nb;
   int r, c;

   nb = b;
   for(r=0; r<b.n; r++)
   for(c=0; c<b.n; c++)
       nb.b[c][b.n+1 - r] = b.b[r][c];

   return nb;
}

/* reflect board horizontally: [r, c] -> [r, n-1 -c] */
Board
reflect(Board b)
{
   Board nb;
   int r, c;

   nb = b;
   for(r=0; r<b.n; r++)
   for(c=0; c<b.n; c++)
       nb.b[r][b.n-1 - c] = b.b[r][c];

   return nb;
}

/* return non-zero if and only if boards are equal */
int
eqboard(Board b, Board bb)
{
   int r, c;

   if(b.n != bb.n)
       return 0;

   for(r=0; r<b.n; r++)
   for(c=0; c<b.n; c++)
       if(b.b[r][c] != bb.b[r][c])
           return 0;
   return 1;
}

Board
rdboard(int n)
{
   Board b;
   int r, c;

   b.n = n;
   for(r=0; r<n; r++) {
       for(c=0; c<n; c++)
           scanf(" %c",&b.b[r][c]);
//       assert(getc(fin) == '\n');
   }
   return b;
}

 main(void)
{
//   FILE *fin, *fout;
   Board b, nb;
   int n, change;

//   fin = fopen("transform.in", "r");
//   fout = fopen("transform.out", "w");
//   assert(fin != NULL && fout != NULL);

   scanf("%d\n", &n);
   b = rdboard(n);
   nb = rdboard(n);

   if(eqboard(nb, rotate(b)))
       change = 1;
   else if(eqboard(nb, rotate(rotate(b))))
       change = 2;
   else if(eqboard(nb, rotate(rotate(rotate(b)))))
       change = 3;
   else if(eqboard(nb, reflect(b)))
       change = 4;
   else if(eqboard(nb, rotate(reflect(b)))
        || eqboard(nb, rotate(rotate(reflect(b))))
        || eqboard(nb, rotate(rotate(rotate(reflect(b))))))
       change = 5;
   else if(eqboard(nb, b))
       change = 6;
   else
       change = 7;

   printf("%d\n", change);

//   exit(0);
}
