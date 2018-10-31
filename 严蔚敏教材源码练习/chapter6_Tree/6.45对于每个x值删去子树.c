//删除以元素值x为根的子树 只要能删除其左右子树 就可以释放值为x的根节点
//因此 后序遍历

//删除值为x的节点，意味着应将其父节点 的左/右子女指针置空，
//层次遍历易找到 某节点的父节点 

//本题要删除树中每个元素值为x的节点的子树
//要遍历整个完整二叉树

void DeleteXTree(BiTree bt)//删除以bt为根的子树
{
	if(bt)
	{
		DeleteXTree(bt->lchild);//删左子树
		DeleteXTree(bt->rchild);
		free(bt);
	}
}

void Search(BiTree bt,ElemType x)//在二叉树中找到所有x值节点 并删除其子树
{
	BiTree Q[];//存放二叉树节点指针的队列 容量足够大
	if(bt)
	{
		if(bt->data=x)
		{
			DeleteXTree(bt);
			exit 0;
		}

		InitQueue(Q);//层次遍历用到 队列

		EnQueue(Q,bt);根节点入队
		while(!IsEmpty(Q))
		{
			DeQueue(Q,p)//出队
			if(p->lchild)				//左子女非空
				if(p->lchild->data==x)	//左子树符合 则删除左子树
				{
					DeleteXTree(p->lchild);
					p->lchild=NULL;			//父节点左子女置空
				}
				else
					EnQueue(Q,p->lchild);//左子树入队
			if(p->rchild)			//右子女非空
				if(p->rchild->data==x)//右子女符合则删除右子树
				{
					DeleteXTree(p->rchild);
					p->rchild=NULL;
				}
				else
					EnQueue(Q,p->rchild);//右子女入队列

		}
	}
}

