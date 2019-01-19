//		设顺序表va中数据元素有序递增 试写一算法 将x插入到顺序表的适当位置保持该表的有序性
#include <stdbool.h>

typedef  int ElemType; 

typedef struct
{
	ElemType *elem;
	int length;
	int listsize; 
}SqList;

bool InsertOrderList(SqList &va,ElemType x)
{
 int i;
 if(va.length==va.listsize)
 	return 0;

 for(i=va.length ; i > 0&&x<va.elem[i-1] ;i--)//从末尾开始递减遍历
 	va.elem[i]=va.elem[i-1];//后移动一个

 va.elem[i]=x;//插入
 va.length++;
 return 1;
}
