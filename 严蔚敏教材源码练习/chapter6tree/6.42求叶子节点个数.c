int LeafCount_BiTree(Bitree T)
{
	if(!T)return 0;//空树没有叶子节点
	else if(!T->lchild && !T->rchild) return 1;//根为叶子节点
	else return LeafCount_BiTree(T->lchile)+LeafCount_BiTree(T->rchild)
}