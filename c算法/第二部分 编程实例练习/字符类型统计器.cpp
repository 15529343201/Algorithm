/*
���дһ��c�������ն��ü��������ַ�������Ctrl+Z������ͳ������
���ַ����пո��Ʊ�������з��ĸ���������ʾͳ�ƵĽ��
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
