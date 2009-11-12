#include<stdio.h>
#include  <iostream>
using  namespace  std;
typedef  int        ElemType;  
typedef  int        status;
typedef  struct    LNode
{
  ElemType            data;
  struct  LNode    *next;              
}Lnode,*LinkList;



//初使化链表
//主要是为链表分配新的内存和对链表长清零并且对头结点尾清零
status  Initlist  (LinkList  &L)
{
  L  =  (LinkList)malloc(sizeof(Lnode));
  if  (L  ==  NULL)  
  {
    printf("the  space  is  not  found!\n");
    exit(0);
  }
  L->data  =  0;
  L->next  =  NULL;
  return  true;
}
//向链表中插入新的元素
//给定位置i(1到L.data)在定点插入数据e
//空表的时间可以在0处插入数据
//增加数据个数的记录
status  Listinsert(LinkList  &L,int  i  ,  int  e)
{
  LinkList  S,p;                          
  S=(LinkList)malloc(sizeof(Lnode));
  S->data  =  e;        
  p  =  L;
  if  (L->next  ==  NULL  &&  i  ==  0)//表空只能在0出插入元素
  {
    S  ->  next  =  L->next;
    L->next  =  S;
    L->data  ++;
    printf("the  number  you've  stored  is  %d!\n",L->data);
    printf("the  number  you've  insert  is  %d!\n",S->data);
    return  true;
  }
  if(i  <=  0  ||  i  >  L->data  )
  {
    printf("  the  number  is  out  of  range!\n");
    return  false;
  }
  for(int  j  =  0;  j  <  i  -1;  j  ++)
  {
    p  =  p->next;                      
  }
  S->next  =  p->next;
  p->next  =  S;
  L->data  ++;
  printf("the  number  you've  stored  is  %d!\n",L->data);
  printf("the  number  you've  insert  is  %d！\n",S->data);
  return  true;

}

//删除线性表中的元素
//输出链表内的说有数据元素
//寻找第  i-1个结点
//测试  已知量的合法性；
//删除结点，取出结点数据域的值
//释放结点的存储空间
status  Deletelist  (LinkList  &L,int  i,int  e  =  0)
{
  LinkList  p,M;
  //B;
  p  =  L;
  if(i  <=  0  ||  i  >  L->data  )    
  {
    printf("  the  number  is  out  of  range!\n");
    return  false;
  }              
  for(int  j  =  0;  j  <  i  -1;  j  ++)
  {
    p  =  p->next;

  }  
  M  =  p->next;
  e  =  M->data  ;
  //  B  =  M->next;
  p  ->  next  =    M  ->  next;  //将数据元素分块切除M
  L->data  --;
  M  ->  next  =  NULL;
  printf("the  number  you've  delete  is  %d!\n",e);
  free(M);
  return  true;

}

//查找定量元素
status  Locatelem(LinkList  &L,int  e)
{
  LinkList  p;
  p  =  L;
  int  mark  =  0  ;
  if(L->next  ==  NULL)
    return  0;
  while(p->next)
  {    mark  ++;
    p  =  p->next;
    if  (p->data  ==  e  )
    {
      cout<<"the  number    has  been  find  at  postion  of:  "  <<mark<<",  and  It  is:  "<<  e<<"."<<endl;
      return  true  ;//只是找到第一个匹配即返回
    }
  }
  cout<<"the  elem  is  not  exist  in  the  linklist!"<<endl;
  return  true;
}
//查找练表的前驱
status  Priorelem(LinkList  &L  ,  int  e  ,int  &pre)//单位移动，用两个指针操作
{

  LinkList  p,q;
  p  =  L->next  ;
  q  =  p  ->next;
  if(L->next  ==  NULL||p->next  ==  NULL)      
  {  
    printf("there  is  no  prior  exist!\n");
    return  0;
  }
  while  (q  ->  next)
  {
    if(  q->data  ==  e  )
    {
      pre  =  p  ->  data;
      printf("the  number  %d's  prior  %d  has  been  found  in  the  list!"  ,e,pre);
      return  true;
    }
    q  =  q  ->  next  ;
    p  =  p  ->  next;
  }
  cout<<"the  number"<<  e  <<"is  not  exist  in  the  linklist  !"<<endl;
  return  false;
}
//查找元素的后继
status  Nextelem  (LinkList  &L  ,  int  e  ,int  &ne)//连接型移动，实计是单指针操做
{
  LinkList  p,q;
  q  =  L;
  p  =  q->next  ;
  if(L->next  ==  NULL)
  {  
    printf("there  is  no  next  elem  exist!\n");
    return  0;
  }
  while(p)
  {
    q  =  p;
    p  =  q  ->next  ;
    if(q->data  ==  e  )
    {
      ne  =  p  ->data  ;
      printf("elem  %d's  nextelem  has  been  found,It  is  %d.!",e  ,ne);
      return  true;
    }

  }
  cout<<"the  number"<<  e  <<"is  not  exist  in  the  linklist  !"<<endl;
  return  false;
}
//连接两个都有表头的单链表
//增加表长
status  Append(LinkList  &LA,LinkList  &LB)
{
  LinkList  p;
  p  =  LA;
  while (p->next)
  {  
    p  =  p->next  ;
  }
  if(LB->next  ==  NULL)
    return  false;
  p->next  =  LB  ->  next;
  //LB  ->  next  =  NULL;
  LA->data  +=  LB->data;
  //free(LB);
  return  true;


}
//打印链表中的数据和列长
int  Visit(LinkList  &L)
{
  int  i  =  1;
  LinkList  p;
  p  =  L;
  if(L->data  ==  0  ||  p  ==  NULL)  
  {
    printf("there  is  no  contentment  in  the  linklist!\n");
    return  0;
  }
  //  while  (p)
  {
    //p  =  p->next;
    //  printf("the  %dth  number    is  %d.  \n",i,p->data);
    //  cout<<"the"<<i<<"th  number  has  been  stored  in  the  linklist  is"<<p->data<<!<<endl;
    //printf("the  number  has  been  stored  in  the  linklist  is  %d!\n",p->data  );

  }
  while(p->next)
  {    
    p  =  p->next;
    cout<<i<<"th  number  is:  "<<p->data<<endl;
    i++;
  }
  printf("the  total  numbe  of  the  list  is  %d!\n",L->data);
  return  true;
}

//函数声明
status        Initlist(LinkList  &);
status        Listinsert(LinkList  &  ,int    ,  int  );
status        Deletelist  (LinkList  &,int  ,int);
status        Visit(LinkList  &);
status        Locatelem(LinkList  &,int);
status        Priorelem(LinkList  &  ,  int    ,int  &);
status        Nextelem  (LinkList  &  ,  int    ,int  &);
status        Append(LinkList  &,LinkList  &);
int  main()
{
  LinkList        L,B;
  int  mark  =  0;
  Initlist  (L);
  Initlist  (B);
  Visit(L);
  cout<<"第1次插入！\n";
  Listinsert(L,0,5);
  Visit(L);
  cout<<"第2次插入！\n";
  Listinsert(L,1,4);
  Visit(L);
  cout<<"第3次插入！\n";
  Listinsert(L,1,3);
  Visit(L);
  cout<<"第4次插入！\n";
  Listinsert(L,1,2);
  Visit(L);
  cout<<"第5次插入！\n";
  Listinsert(L,1,1);
  cout<<"插入结束！\n";
  Visit(L);
  cout<<"删除第2个元素！\n";
  Deletelist(L,2);
  Visit(L);
  cout<<"第6次插入！\n";
  Listinsert(L,2,2);
  Visit(L);
  cout<<"查找元素4！\n";
  Locatelem(L,4);
  cout<<"查找元素7！\n";
  Locatelem(L,7);
  cout<<"查找元素3的前驱！\n";
  Priorelem(L,3,mark);
  cout<<"查找元素3的后继！\n";
  Nextelem  (L  ,3,mark);

  cout<<"第1次插入！\n";
  Listinsert(B,0,1);
  Visit(B);
  cout<<"第2次插入！\n";
  Listinsert(B,1,3);
  Visit(B);
  cout<<"第3次插入！\n";
  Listinsert(B,2,2);
  Visit(B);
  cout<<"第4次插入！\n";
  Listinsert(B,1,4);
  Visit(B);
  cout<<"第5次插入！\n";
  Listinsert(B,1,5);
  Visit(B);
  Append(L,B);
  cout<<"打印L中的元素！\n";
  Visit(L);
  // system("pause");
  return  0  ;



}
