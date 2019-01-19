/*
16.设计一个算法将二叉树的叶结点按从左到右的顺序连成一个单链表,表头指针为head
二叉树按二叉链表方式存储,链接时用叶结点的右指针域来存放单链表指针
*/

//设置前驱指针节点pre初始为空
//第一个叶子节点由指针head指向
//遍历到叶子节点时 就将他的前驱rchild 指针指向他，最后一个叶节点的rchild为空，

LinkedList head,pre=NULL;
LinkedList InOreder(BiTree bt)
{
	if(bt)
	{
		InOreder(bt->lchild);	//中序遍历左子树

		if(bt->lchild==NULL && bt->rchild==NULL)	//叶节点
			if(pre==NULL)
			{
				head=bt;
				pre=bt;
			}
			else//处理第一个节点
			{
				pre->rchild=bt;
				pre=bt;			//叶子节点炼乳链表
			}
		InOreder(bt->rchild); //中序遍历右子树

			pre->rchild=NULL;//设置表尾
	}

}