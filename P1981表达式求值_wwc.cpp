#include<iostream>
#include<stack>
using namespace std;
stack<long long> num;
stack<char> op;
long long pop()
{
	if(op.top()=='*'){
		int t1=num.top();
		num.pop();
		int t2=num.top();
		num.pop();
		return t1*t2;
	}
	else{
		int t1=num.top();
		num.pop();
		int t2=num.top();
		num.pop();
		return t1+t2;
	}
}
int main()
{
	char a;
	while(cin>>a)
	{
		switch(a)
		{
			case '+':{
				if(op.empty()) op.push('+');
				else{
					pop();
				}
				break;
			}
			case '*':{
				if(op.empty()) op.push('*');
				else if(op.top()=='+'){
					op.push('*');
				}
				else pop();
				break;
			}
			default:{
				int s=0;
				do
				{
					s=s*10+a-'0';
				}while(a!='+' && a!='*' && cin>>a);
				num.push(s);
				break;
			}
		}
	}
	while(!op.empty())
	{
		if(op.top()=='*'){
				if(op.empty()) op.push('+');
				else{
					pop();
				}
				break;
			}
			if(op.top()=='*'){
				if(op.empty()) op.push('*');
				else if(op.top()=='+'){
					op.push('*');
				}
				else pop();
				break;
			}
	}
	cout<<num.top();
	return 0;
}
