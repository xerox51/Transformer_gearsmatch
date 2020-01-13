#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,m;
	float **a,**b;;
	printf("please input the gears of #1 transformer:");
	scanf("%d",&n);
	printf("please input the gears of #2 transformer:");
	scanf("%d",&m);
	a=(float**)malloc(sizeof(float*)*n);  
	for(int i=0;i<n;i++)  
		a[i]=(float*)malloc(sizeof(float)*2); 
	b=(float**)malloc(sizeof(float*)*n);
	for(int i=0;i<n;i++)
		b[i]=(float*)malloc(sizeof(float)*2);
	float *c = (float*)malloc(sizeof(float)*n);
	float *d = (float*)malloc(sizeof(float)*n);
	float *e = (float*)malloc(sizeof(float)*m);
	float *f = (float*)malloc(sizeof(float)*m);
	
	for(int i=0;i<n;i++)
	{
		printf("Please input the #1 transformer medium pressure side ratio of %d gears:",i+1);
		scanf("%f",&c[i]);
	}
	for(int i=0;i<n;i++)
	{
		printf("Please input the #1 transformer low pressure side ratio of %d gears:",i+1);
		scanf("%f",&d[i]);
	}
	for(int i=0;i<m;i++)
	{
		printf("Please input the #2 transformer medium pressure side ratio of %d gears:",i+1);
		scanf("%f",&f[i]);
	}
	for(int i=0;i<m;i++)
	{
		printf("Please input the #2 transformer low pressure side ratio of %d gears:",i+1);
		scanf("%f",&e[i]);
	}
	for(int i=0;i<n;i++)
	{
		a[i][0] = c[i]*(1-0.005);
		a[i][1] = c[i]*(1+0.005);
	}
	for(int i=0;i<n;i++)
	{
		b[i][0] = d[i]*(1-0.005);
		b[i][1] = d[i]*(1+0.005);
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(e[i]>=b[j][0]&&e[i]<=b[j][1])
				printf("In the low side,#1 transformer's %d gears matches #2 transformer's %d gears.\n",j+1,i+1);
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(f[i]>=a[j][0]&&f[i]<=a[j][1])
				printf("In the medium side,#1 transformer's %d gears matches #2 transformer's %d gears.\n",j+1,i+1);
		}
	}
	free(a);
	free(b);
	free(c);
	free(d);
	free(e);
	free(f);
	return 0;
}
	
		