//分治模板？
#include<iostream>
#include<cmath>
using namespace std;
int a;
void fff(int x)
{
    for(int i=14;i>=0;i--)
    {
        if(pow(2,i)<=x){
            if(i==1) cout<<"2"; //2（1）不用再往后分解了，2^1输出为2，单独出来
            else if(i==0) cout<<"2(0)"; //2（0）不用再往后分解了，单独出来
            else{
                cout<<"2(";
            fff(i);
            cout<<")";
            }
            x-=pow(2,i);
            if(x!=0) cout<<"+"; //主要是加号的处理，若此x还没分解完，则后面还有项，所以输出一个+
        }
    }
}
int main()
{
    cin>>a;
    fff(a);
    return 0;
}
