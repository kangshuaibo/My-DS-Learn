int LeafCount_BiTree(Bitree T)
{
	if(!T)
	    return 0;//空树没有叶子节点
	else if(!T->lchild && !T->rchild) 
		return 1;//根为叶子节点
	else 
		return LeafCount_BiTree(T->lchile)+LeafCount_BiTree(T->rchild)
}













/*
用孩子兄弟链表结构 求树中叶子节点数
*/
//孩子兄弟链表表示的树中 孩子指针为空的是叶子
int Count(CSTree t)
{
	if(t==NULL)
		return 0;
	else if(t->firstchild==NULL)
		return(Count(t->nextsibling)+1);
	else 
		return(Count(t->firstchild)+Count(t->nextsibling))//子女中叶子 加兄弟中叶子
}
