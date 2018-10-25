//设A=（a1,...,am）和B=(b1,...bn)均为顺序表 A'和B'分别为A和B中除去最大共同前缀后的子表。若A'=B'=空表，则A=B
//若A'=空表  B'不为空 或者两者均不为空表 且A'首元素小于B'首元素 则A<B
//否则A>B
#define MaxSize 100
typedef int ElemType;
typedef struct 
{
	ElemType *elem;
	int length;
}SqList;

int CompareOrderList(SqList &A,SqList &B)
{
int i,j,k;
k=A.length>B.length?A.length:B.length;
for(i=0;i<k;i++)
{
	if(A.elem[i]>B.elem[i]) j=1;
	if(A.elem[i]<B.elem[i]) j=-1;

}
if(A.length>k)j=1;
if(B.length>k)j=-1;
if(A.length==B.length)j=0;
return j;
}