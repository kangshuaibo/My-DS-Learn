 /*
先序遍历
*/
void PreOrder(BiTree T)
{
	if(!T)
	{
		visit(T);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}




/*中序遍历*/
void InOrder(BiTree T)
{
	if(!T)
	{ 
		InOrder(T->lchild);
		visit(T);
		InOrder(T->rchild);

	}
}




/*
后序遍历
*/
void PostOrder(BiTree T)
{
	if(!T)
	{
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		visit(T);
	}
}


/*
层次遍历
*/
/*
层次遍历要借助队列 
先将根节点入队列 出队访问
如果他有左子树将根节点的左子树入队列 如果有右子树将右子树入队列
出队 访问这个节点 这个节点的左右入队遍历
*/

void LeaveOrder(BiTree T)
{
	InitQueue(Q); //层次遍历需队列
	BiTree p;
	EnQueue(Q,T); //根节点入队
	while(!IsEmpty(Q))
	{
		DeQueue(Q,p);//出队
		visit(p);

		if(p->lchild!=NULL)
			EnQueue(Q,p->lchild);
		if(p->rchild!=NULL)
			EnQueue(Q,p->rchild);

	}
}


/*
-----------------------------线索化---------------------------------
*/
typtdef struct ThreadNode
{
	ElemType data;
	struct ThreadNode *rchild,*lchild;
	int ltag,rtag;
}Thread,*ThreadTree;


//线索化就是遍历一次二叉树 
//检查左右节点是否为空 
//若为空将他们改为指向 前驱 或者 后继的线索 还要增加两个标志域ltag rtag
//pre指向刚刚访问过的节点 中序遍历将二叉树线索化
void InThread(ThreadTree &p,Thread &pre)//中序遍历线索化
{
 if(p!=NULL)
 {
 	InThread(p->lchild,pre);//递归 线索化左子树

 	if(p->lchild==NULL)//左子树为空 建立前驱线索
 	{
 		p->lchild=pre；
 		p->ltag=1;
 	}
 	if(pre!=NULL && pre->rchild==NULL)//建立前驱节点后继线索
 	{
 		pre->rchild=p;
 		pre->rtag=1;	
 	}
 	pre=p;//标记当前节点为 刚刚访问过节点

 	InThread(p->rchild,pre);//递归 线索化右子树
 }
}

//中序遍历建立中序线索二叉树
void CreatInThread(ThreadTree T)
{
	ThreadTree pre=NULL;
	if(T!=NULL)
	{
		InThread(T,pre);//非空 线索化二叉树

		pre->rchild=NULL;//处理遍历的最后一个节点
		pre->rtag=1;
	}
}



/*
-----------------------------线索二叉树的遍历-------------------------------------------------
*/
ThreadNode *Firstnode(ThreadNode *p)//求线索二叉树中序序列第一个节点
{
	while(p->ltag==0)
		p=p->lchild;//最左下节点
	returnp;
}

ThreadNode *Nextnode(ThreadNode *p)//求中序线索二叉树 节点p在中序序列下的 后继
{
	if(p->rtag==0)
		return Firstnode(p->rchild);
	else
		return p->rchild;	//rtag==1直接返回后继线索
}

void Inorder(ThreadNode *p)//不含头节点的线索二叉树中序遍历
{
	for(ThreadNode *p=Firstnode(T);p!=NULL;p=Nextnode(p))
		visit p;
}


