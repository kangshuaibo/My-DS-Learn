typedef struct{
 CSNode *ptr;
CSNode *lastchild;
} NodeMsg; //结点的指针和其最后一个孩子的指针

Status Build_CSTree_PTree(PTree T)//由树 T 的双亲表构造其孩子兄弟链表 www.kaoeasy.com
{
	NodeMsg Tree[MAXSIZE]; 
	for(i=0;i<T.n;i++)
	{
		Tree[i].ptr=(CSNode*)malloc(sizeof(CSNode));
		 Tree[i].ptr->data=T.node[i].data; //建结点
		  if(T.nodes[i].parent>=0) //不是树根
			{
				j=T.nodes[i].parent; //本算法要求双亲表必须是按层序存储 
				if(!(Tree[j].lastchild)) //双亲当前还没有孩子
					Tree[j].ptr->firstchild=Tree[i].ptr; //成为双亲的第一个孩子
				else //双亲已经有了孩子
					Tree[j].lastchild->nextsib=Tree[i].ptr; //成为双亲最后一个孩子的下一个兄弟
				Tree[j].lastchild=Tree[i].ptr; //成为双亲的最后一个孩子
			}//if
	}//for
}//Build_CSTree_PTree 

 