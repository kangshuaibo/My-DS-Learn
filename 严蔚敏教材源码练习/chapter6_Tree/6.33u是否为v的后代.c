/*
6.假定用两个一维数组L[N]和R[N]作为有N个结点1,2,…,N的二元树的存储结构。
L[i]和R[i]分别指示结点i的左儿子和右儿子;
L[i]=0 (R[i]=0) 表示i的左(右)儿子为空。试写一个算法,由L和R建立一个一维数组T[n],
使T存放结点i的父亲;然后再写一个判别结点U是否为结点V的后代的算法。
【哈尔滨工业大学1999七(14分)】【华南师范大学2000六(17分)】
*/
for(i=0;i<= N;i++) T[i]=0;//T数组初始化

for(i=1;i<=N;i++)
	if(L[i]!=0)//节点i左子女是L 则节点L双亲是i
		T[L[i]]=i;

for(i=1;i<N;i++)//节点i右子女是R 则节点R双亲是i
	if(R[i]!=0)
		T[R[i]]=i;

int parent=U;//判断U是否为V后代

while(parent!=V && parent!=0)
	parent=T[parent];

if(parent==V)
{
	cout<<"是后代";
 	return 1;
}
else
{
cout<<"不是后代";
return 0;
}

/*6.33③  假定用两个一维数组L[1..n]和R[1..n]作为
有n个结点的二叉树的存储结构， L[i]和R[i]分别指
示结点i的左孩子和右孩子，0表示空。试写一个算法
判别结点u是否为结点v的子孙。*/
int Is_Descendant_C(int u,int v)//在孩子存储结构上判断 u 是否 v 的子孙,是则返回 1,否则返回 0 {
if(u==v) return 1; 
else
{ 
  if(L[v])
	if (Is_Descendant(u,L[v])) return 1;
  if(R[v])
	if (Is_Descendant(u,R[v])) return 1; //这是个递归算法
}




