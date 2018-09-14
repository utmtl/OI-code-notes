#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=n+1;;i++)
	{
		if(i%10!=i/10%10 && i%10!=i/100%10 && i%10!=i/1000 && i/10%10!=i/100%10 && i/10%10!=i/1000 && i/100%10!=i/1000){
			cout<<i;
			return 0;
		}
	}
}