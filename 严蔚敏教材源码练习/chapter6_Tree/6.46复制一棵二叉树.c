//递归
BiTree Copy(BiTree t)
{
	BiTree bt;
	if(t==NULL)
		bt=NULL;
	else
	{
		bt=new(BiNode);
		bt->data=t->data;
		bt->lchild=Copy(t->lchild);
		bt->rchild=Copy(t->rchild);
	}
	return bt;
}



//非递归算法
QueueIn(Q,(t,bt));
while(!QueueIsEmptu(Q))
{
	(t,bt)=QueueOut(Q);
	bt=new(BiNode);
	bt->data=t->data;
	
	if(t->lchild)
		QueueIn(Q,(t->lchild,bt->lchild));
	else 
		bt->lchild=NULL;

	if(t->rchild)
		QueueIn(Q,(t->rchild,bt->rchild));
	else
		bt->rchild=NULL;

}