//根据先序序列确定根节点
//根据根节点在先序序列中划分出左右子树包含哪些节点
//然后根据左右子树节点 在先序序列的次序中的次序确定根节点
BiTree PreInCreat(Elemtype A[],Elemtype B[],int l1,int h1,int l2,int h2)//l1 h1为先序的第一和最后一个节点的下标；l2和h2为中序的第一和最后节点的下标
{
	root=(BiTNode*)malloc(sizeof(BiTNode));
	root->data=A[l1];

	for(i=l2;B[i]!=root->data;i++);//根节点在中序序列的划分
		llen=i-l2;//左子树长度
		rlen=h2-i;//右子树长度
	if(llen)
		root->lchild=PreInCreat(A,B,l1+1,l1+llen,l2,l2+llen-1)
	else
		root->lchild=NULL;
	
	if(rlen)
		root->rchild=PreInCreat(A,B,h1-rlen+1,h1,h2-rlen+1,h2);
	else
		root->rchild=NULL;
	return root;
}