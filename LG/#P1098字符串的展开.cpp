#include<iostream>
#include<cstring>
using namespace std;
char s[10000];
int p1,p2,p3;
int main()
{
	cin>>p1>>p2>>p3>>s;
	for(int i=0;i<strlen(s);i++)
	{
		if(s[i]=='-' && s[i-1]<s[i+1] && ((s[i-1]>='a' && s[i-1]<='z' && s[i+1]>='a' && s[i+1]<='z')||(s[i-1]>='0' && s[i-1]<='9' && s[i+1]>='0' && s[i+1]<='9'))){
			if(p3==1){
				for(char j=s[i-1]+1;j<s[i+1];j++)
				{
					for(int k=1;k<=p2;k++)
					{
						if(p1==1) cout<<(char)tolower(j);
						if(p1==2) cout<<(char)toupper(j);
						if(p1==3) cout<<'*';
					}
				}
			}
			else{
				for(char j=s[i+1]-1;j>s[i-1];j--)
				{
					for(int k=1;k<=p2;k++)
					{
						if(p1==1) cout<<(char)tolower(j);
						if(p1==2) cout<<(char)toupper(j);
						if(p1==3) cout<<'*';
					}
				}
			}
		}
		else cout<<s[i];
	}
	return 0;
}
