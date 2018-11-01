/*
STL之链表:

初始化:
list<int>a(n,m) //声明一个n个元素的列表,每个元素都是m
list<int>a(first,last) //声明一个列表,其元素的初始值来源于由区间所指定的序列中的元素,first和last是迭代器

插入与删除:
push_back(),push_front(),pop_back(),pop_front()
remove(n) //删除值为n的所有元素
insert(it,元素) //在迭代器it前插入元素
insert(it,n,元素) //在迭代器it前插入n个同一元素
//链表优势: 插入删除操作时间复杂度为O(1)

front(),back()//可返回首尾元素
reverse()//翻转
 */
#include<cstdio>
#include<list>
using namespace std;
list<int> lb{1,2,3,5,6,7};//定义与初始化
int main()
{
	list<int>::iterator it;//指向一个int链表的迭代器it, 类似于指针
	it=lb.begin();
	advance(it,3);//相当于it+=3. 但迭代器只重载了++和--运算符, 没有+, -操作, advance()相当于重复++或--
	//PS: advance是前进的意思
	//CE: lb.insert(lb.begin()+3,4);
	lb.insert(it,4);//在it前(即begin+3 即第四个元素前)插入元素4
	for(it=lb.begin();it!=lb.end();it++)
		printf("%d ",*it);//遍历list
	return 0;
}
