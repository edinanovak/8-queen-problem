#include <stdio.h>
#define N 8
int k=0;
void printSol(int board[N][N])
{
  int i,j;
  k++;
  printf("-%d\n",k);
  for(i=0;i<N;i++)
    {
      for(j=0;j<N;j++)
	printf("%d ",board[i][j]);
      printf("\n");
    }
}
int isSafe(int board[N][N],int r,int c)
{
  int i,j;
  
  for(i=0;i<N;i++)
    if(board[i][c]==1)
      return 0;

  for(j=0;j<N;j++)
    if(board[r][j]==1)
      return 0;

  for(i=r,j=c;j>=0 && i<N;i++,j--)
    if(board[i][j]==1)
      return 0;

  for(i=r,j=c;j<N && i>=0;i--,j++)
    if(board[i][j]==1)
      return 0;

  for(i=r,j=c;j<N && i<N;i++,j++)
    if(board[i][j]==1)
      return 0;

  for(i=r,j=c;i>=0 && j>=0;i--,j--)
    if(board[i][j]==1)
      return 0;

  return 1;
}

int solve(int board[N][N],int c)
{
  if(c==N)
    {
      printSol(board);
    return 1;
    }

  int i,check=0;

  for(i=0;i<N;i++)
    if(isSafe(board,i,c))
      {
	board[i][c]=1;
	
	if(solve(board,c+1)==1)
	  check=1;

	board[i][c]=0;
      }
  return check;
}

int solutionQ()
{
  int board[N][N];
  int i,j;
  for(i=0;i<N;i++)
    for(j=0;j<N;j++)
      board[i][j]=0;

  if(solve(board,0)==0)
    { printf("No solutions found!");
      return 0;}

  return 1;
}

int main()
{
  solutionQ();
  return 0;
}
