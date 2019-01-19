/*
◆6.56③试写一个算法,在 先序 后继线索二叉树中,查找给定结点*p在 先序序列
中的后继(假设二叉树的根结点未知)。并讨论实现此算法对存储结构有何要求?
*/
BTNode *PreOrder_Next(BTNode *p)
{
    if(p->ltag==1) 
        return p->rchild;
    else 
        return p->lchild;
}

/*
◆6.56③试写一个算法,在 后序 后继线索二叉树中,查找给定结点*p在 后序序列
中的后继(假设二叉树的根结点未知)。并讨论实现此算法对存储结构有何要求?
*/
Bitree PostOrder_Next(Bitree p)//在后序后继线索二叉树中查找结点 p 的后序后继,并返回指针 
{
if(p->rtag==1) 
	return p->rchild; //p 有后继线索
else if(!p->parent) 
	return NULL; //p 是根结点
else if(p==p->parent->rchild) 
	return p->parent; //p 是右孩子 
else if(p==p->parent->lchild&&p->parent->rtag)
	return p->parent; //p 是左孩子且双亲没有右孩子 
else //p 是左孩子且双亲有右孩子
{
	q=p->parent->rchild; 
	while(q->lchild||!q->rtag) 
	{
	 if(q->lchild) 
	 	q=q->lchild;
	 else 
	 	q=q->rchild;
    } //从 p 的双亲的右孩子向下走到底
return q; 
  }//else
}//PostOrder_Next



/*
1800 88、后序线索二叉树上找 p的直接前驱
*/

//后序遍历为 左-右-根 若节点有右子女，则右子女是其后序前驱，否则，左子女指向其后序前驱 
if(p->rtag==0)
   return (p->rchild);
else
   return (p->lchild);




/*王道
18、写出在 中序线索二又树 里查找指定结点在 后序的 前驱 结点的算法
*/

//在后序序例中
//若节点p有右子女，则右子女是其前驱；若无右子女，而有左子女，则左子女是其前驱
//若节点p左右子女均无，设其 中序左线索指向某祖先节点f（p是f右子树中按中序遍历的第一个节点）
//若f有左子女，则其左子女是节点p在后序下的前驱；
//若f无左子女，则顺其双亲找双亲的双亲，一直找到双亲有左子女（这时左子女是p的前驱）；
//还有一种情况，若p是中序遍历的第一个节点，节点p在中序和后序下均无前驱
BiThrTree InPostPre(BiThrTree t,BiThrTree p)
{
	BiThrTree q;
	if(p->rtag==0)		    //若p有右子女 则右子女是其后序的前驱
		q=p->rchild;
	else if(p->ltag==0) 	//若p只有左子女，左子女是其后序的前驱
		q=p->lchild;
	else if(p->lchild==NULL)	//p是中序序例第一个结点，无后序前驱
		q=NULL;
	else	//顺左线索向上找到p的祖先，若存在，再找祖先的左子女
	{	
		while(p->ltag==1 && p->lchild!=NULL)
			p=p->lchild;
		if(p->lchild==0)
			q=p->lchild;		//p节点的祖先的左子女是其后序的前驱
		else
			q=NULL;				//仅有单只树（p是叶子），已到根节点，p无后序前驱

	}
}



/*
1800 78、写出在 中序线索二又树 里查找指定结点在 前序的 后继 结点的算法
*/

//在前序序例中
//若P有左子女,则左子女就是其前序后继;若p无左子女，而有右子女,则P的右子女就是p的前序后继;
//若p无左右子女,这时沿p的右线索往上,直到p的右标志为0(非线索),
//这时若p的右子女为空,则表示这是中序遍历最后一个结点,故指定结点无前序后继,
//否则,该结点就是指定结点的前序后继。

if(p->ltag==0 && p->lchild!=null) 
	return(p->lchild)  //p左子女是p的前序后继
else if( (p->rtag==0)&& p->rchild! =null ）
	return(p->rchild) //p右子女是其前序后继
else				  //p无左右子女,应沿右线索向上(找其前序后继),直到某结点右标记为
{
	while(p->rtag==1) 
		p=p->rchild;//沿右链向上
	if(p->rchild) 
		return(p->rchild)//指定结点的前序后继
    else return(null);
}

