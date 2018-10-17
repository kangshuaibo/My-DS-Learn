ADT List{//抽象数据类型线性表
	InitList(&L)
	DestroyList(&L)
	ClearList(&L)
	ListEmpty(L)

}ADT List



//😄例2-1 两个集合AB
void union(List &La,List Lb){

	La_Len=ListLength(La);
	Lb_Len=ListLength(Lb);
	for(i=1;i<=Lb_Len;i++){
		GetElem(Lb,i,e);
		if(!LocateElem(La,e,equal))
			ListInsert(La,++La_len,e);

	}
}//算法2-1 








//😝例2-2 线性表La Lb数据元素非递减有序排列
void MergeList(List La,List Lb,List &lc)
{
	InitList(Lc);
	i=j=1;k=0;
	La_Len = ListLength(La);
	Lb_Len = ListLength(Lb);
	while( (i<=La_Len)&&(j<=Lb_Len) )
	{
		GetElem(La,i,ai);//取La中第i个元素给ai
		GetElem(Lb,j,bj);
		if(ai<=bj)
		     {
				ListInsert(Lc,++k,ai);
				++i;
		     }
		     
	    else{
				ListInser(Lc,++k,bj);
				++j;
			}
			
	}
	

	while(i<=La_Len)
	{
		GetElem(La,i++,ai);
		ListInser(Lc,++k,ai);
	}
	while(j<=Lb_Len)
	{
		GetElem(Lb,j++,bj);
		ListInsert(La,++k,bj);
	}

}//算法2-2









//*****************线性表 动态分配 顺序存储结构*******************************************************************p22
#define LIST_INIT_SIZE 100
#define LISTINCREMENT
typedef struct{
	ELemType *elem;
	int length;
	int listsize;
}SqList;



Status InitList_Sq(SqList &L)
{//构造一个空线性表L
	L.elem=(ELemType*)malloc(LIST_INIT_SIZE*sizeof(ELemType));
	if(!L.elem)
		exit(OVERLOW);
	L.length = 0;
	L.listsize= LIST_INIT_SIZE;

	return OK;
}//算法2-3



Status ListInsert_Sq(SqList &L,int i,ELemType e)
{  //在顺序表L中第i个位置之前插入新元素e
	if( i<1||i>L.length+1)
		return error;
	if(L.length>=L.listsize)
	{
		newbase = (ELemType* )realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ELemType));
	}
	if(!newbase)
		exit(OVERLOW);
	L.elem= newbase;
	L.listsize+=LISTINCREMENT;

q=&(L.elem[i-1]);  //q为插入位置
for(p = &(L.elem[L.length-1]);p>=q;--p)
	*(p+1)=*p;
*q = e;
++L.length;
return OK;
}//算法2-4


Status ListDelete_Sq(SqList &L,int i,ELemType)
{//线性表L中删除第i个元素 并用e返回
	if(i<i)||(i>L.length)
		return error;
	p=&(L.elem[i-1]);
	e=*p;
	q=L.elem+L.length-1;
	for(++p;p<=q;++p)
	{
		*(p-1) = *p;
		--L.length;
		return Ok;
	}

}//算法2-5


int LocateElem_Sq(SqList L,ELemType e,Status(*compare)(ELemType,ELemType))
{//在顺序线性表L中查找第一个与e满足compare的元素位序
	i=1;
	p=L.elem;
	while( i<=L.length && !(*compare)(*p++,e) )
		++i;
	if(i<=L.length)
		return i;
	else
		return 0;
}//算法2-6



void MergeList_Sq(SqList La,SqList Lb,SqList &Lc)
{
	pa = La.elem;
	pb = Lb.elem;
	Lc.listsize = Lc.length = la.length + Lb.length;

	pc=Lc.elem = (ElemType*)malloc(Lc.Listisize*sizeof(ElemTpye));
	if(!Lc.elem)
		exit(OVERLOW);
	pa_last = La.elem+La.length-1;
	pb_last = Lb.elem+Lb.length-1;
	while(pa<=pa_last && pb<=pb_last)//归并
	{
		if(*pa<=*pb)
			*pc++ = *pa++;
		else
			*pc++ = *pb++;

	}
	while(pa<=pa_last)
		*pc++ = *pa++;
	while(pa<=pa_last)
		*pc++ = *pb++;
}//算法2-7 顺序表归并 已知La Lb非递减🆚



//***************线性表 单链表 存储结构****************************************************************************p28
typedef struct LNode{
	ELemType data;
	struct LNode *next;
}LNode,*LinkList;



Status GetElem_L(LinkList L,int i,ELemType &e)
{//当第i个元素存在时 其置赋值给e
	p = L->next;
	j=1;
	while(p && j<i)
	{
		p=p->next;
		++j;
	}
	if(!p||j>i)
		return ERROR;

	e = p->data;
	return OK;

}//算法2-8 查找第i个位置的值


Status LinkList_L(LinkList &L,int i,ELemType e)
{//在带头结点的 单链 线性链表L中第i个位置之前插入元素e
	p = L;
	j=0;
	while( p && j<i-1)
	{
		p=p->next;//寻找第i-1个节点
		++j;
	}
	if(!p||j>i-1)
		return ERROR;
	s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}//算法2-9



status ListDlete_L(LinkList &L,int i,ELemType &e)
{//在带头结点的单链线性表L中，删除第i个元素，并由e返回其值
	p=L;
	j=0;
	while(p->next && j<i-1)
	{//寻找第i个节点，并令p指向其前驱
		p = p->next;
		++j;
	}
	if( !(p->next&&j>i-1) )
		return ERROR;
    
    p = p->next;
    p->next = q->next;//本质上p为pCurrent q为pNext
    e = q->data;
    free(q);
}//算法2-10


void CreatList_L(LinkList &L,int n)
{//逆序输入n个元素的值，建立带表头节点的 单链 线性链表L
	L=(LinkList)malloc(ssizeof(LNode));
	L->next=NULL;
	for(i=n;i>0;--i)
		p=(LinkList)malloc(sizeof(LNode));

	scanf(&p->data);

	p->nxet = L->next;
	L->next=p;//插入到表头
}//算法2-11


void MergeList_L(LinkList &La,LinkList &Lb,LinkList &Lc)
{//已知单链线性表La Lb的元素按值非递减排列
	pa = La->next;
	pb = Lb->next;
	Lc = pc = La;//另建存储空间
	while(pa&&pb)
	{
		if(pa->data <= pb->data)
		{
			pc->naxt=pa;
			pc = pa;
			pa=pa->naxt;	
		}
		else
		{ 
			pc->next=pb;
			pc = pb;
			pb=pb->naxt;
		}
		pc->next = pa?pa:pb;
		free(Lb);
	}

}//算法2-12 两个有序链表归并



//****************************************线性表的静态单链表存储结构****************************************p31
#define MAXSIZE 1000
typedef struct{
	ELemType data;
	int cur;//指示器代替指针
}component,SLinkList[MAXSIZE];

//😝例2-3 假设由终端输入集合元素 先建立集合A的静态链表S  在输入集合B同时查找S 若存在与B相同则删除 否则插入
int LocateElem_Sl(SLinkList S,ELemType e)
{//在静态单链线性表 L中查找第一个值为e的元素
	i=S[0].cur;
	while(i&&s[i].data!=e)
		i=S[i].cur;
	return i;

}






