#include<stdio.h>

int matrix[100][100];

int main()
{
int size,source,destination, number_of_edges;
int i,j;
printf("Enter number of vertices\n");
scanf("%d",&size);
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
			{
				matrix[i][j]=0;
			}
	}

printf("Enter number of edges\n");
scanf("%d",&number_of_edges);
	for(i=0;i<number_of_edges;i++)
	{
		printf("Enter source and destination\n");
		scanf("%d%d",&source,&destination);
		matrix[source][destination]=1;
	}


for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
			{
				printf("%d",matrix[i][j]);
			}
		printf("\n");
	}

}