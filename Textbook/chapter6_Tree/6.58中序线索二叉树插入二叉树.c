/*
◆6.58④试写一个算法,在中序全线索二又树的结点*p之下,插入一棵以结点*x
为根、只有左子树的中序全线索二叉树,使*x为根的二叉树成为*p的左子树。若*p
原来有左子树,则令它为*x的右子树。完成插入之后的二叉树应保持全线索化特性。
*/

//要对x有无左右子树进行讨论,并修改X左(右)子树上最左结点和最右结点的线索。
//在中序线索树上查找某结点P的前驱的规律是:
//若p>lag=1,则p-> lchild就指向前驱,否则,其前驱是p的左子树上按中序遍历的最后一个结点,
//查找某结点P的后继的规律是:若P>g1,则p> rchild就指向后继,否则,其后继是p的右子树上按中序遍历的第一个结点。
//这里只讨论P有左子女,将X插为P的右子女的情况。核心语句段如下
if(p->ltag==0)//P有左子女,将X插为P的右子女
{ if(x->ltag==1)
	x->lchild=P;//若X无左子树,X的左线索(前驱)是P
  else			//寻找X的左子树上最左(下)边的结点
	{
		q=x->lchild
		while(q->ltag==0)q=q->lchild
		q->lchild=p
    }
  if(x->rtag==l)
	x->rchild=p->rchild//修改x的右线索,将p的右线索改为X的右线索
  else//找x右子树最右面的结点
  {
	q=x->rchild
	while(q->rtag==0) q=q->rchild;
	q->rchild=P->rchild;
  }
  p->rtag=0;p->rchild=x;
}




/*
设t是一棵按后序遍历方式构成的线索二叉树的根结点指针,试设计一个非递归的算法,把
个地址为x的新结点插到t树中已知地址为y的结点右侧作为结点y的右孩子,并使插入
后的二叉树仍为后序线索二叉树。【东北大学1996七(15分)】
*/
//在线索二叉树上 插入节点破坏了被插入节点的线索 
//在节点y右侧插入节点x 因为是后序线索树，要区分节点y有无左子树
//设y无右子树
if(y->ltag==0)	//y有左子女
{
	p=y->lchild;
	if(p->rtag==1)
		p->rchild=x;//x是y左子女的后序后继
	x->ltag=1;
	x->lchild=p;	//x的左线索是y的左子女
}
else			//y无左子女
{
	x->ltag=1;
	x->lchild=y->lchild;//y左线索为x左线索
	if(y->lchild->rtag==1)// y的后序前驱 右标记为1
		y->lchild->rchild=x;//则y的后序前驱的后继改为x
}
