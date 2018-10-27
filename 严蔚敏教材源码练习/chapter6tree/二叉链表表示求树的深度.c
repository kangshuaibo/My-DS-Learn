//层次遍历非递归求二叉树高度（思想用于某一层节点个数/每一层节点个数/树的最大宽度）
int Btdepth(BiTree T)
{
	if(!T)
		return 0;
	int front=-1,rear=-1;
	int last=0,level=0;

	BiTree Q[Maxsize];
	Q[++rear]=T;//根节点入队列
	BiTree p;
	while(front<rear)
	{
		p=Q[++front]; //出队列 正在访问

		if(p->lchild)
			Q[++rear]=p->lchild;
		if(p->rchild)
			Q[++rear]=p->rchild;

		if(front==last)		//		处理最右边节点
		{
			level++;		//层数加一
			last=rear;	//last指向下一层
		}
	}
	return level
}


//递归求二叉树深度
int Btdepth2(BiTree T)
{
	if(T==NULL)
		return 0;
	ldep=Btdepth2(T->lchild);
	rdep=Btdepth2(T->rchild);

	if(ldep>rdep)
		return ldep+1;
	else
		return rdep+1;
}