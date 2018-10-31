/*
◆6.60③试编写算法,对一棵以孩子兄弟链表表示的树统计叶子的个数。----------------------------------
*/
//孩子兄弟链表表示 孩子指针为空的节点是叶子
int Count(CSTree t)
{
	if(t==NULL)
		return 0;
	else if(t->firstlchild==null)
		return(1+Count(t->nextsibling));
	else 
		return(Count(t->firstlchild)+Count(t->nextsibling));
}


//6.61③试编写算法,求一棵以 孩子-兄弟链表 表示的树的度
int GetDegree_CSTree(CSTree T)//求孩子兄弟链表表示的树 T 的度 
{
 if(!T->firstchild) 
 	return 0; //空树 
 else
 {
	degree=0;
	for(p=T->firstchild;p;p=p->nextsib) 
		degree++;//本结点的度 
	for(p=T->firstchild;p;p=p->nextsib)
	{
	 d=GetDegree_CSTree(p);
	 if(d>degree) 
		degree=d; //孩子结点的度的最大值
 
  	}
	return degree; 
   }//else
}//GetDegree_CSTree



//◆6.62④对以 孩子兄弟链表 表示的树编写计算树的深度的算法--------------------------------
int GetDepth_CSTree(CSTree T)
{
	if(!T)
		return 0;//空树
	else
		{
			for(maxd=0,p=T->firstchild;p;p=p->nextsib)
				if((d=GetDepth_CSTree(p))>maxd)
					maxd=d;
			return maxd+1;
		}
}


			//1800

			//若树为空，高度为0；若第一子女为空，高度为1和兄弟子树高度的大者；
			//否则高度为第一子女树高度加1和兄弟子树高度的大者
			//非递归使用队列

			//递归算法-----------
			if(bt==NULL)
			return 0;
			else if(!bt->firstchild)
				return(max(1,height(bt->nextsibling)));
			else
			{
				hc=height(bt->firstchild);//第一子女树高
				hs=height(bt->nextsibling);
				if(hc+1>hs)
					return (hc+1);
				else
					return hs;
			}

			//非递归-------------
			Q[rear]=t;			//Q以树中节点为元素的队列
			while(front<=last）    //队列的初始front=rear=1
			{
				t=Q[front++];  //出队
				while(t!=NULL) //层次遍历
				{
					if(t->firstchild)
						Q[++rear]=t->firstchild;
					t=t->nextsibling;//同层兄弟指针后移
				}
			}




//6.63③对以 孩子链表 表示的树编写计算树的深度的算法-------------------------------
int GetDepth_CTree(CTree A)//求孩子链表表示的树 A 的深度 
{
	return SubDepth(A.r); 
}//GetDepth_CTree

int SubDepth(int T)//求子树 T 的深度 
{
  if(!A.nodes[T].firstchild )
 	return 1; 
  for(sd=1,p=A.nodes[T].firstchild;p;p=p->next)
	if((d=SubDepth(p->child))>sd) 
		sd=d; 
	return sd+1;
}//SubDepth







/*
6.64④对以 双亲表 表示的树编写计算树的深度的算法。------------------------------------------
*/

//以双亲表示法做树的存储结构，对美一对节点，找其双亲，双亲的双亲，直到根节点。
//就可以求出每一节点的层次，取其节点最大层就是树的深度

int GetDepth_PTree(PTree T)//求双亲表表示的树 T 的深度
{ int maxdepth=0;
  for(i=1;i<=t;i++)
  {
	temp=0;f=i;
	while(f>0)
	{
		temp++;
		f=t.nodes[f].parent;
	}
	if(temp>maxdepth)
		maxdepth=temp;
   }
return maxdepth;
}



































