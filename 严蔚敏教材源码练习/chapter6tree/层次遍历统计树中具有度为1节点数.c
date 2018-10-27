typedef struct BiTNode
{
	int data;
	struct BiTNode *lchild,*rchild;
  
}BiTNode,*Bitree;

BiTNode *p;

int leave(Bitree bt)
{
	int num=0;
	if(bt)
	{
		QueueInit(Q);//定义队列Q为 元素为二叉树节点的指针

		QueueIn(Q,bt);//根节点入队
		while(!QueueEmpty(Q))
		{
			p=QueueOut(Q); cout<<p->data;//根节点出队列
			if( (p->lchild && !p->rchild) || (!p->rchild && p->lchild) ) //度为1
				num++;
			if(p->lchild)
				QueueIn(Q,p->lchild);
			if(p->rchild)
				QueueIn(Q,p->rchild);

		}
	}
	return num;
}