  //我有玄学的二分技巧: 先找出答案所在区间, 再在区间内枚举答案, 不管题怎么变都不会WA
	//记得 break 和 r+1~l-1 !!!还要判断r+1, l-1是否在合法范围内
  //example
  int l=0,r=5000000001,mid;
    while(r-l>15)
    {
        mid=(l+r)>>1;
        if(chk(mid)) l=mid+1;
        else r=mid;
    }
    for(re int i=r+1;i>=max(l-1,0);--i)
		if(chk(i)){printf("%lld\n",i);break;}
