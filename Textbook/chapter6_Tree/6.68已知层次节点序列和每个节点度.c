Status CreateCSTree_Degree(char node[ ],int degree[ ])//由结点的层序序列和各结点的度构造树的孩子 兄弟链表
{
	CSNode * ptr[MAXSIZE]; //树结点指针的辅助存储 
	ptr[0]=(CSNode*)malloc(sizeof(CSNode));
	i=0;k=1; //i 为当前结点序号,k 为当前孩子的序号 
	while(node[i])
	{
		ptr[i]->data=node[i]; d=degree[i];
		if(d)
		{
			ptr[k]=(CSNode*)malloc(sizeof(CSNode)); //k 为当前孩子的序号 
			ptr[i]->firstchild=ptr[k]; //建立 i 与第一个孩子 k 之间的联系 
			for(j=2;j<=d;j++)
			{
				ptr[k]=(CSNode*)malloc(sizeof(CSNode));
				ptr[k-1]->nextsib=ptr[k]; //当结点的度大于 1 时,为其孩子建立兄弟链表 
				k++;
			}//for ptr[k-1]->nextsib=NULL;
		}//if 

		i++;
		
	}//while
}//CreateCSTree_Degree