
#include <stdbool.h>
typedef int ElemType;

typedef struct 
{
	ElemType *elem;
	int length;
	int listize;
}SqList;//顺序表



int DeleteK (SqList &a,int i,int k)
{ //从线性表a中删除第i个元素起的k个元素
  if(i<0||i>a.length||k<0||k>a.length-i)
    return 0;
  else
  { int j;
  	for(j=0;j<=k;j++)
      a.elem[j+i]=a.elem[j+i+k];
    a.length=a.length-k;
  	
  }
  return 1;
}

