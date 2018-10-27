//使用后序遍历可以保存当前节点的祖先信息 用一变量 保存栈 最高 栈顶指针
//每当推栈时 栈顶高于保存的 则将该栈倒入辅栈中
void LongestPath(BiTree bt)
{
	BiTree p=bt,l[],s[];
	int i,top=0,tag[],longest=0;
	while( p||top>0)
	{
		while(p)
		{
			s[++top]=p; //根入栈
			tag[top]=0;
			p=p->lchild;//沿左分支向下
		}

		   if(tag[top]==1)//当前节点右分支已遍历
			{
				if( !s[top]->lchild && !s[top]->rchild )//没有左右孩子为叶节点 检查长度
					if(top>longest)
					{
						for(i=1;i<top;i++)
							l[i]=s[i];//保留当前到l栈
						longest=top; //记住最高栈顶指针 退栈
						top--;
					}
			}
			
		else if(top>0)
		{
			tag[top]=1;
			p=s[top].rchild;//沿又分支向下
		}
	}//while
}