//采用递归方法 
//首先交换b的 左孩子的 左右子树，
//然后交换b的 右孩子的 左右子树，
//最后交换b的左右子树
void swap(BiTree b)
{
	swap(b->lchild);
	swap(b->rchild);

	temp=b->lchild;
	b->lchild=b->rchild;
	b->rchild=temp;
}