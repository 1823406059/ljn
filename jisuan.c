#include<stdio.h>
#include<math.h>
#include<time.h>
#include <stdlib.h>
void opration(void);
float numjisuan(int i,float a,float b);
char yunsuanfu(int i);
void main()
{
	int i=0,n;
	printf("输入运算的条数为：");
	scanf("%d",&n);
	do{
		opration();
		i++;
	}while(i<n);
	system("pause");
}
void opration(void)
{
	float numanswer;
	float x,y,z;
	int a,b,c;
	int j,k;
	char op1,op2;
	srand((unsigned)time(NULL));
	do{
		a=rand()%100;
		b=rand()%100;
		c=rand()%100;
		//0，1为加减 2，3为乘除
		j=rand()%4;
		k=rand()%4;
		if(j>1){
			y=(float)a;
			z=(float)b;
			x=numjisuan(j,y,z);
			y=x;
			z=(float)c;
			x=numjisuan(k,y,z);
		}
		else
		{
			if(k<2)
			{
				y=(float)a;
			    z=(float)b;
			    x=numjisuan(j,y,z);
			    y=x;
			    z=(float)c;
			    x=numjisuan(k,y,z);
			}
			else
			{
				y=(float)b;
			    z=(float)c;
		    	x=numjisuan(k,y,z);
			    y=(float)a;
			    z=x;
		    	x=numjisuan(j,y,z);
			}
		}
	}while(x<0);
	op1=yunsuanfu(j);
	op2=yunsuanfu(k);
	printf("%d %c %d %c %d = ",a,op1,b,op2,c);
	scanf("%f",&numanswer);
	if(fabs(numanswer-x)<0.01)
	{
		printf("答对啦！\n");
	}
	else
	{
		printf("答错啦！，正确答案是：%.1f\n",x);
	}
}
float numjisuan(int i,float a,float b)
{
	float x;
	switch(i)
	{
	case 0:
		x=a+b;
		break;
	case 1:
		x=a-b;
		break;
	case 2:
		x=a*b;
		break;
	case 3:
		x=a/b;
		break;
	default:
		break;
	}
	return x;
}
char yunsuanfu(int i)
{
	char op;
	switch(i)
	{
	case 0:
		op='+';
		break;
	case 1:
		op='-';
		break;
	case 2:
		op='*';
		break;
	default:
		op='/';
		break;
	}
	return op;
}