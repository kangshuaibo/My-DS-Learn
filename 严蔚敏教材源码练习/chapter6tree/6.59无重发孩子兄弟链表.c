/*
6.59③编写算法完成下列操作:无重复地输出以孩子兄弟链表存储的树T中所有
的边。输出的形式为(k1,k2),…,(k,k),…,其中,k和k,为树结点中的结点标识。
*/

void Print_CSTree(CSTree T)//输出孩子兄弟链表表示的树 T 的各边
 {
	for(child=T->firstchild;child;child=child->nextsib) 
	{
	printf("(%c,%c),",T->data,child->data);
	Print_CSTree(child);
	}
}//Print_CSTree