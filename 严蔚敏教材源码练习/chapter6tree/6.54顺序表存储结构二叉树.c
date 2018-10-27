/*
假设顺序表sa表示一棵完全二叉树，sa.elem[sa.last]中存放 树中各个节点的元素数据。
试编写算法由此顺序表存储结构建立该二叉树的二叉链表
*/
BiTree Creat(ElemType A[],int i)
{
	BiTree tree;
	if(i<=n)
	{
		tree=new(BiNode);
		tree->data=A[i];
		
		if(2*i>n)
			tree->lchild=Creat(A,2*i);
		if(2*i+1>n)
			tree->rchild=NULL;
		else
			tree->rchild=Creat(A,2*i+1);
	}
	return tree;
}