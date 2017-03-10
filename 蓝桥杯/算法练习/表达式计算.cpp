/* 问题描述
　　输入一个只包含加减乖除和括号的合法表达式，求表达式的值。其中除表示整除。
输入格式
　　输入一行，包含一个表达式。
输出格式
　　输出这个表达式的值。
样例输入
1-2+3*(4-5)
样例输出
-4
数据规模和约定

　　表达式长度不超过100，表达式运算合法且运算过程都在int内进行。
*/
#include<iostream>
#include<cstring>
#include<stack>
#include<algorithm>
#include<cmath>
using namespace std;

stack<char> s1,s2;
stack<int> s3;
char ch[150]={0};//用来存表达式
int num[11];//用来暂存数字 

int priority(char ch)//用于比较字符优先级      
{      
    if(ch==')') return 1;      
    if(ch=='+'||ch=='-') return 2;      
    if(ch=='*'||ch=='/') return 3;      
    if(ch=='(') return 4;         
}      
           
int Scal(int x,int y,char ope)//两个数的运算      
{      
    if(ope=='+') return x+y;      
    if(ope=='-') return x-y;      
    if(ope=='*') return x*y;      
    if(ope=='/'&&y!=0) return x/y;      
} 
     
//将中缀表达式转换为后缀表达式
void Transform(int n)
{
	int k=0;
	for(int i=0;i<n;i++)
	{
		if(ch[i]>='0'&&ch[i]<='9')//当时数字的情况
		{
			if(i+1<n&&(ch[i+1]<'0'||ch[i+1]>'9')||i==n-1)//当是最后一个数字，或下一个元素是运算符 
			{
			    s2.push(ch[i]);
			    s2.push('#');
			}
			else
			{
				s2.push(ch[i]);
			}
		}
		else
		{
			if(s1.empty()||ch[i]=='('||priority(ch[i])>priority(s1.top()))//当是运算符，有3种情况直接入栈 
		         s1.push(ch[i]);
		    else if(ch[i]==')')//当是右括号的情况
			{
				while(s1.top()!='(')
				{
					s2.push(s1.top());
					s1.pop();
				}
				s1.pop();
			}
			else//当运算符优先级小于或等于S1栈顶运算符的优先级 
			{
				while(!s1.empty()&&priority(ch[i])<=priority(s1.top())&&s1.top()!='(')//这里还要注意两个界限
				{
					s2.push(s1.top());
					s1.pop();
				}
				s1.push(ch[i]);
			} 
		} 
		
	}
	while(!s1.empty())//当表达式结束  
	{
		s2.push(s1.top());
		s1.pop();
	}
	while(!s2.empty()) //将栈内元素放回ch[]中      
    {      
        ch[k++]=s2.top();      
        s2.pop();         
    }      
    reverse(ch,ch+k);//将ch[]反向      
    ch[k]=0;      
	
} 

//后缀表达式计算 
int Cal(int n)
{
	int x,y,tmp=0,k=0;
	for(int i=0;i<n;i++)
	{
		if(ch[i]=='#')//是#直接跳过
		   continue;
		else if(ch[i]=='+'||ch[i]=='-'||ch[i]=='*'||ch[i]=='/')//是运算符弹出栈顶两元素计算后放回栈
		{
			x=s3.top();      
            s3.pop();      
            y=s3.top();      
            s3.pop();      
            x=Scal(y,x,ch[i]);      
            s3.push(x);  
		}
		else//是数字字符      
        {      
            if(ch[i+1]=='#')//下一个元素是#      
            {      
                num[k++]=ch[i]-'0';      
                for(int i=0;i<k;i++)      
                    tmp+=(num[i]*(int)pow(10,k-i-1));      
                s3.push(tmp);      
                tmp=0;      
                k=0;                      
            }      
            else//下一个元素不是#      
            {      
                num[k++]=ch[i]-'0';       
            }         
        }      
    }      
    return s3.top();      
}

int main()
{
	gets(ch);
	Transform(strlen(ch));
	cout<<Cal(strlen(ch))<<endl;
	return 0;
}
