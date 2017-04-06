/*
请编写一个c程序，在终端用键盘输入字符串，以Ctrl+Z结束，统计输入
的字符串中空格，制表符，换行符的个数，并显示统计的结果
*/
#include<stdio.h>
#include<string.h>
#define EOF (-1)
int main()
{
	char c;
	int space=0,table=0,enter=0;
	printf("Please input a string:\n");
	scanf("%c",&c);
	while(c!='#'){
		switch(c){
			case 32:space++;break;
			case 9:table++;break;
			case 10:enter++;break;
			default:break;
		}
		scanf("%c",&c);
	}
	printf("The number of space:%d\n",space);
	printf("The number of table:%d\n",table);
	printf("The number of enter:%d\n",enter);
	getchar();
	return 0;
}
