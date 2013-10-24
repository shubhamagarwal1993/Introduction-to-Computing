#include <stdio.h>

#define N 3

int main(){

   int i,row,col;

   int a[N][N] = {
     {   1,   2,   3},
     {   0,   1,   4},
     {   5,   6,   0}};

   int b[N][N] = {
     { -24,  18,   5},
     {  20, -15,  -4},
     {  -5,   4,   1}};

   int c[N][N] = {
     {   0,   0,   0},
     {   0,   0,   0},
     {   0,   0,   0}};


   for(row=0;row<N;row++)
      for(col=0;col<N;col++)
         for(i=0;i<N;i++)
            c[row][col]+=a[row][i]*b[i][col];


   for(row=0;row<N;row++){
      for(col=0;col<N;col++)
         printf("%d ",c[row][col]);
      printf("\n");}

   return 0;
}

