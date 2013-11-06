/* Risk Calculation */

#include<stdio.h>
#define N 5

int calcRisk(int YoB[], float Cholestrol[], int Risk[], int current_year);

int main()
{
int YoB[N] = {1955, 1938, 1960, 1945, 1945}; 
float Cholesterol[N] = {255.6, 200.99, 120.6, 239, 400};
int Risk[N];
int current_year = 2013;
/* call calcRisk*/
calcRisk(YoB,Cholesterol,Risk,current_year);
printf("\n Risk vector: ");
for (int i = 0; i < N; i++)
	printf(" %d ", Risk[i]); 
return 0;
}

int calcRisk(int YoB[], float Cholestrol[], int Risk[], int current_year)
{
	int i;
	int age;
	
	for (i = 0; i < N; i++)
	{
		age = (current_year - YoB[i]);
		if (age > 80)
		{
			Risk[i] = 0;
			return 0;
		}	
	
		if (Cholestrol[i] > 300 || ((age*1.2)+Cholestrol[i]) > 300)
		{
			Risk[i] = 1;
		}
		else
		{
			Risk[i] = 0;
		}
	
	}
	return 0;
}
