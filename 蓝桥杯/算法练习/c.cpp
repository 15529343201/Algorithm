//#include<stdio.h>
//int main()
//{
//	int a,b,c,max;
//	scanf("%d%d%d",&a,&b,&c);
//	max=(a>b?(a>c?a:c):(b>c?b:c));
//	printf("%d\n",max);
//	return 0;
//}
/*#include<stdio.h>
#include<math.h>
int main()
{
	float a,b,c,area,l;
	scanf("%f%f%f",&a,&b,&c);
	l=(a+b+c)/2.0;
	area=sqrt(l*(l-a)*(l-b)*(l-c));
	printf("%.2lf\n",area);
	return 0; 
}
*/ 
#include<stdio.h>
#include<math.h>
int main()
{
	float a,b,c;
	scanf("%f%f%f",&a,&b,&c);
	printf("x1=%.2f,x2=%.2f\n",(-b-sqrt(b*b-4*a*c))/(2*a),(-b+sqrt(b*b-4*a*c))/(2*a));
    return 0;
}
