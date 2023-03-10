#include <stdio.h>
#define N 3

struct student
{
	int NO;
	char name[20];
	float score1;
	float score2;
	float score3;
	float average;
};

int main()
{
	struct student stu[N];
	int i = 0;
	for (i = 0; i < N; i++)
	{
		scanf("%d%s%f%f%f",&stu[i].NO,&stu[i].name, &stu[i].score1, &stu[i].score2, &stu[i].score3);
	}
	printf("\nNO\t\tname\t\tscore1\t\tscore2\t\tscore3\t\taverage\n");
	float sum2=0.0;
	for (i = 0; i < N; i++)
	{
	    float sum1 ;
		sum1 = stu[i].score1 + stu[i].score2 + stu[i].score3;
		stu[i].average = sum1 / N;
		printf("\n%d\t\t%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f", stu[i].NO, stu[i].name, stu[i].score1, stu[i].score2, stu[i].score3, stu[i].average);
        sum2+=stu[i].average;
	}

    float k=0.0;
    k=sum2/N;
    printf("\naverage=%.2f",k);

	int max=0;
	int j=0;
	int n=0;
	for(j=0;j<N;j++)
    {
        if(stu[j].average>max)
        {
            max=stu[j].average;
            n=j;
        }

    }
    printf("\nThe highest score is : student %d,%s\n",stu[n].NO,stu[n].name);
    printf("his scores are:%d,%s,%.2f,%.2f,%.2f,average:%.2f",stu[n].NO,stu[n].name, stu[n].score1, stu[n].score2, stu[n].score3,stu[n].average);

	return 0;
}
