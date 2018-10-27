//采用先序遍历的递归方法，当找到叶子结点*b时，
//由于*b叶子结点尚未添加到path中，因此在输出路径时还需输出b->data值。
void AllPath(BTNode *b,ElemType path[],int pathlen)
{
	int i;
	if(b!=NULL)
	{
		    if(b->lchild==NULL && b->rchlid==NULL)//*b为叶子节点
			{
				cout<<" "<<b->data<<"到根节点路径：";
				for(i=pathlen-1;i>=0;i)
					cout<<path[i]->data<<endl;//换行
			}
			else
			{
				path[pathlen]=b->data;  //当前节点放入到路径中
				pathlen++; 				//路径长度增加
				AllPath(b->lchild,path,pathlen);
				AllPath(b->rchlid,path,pathlen);
				pathlen--;//恢复
			}
	}
}