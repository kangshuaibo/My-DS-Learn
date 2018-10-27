/*
46.假设在二又链表的结点中增设两个域: parent域以指示其双亲结点;fag域(取值为0..2)
以区分在遍历过程中到达该结点时应继续向左或向右或访问该结点。试以此存储结构编写
不用栈进行后序遍历的递推形式的算法。【中南大学2004三(10分)】
*/
//后序遍历为‘左右根’查找节点后继节点要通过双亲 因此设置节点结构为（lchild,data,rchild,parent,falg)
//a、遍历中当flag=0时置flag=1，并遍历左子树，
//b、当flag=1时置为2并遍历右子树，
//c、当flag=2时访问节点，同时恢复flag=0,再去查找其双亲

switch(p->falg)
{
	case 0:p->flag=1;
		if(p->lchild)	
			p=p->lchild;break;
	case 1:p->flag=2;
		if(p->rchild)	
			p=p->rchild;break;
	case 2:p->flag=0;
		if(p->data) printf("p->data");
			p=p->parent;
}