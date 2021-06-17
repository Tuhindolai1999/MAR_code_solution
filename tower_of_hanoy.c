#include<stdio.h>
void toh(int,char,char,char);
int main()
{
   int num;
   printf("Enter the number of the disk:");
   scanf("%d",&num);
   printf("\nThe sequence of moves in the tower of hanoi are:");
   toh(num,'A','C','B');
   return 0;
}
void toh(int num,char frompeg,char topeg,char auxpeg)
{
    if(num==1)
    {
        printf("\nmove 1 disk from %c peg to %c peg\n",frompeg,topeg);
        return;
    }
    toh(num-1,frompeg,auxpeg,topeg);
    printf("Move %d disk from %c peg to %c peg",num,frompeg,topeg);
    toh(num-1,auxpeg,topeg,frompeg);
}
