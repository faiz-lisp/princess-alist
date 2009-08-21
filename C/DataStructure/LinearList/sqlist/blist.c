#define          OK        1
#define    error          0
#define    false          0
#define      true          1                        //定义应用的新的数据类型同时初始化const  变量false  &  true..
#define    OVERFLOW    0
#include<stdlib.h>
#include<stdio.h>

//以全新的数据类型让c重新回到我们的面前
//虽然很多都是学过的东西但是算法确实是很重要的一个关节
//现在才知道程序员的级别不是一个人能够实现什么功能而是..谁用的代码少!并且精!
typedef  int  ElemType;
typedef  ElemType  ET;
typedef  int  status;
typedef  struct{
  ElemType            *elem;
  ET    re_length;
  int    listsize;
}Sqlist;


//创建一个空的新的线性表
//主要是申请内存和对线性表的长度清零
status  Initlist_Sq(Sqlist* L)
{
  L.elem  =  (ET*)malloc(20*sizeof(int));
  if  (L.elem  ==  NULL)
    exit(0);
  L.listsize  =  20;
  L.re_length  =  0;
  return  OK;
}
//清空线性表
//将线性表的数据项全部覆盖,长度清零
status  Clearlist(Sqlist  L)
{
  if(!L.elem)
  {            
    printf("the  Sqlist  is  not  exist!\n");
    return  false;
  }
  L.re_length  =  0  ;
  return  true;          
}
//销毁线性表
//清空内存
status  Destroylist(Sqlist  L)
{
  if(!L.elem)
  {            
    printf("the  Sqlist  is  not  exist,");
    return  false;
  }
  free(L.elem);//释放内存
  return  true;
}
//线性表的插入操作
//在第i个元素之前插入新的元素e  
//增加线性表的长度
status  List_insert(Sqlist  L  ,  int  i  ,  int  e  )
{
  if(!L.elem)
  {            
    printf("the  Sqlist  is  not  exist!\n");
    return  false;
  }
  if  (i  <  0  ||  i  >  L.re_length)
  {
    printf("the  number  i  is  not  a  probablely  number!\n");
    return  false;
  }        //检验数据域是否在操作域内
  int j;
  for  (j  =  0  ;  j  <  L.re_length-i+1  ;  j++)
  {  
    L.elem[L.re_length-j]  =  L.elem[L.re_length-1-j];
  }//对后序的数据进行移动位置
  L.elem[i-1]  =  e;//插入新的数据
  L.re_length  ++;//刷新线性表的长度
  return  true;
}
//线性表操做之删除数据元素
//删除列表中的第i个元素
//并且用e返回第i个元素的值
status  ListDelet  (Sqlist  L  ,  int  i  ,int  e)
{
  if(!L.elem)
  {            
    printf("the  Sqlist  is  not  exist!\n");
    return  false;
  }
  if(i  <  1  ||  i  >  L.re_length)
    return  error;
  e  =  L.elem[i-1];
  printf("the  number  you  wanna  delete  is  %d\n",e);
  int j;
  for  (j  =  0  ;  j  <  L.re_length-i;  j  ++)
    L.elem[i-1+j]  =  L.elem[i+j];
  L.re_length  --;//刷新线性表的长度
  return  OK;
                
}
//线性表的查找操作(只是找到第一个元素即返回)
//找到匹配的数值并且返回
//否则根据情况输出相应的错误信息
status  LoacteElem(Sqlist  L,  int  e,int  mark)
{            
  if(!L.elem)
  {
    printf("the  Sqlist  is  not  exist!\n");
    return  false;
  }
  int  sign  =  0;//标志是否查找到要找的元素
  int j;
  for  (j  =  0  ;  j  <  L.re_length  ;  j  ++)
    if(L.elem[j]  ==  e  )  {  
      printf("elem  %d  has  been  found  at  the  age  of  %d!\n",e,j+1);
      sign  =  1;
      mark  =  j+1;
      printf("the  position  is  %d",mark);
      break;
    }//返回第一个元素
  if  (sign  ==  0  )  {
    printf("the  number  is  not  exit  in  this  contentment!\n");
    mark  =0  ;
    return  false;
  }    
  return  true;                              
}
//线性表操作之函数返回第i个元素的前驱
//找到第i－1个元素并且以e返回
status  PriorElem(Sqlist  L  ,  int  i  ,  int  e)
{
  if  (i  <=  1  ||  i  >  L.re_length)
    return  false  ;
  e  =  L.elem[i-2];
  printf("the  priorelem  is  %d\n",e);
  return  true;
}
//线性表操作之返会线性表第i个数据元素的后继
//找到第i＋1个元素并且以e返回

status  NextElem(Sqlist  L  ,  int  i  ,int  e  )
{              
  if(!L.elem)
  {            
    printf("the  Sqlist  is  not  exist!\n");
    return  false;
  }
  if  (i  <1  ||  i  >=  L.re_length)
    return  error;
  e  =  L.elem[i];
  printf("the  next  elem  is  %d\n",e);
  return  OK;
}


//线性表操作之浏览表内元素

status  Visit(Sqlist  L)
{                
  if  (!L.elem)
  {
    printf("the  Sqlist  is  not  exist,");
    return  false;
  }
  int j;
  for(j  =  0  ;  j  <  L.re_length  ;  j  ++)
    printf("the  %dth  date  has  been  stored  is  %d\n",j+1,  L.elem[j]);
  return  true;                      
}
//线性表操作之删除元素队列
//删除第i个元素之后的k个元素

status  Deletesome(Sqlist  L,int  i  ,int  k)
{
  if(!L.elem)
    return  error;
  if  (i  <  0  ||  i  >  L.re_length)
  {                        
    printf("range  error  the  fuction  will  not  on  work!\n");
    return  error;
  }
  if(i  +  k  >  L.re_length)
  {
    L.  re_length  =  i;
    return  OK;
  }
  int j;
  for  (j  =  0  ;  j  <  k;  j  ++)
    L.elem[i+j]  =  L.elem[i+1+j];
  L.re_length  --;  //刷新线性表的长度
  return  OK;                
}
//线性表操作之改变元素的数值
//主要是以下表定位找到之后赋相应的数据值
//显示改变数据操作之前和操作之后的数据项

status  Numberchange(Sqlist  L,int  i,int  e)
{
  if  (!L.elem)
    return  error  ;
  printf("the  regular  number  is  %d",L.elem[i-1]);
  L.elem[i-1]  =  e;
  printf("number  changed  is  %d",L.elem[i-1]);
  return  OK;
}

//函数列表
status  Initlist_Sq(Sqlist*);
status  Clearlist(Sqlist  );
status  Destroylist(Sqlist  );
status  List_insert(Sqlist  ,  int    ,  int);
status  ListDelet  (Sqlist  ,  int  ,  int  );
status  LoacteElem(Sqlist  ,  int  ,int  );
status  PriorElem(Sqlist    ,  int    ,  int  );
status  NextElem(Sqlist  ,  int  ,int  );
status  Visit(Sqlist  );
status  Deletesome(Sqlist  ,int  ,int  );
status  Numberchange(Sqlist  ,int  ,int  );

int  main()
{
  char  space;
  Sqlist      L;
  printf("any  word  to  return!\n");
  scanf("%c",space);
  Initlist_Sq(&L);
  if(L.elem  ==  NULL)
  {
    printf("story  problem  we  can  not  operate  continue!\n");
    return  false;
  }
  for  (  int  j  =  0  ;j  <  9;  j  ++)
    L.elem[j]  =  j+1;
  L.re_length  =  j;
  Visit(&L);

  return  0;
}
