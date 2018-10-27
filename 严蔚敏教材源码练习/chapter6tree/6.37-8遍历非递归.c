//中序遍历非递归算法
/*
先扫描（非访问）根节点所有左节点并一一进栈，然后出栈 访问他
然后扫描该节点的右孩子节点 将其进栈
再扫描右孩子节点的所有左节点并将其一一进栈
直到栈空
*/
void InOrder2(BiTree T)
{
	InitStack(S); BiTree p=T;//初始化栈 p是遍历指针
	while(p||!IsEmpty(S))//栈不空 或p不空时循环
	{
		if(p)
		{				//根进栈 遍历左子树 （每遇到非空二叉树 向左走）
			Push(S,p);
			p=p->lchild;
		}
		else//退栈时访问 遍历右子树
		{
			Pop(S,p);
			visit(p);
			p=p->rchild;
		}
	}

}

//先序遍历非递归算法
void PreOrder2(BiTree T)
{
	InitStack(S);
	BiTree p=T;
	while(p||!IsEmpty(S))
	{
		if(p)
		{			//根进栈就访问 遍历左子树 （每遇到非空二叉树 向左走）
			Push(S,p);
			visit(p);
			p=p->lchild;
		}
		else 	//退栈 遍历右子树
		{
			Pop(S,p);
			p=p->lchild;
		}
	}
}


//后序遍历非递归算法
/*
要用到栈
先访问左子树再访问右子树最后访问根节点 故访问根节
点要分是从左子树反回的还是右子树返回的 增加辅助指针r
*/
void PosOrder2(BiTree T)
{
	InitStack(S);
	BiTree p=T;
	r=NULL;
	while(p||!IsEmpty)
	{
		if(p)
		{				//走到最左
			Push(S,p);
			p=p->lchild;
		}
		else 	//向右
		{
			GetTop(S,p);
			if(p->rchild && p->rchild!=NULL) //右子树存在 且未被访问过
				{
					p=p->rchild;//向右转
					Push(S,p);//压入栈
					p=p->lchild;再走到最左
				}
				else
				{
					Pop(S.p);//弹出并访问
					visit(p->data);
					r=p;//记录被访问过
					r=NULL;
				}
		}
	}
}

