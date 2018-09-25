#include<iostream>
#include<string.h>
using namespace std;
int i=0,top=1;
float n[201];
char f[201],s[451],t[451];  
void push(void)
{
	top++;
	f[top]=s[i];
}
void pop(void)
{
	switch(f[top])
	{
		case '+':n[top-1]+=n[top];break;
		case '-':n[top-1]-=n[top];break;
		case '*':n[top-1]*=n[top];break;
		case '/':n[top-1]/=n[top];break;
	}
	top--;
}
bool can(void)
{
    if(((s[i]=='+')||(s[i]=='-'))&&(f[top]!='(')) return true;
    if(((s[i]=='*')||(s[i]=='/'))&&((f[top]=='*')||(f[top]=='/'))) return true;
    return false;
}
int main()
{  
    int x=0;
	cout<<"请输入一个表达式："<<endl;
    gets(s);
    s[strlen(s)]=')';
    f[top]='(';
    while(i<strlen(s))
    {
        while(s[i]=='(')
        {
            push();
			i++;
        }
        while((s[i]>='0')&&(s[i]<='9'))
        {
        	x=x*10+s[i]-'0';
        	i++;
        }
        n[top]=x;
        x=0;
        do
        {  
            if(s[i]==')')
            {
                while(f[top]!='(')
				{
				    pop();
				}
                top--;
                n[top]=n[top+1];
            }
            else
            {
                while(can())
                {
                	pop();
                }
                push();
            }
            i++;
        }while((i<strlen(s))&&(s[i-1]==')'));
    }
    cout<<"="<<n[0];
    return 0;
}
