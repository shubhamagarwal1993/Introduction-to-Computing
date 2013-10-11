#include <stdio.h>

int main()
{
    int readnums = 0;
    int p1,p2,p3,p4,p5,p6,total;
    int netid;
    int num = 0;
    FILE* inputfile;
    inputfile = fopen("sampledata.txt","r");
    if (inputfile==NULL)
        printf("That file ain't there \n");
    readnums = fscanf(inputfile,"%d %d %d %d %d %d %d %d\n",&p1,&p2,&p3,&p4,&p5,&p6,&total,&netid);
    while (num<279)
        {
            readnums = fscanf(inputfile,"%d %d %d %d %d %d %d %d\n",&p1,&p2,&p3,&p4,&p5,&p6,&total,&netid);
            printf("%d   %d  %d  %d  %d  %d  %d  %d\n",p1,p2,p3,p4,p5,p6,total,netid);
            num++;
        }
}
