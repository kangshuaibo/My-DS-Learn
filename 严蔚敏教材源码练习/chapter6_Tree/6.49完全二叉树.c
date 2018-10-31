/*
根据完全二叉树的定义
具有n个节点的完全二叉树 与 满二叉树中的编号从1～n的节点一一对应
*/

//采用层次遍历 将所有节点加入队列(包括空节点)。
//当遇到空节点时，再查看其后是否有非空节点。若有则不是

bool IsComplete(BiTree T)
{
	InitQueue(Q);
	if(!T)
		return 1;	//空树为满二叉树
	Enqueue(Q,T);
	while(!IsEmpty(Q))
	{
		DeQueue(Q,p);

		if(p)	//节点非空 将其左右孩子入队列
		{
			EnQueue(Q,p->lchild);
			EnQueue(Q,p->rchild);
		}
		else			//节点空 检查后面是否还有非空节点
			while(!IsEmpty(Q))
			{
				DeQueue(Q,p);
				if(p)
					return 0;

			}
	}
	return 1;
} 