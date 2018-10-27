/*只增设一个双亲节点能否不设栈 中序遍历*/


typedef struct 
{
	int data;
    PBTNode *lchild; 
    PBTNode *rchild; 
    PBTNode *parent;
} PBTNode,PBitree; //有双亲指针域的二叉树结点类型 
void Inorder_Nonrecursive(PBitree T)//不设栈非递归遍历有双亲指针的二叉树
{ 
    p=T;
	while(p->lchild) p=p->lchild; //向左走到尽头 
	while(p)
	{
    	visit(p);

		if(p->rchild) //寻找中序后继:当有右子树时 
		{
		  p=p->rchild;
		  while(p->lchild) 
		  	p=p->lchild; //后继就是在右子树中向左走到尽头 
		}

		else if(p->parent->lchild==p) 
			p=p->parent; //当自己是双亲的左孩子时后继就是双亲 
		else
		{
			p=p->parent; 
			while(p->parent && p->parent->rchild==p) 
				p=p->parent; 
		    p=p->parent;
		} //当自己是双亲的右孩子时后 继就是向上返回直到遇到自己是在其左子树中的祖先 
}//while