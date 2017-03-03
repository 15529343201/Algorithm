//给定圆的半径r，求圆的面积。
//输入包含一个整数r，表示圆的半径。
//输出一行，包含一个实数，四舍五入保留小数点后7位，表示圆的面积。
#include<cstdio>
#include<cmath>
const double pi=acos(-1.0);
int main()
{
	double r;
	scanf("%lf",&r);
	printf("%.7lf\n",pi*r*r);
	return 0;
}
