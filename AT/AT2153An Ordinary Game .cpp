/*
i
ͷβ��ͬ��ʱ�����϶���ʣ����������ĸ�ģ�����ababa
���λ����������ô�м�϶�������ż���β������������������

ii
ͷβ��ͬ�Ļ������ʣ��ż����
���λ��Ϊ�����Ͳ����������Σ�����ż����

-ż���β�����ô��һ���˾��޷��������䣬�����β����ڶ������޷���������
*/
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char s[100000];
    cin>>s;
    long long t=strlen(s);
    if(s[0]==s[strlen(s)-1]){
    	if(t%2==1) cout<<"Second"<<endl;
    	else cout<<"First"<<endl;
	}
	else{
		if(t%2==0) cout<<"Second"<<endl;
    	else cout<<"First"<<endl;
	}
    return 0;
}
