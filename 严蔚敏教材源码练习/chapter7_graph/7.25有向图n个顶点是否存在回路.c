/*
◆7.25⑤假设对有向图中n个顶点进行自然编号,并以三个数组s[1..max],fst[1..n]和lst[1..n]表示之。
其中数组s存放每个顶点的后继顶点的信息,第i个顶点的后继顶点存放在s中下标从fst[i]起到lst[i]的分量中(i=1,2,…,n)。
若fsti>lsti],则第i个顶点无后继顶点。试编写判别该有向图中是否存在回路的算法。
*/

void PathDFS(Graph &G,vexindex v)	//在G中国呢找以当前路径为前缀的、达到满足条件P的节点的、所有满足条件Q的简单路径，并打印。v为当前节点
{
	if(!OnCurrentPath[v])
	{
		OnCurrentPath[v]=TRUE;
		EnCurrentPath(v,CurrentPath);	//将当前访问的节点v置为当前路径上的一个新的节点。初始时，数组OnCurrentPath[vexindex]全为假，EnCurrentPath表示往路径中添加节点

		if( P(v)&&Q(CurrentPath) )
			print(CurrentPath);
		else
		{
			w=FirstAdjVex(G.v);
			while(w)
			{
				PathDFS(G,w);
				w=NextADjVex(G,v,w)
			}
			OnCurrentPath[v]=FALSE;
			DeCurrentPath(v,Current);	//把当前节点v从当前路径上删除
		}
	}
}