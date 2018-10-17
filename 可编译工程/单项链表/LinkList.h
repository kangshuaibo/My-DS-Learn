//
//  Linklist.h
//  单项链表
//
//  Created by 张耘博 on 2018/10/16.
//  Copyright © 2018 张耘博. All rights reserved.
//

#ifndef LinkList_h
#define LinkList_h

#include <stdio.h>
#include <stdlib.h>



//链表节点
typedef struct LINKNODE{
    void* data; //指向任何类型数据
    struct LINKNODE* next;
}LinkNode;

//链表结构体
typedef struct LINKLIST{
    LinkNode* head;
    int size;
}LinkList;
//打印
typedef void(*PRINTLINKNODE)(void*);
    


//链表初始化
LinkList* Init_LinkList(void);

//在指定位置插入
void Insert_LinkList(LinkList* List,int pos,void* data);

//删除指定节点的值
void RemoveByPos_LinkList(LinkList* List,int pos);

//获得链表的长度
int Size_LinkList(LinkList *list);

//查找
int Find_LinkList(LinkList* list,void* data);

//返回第一个节点
void* Front_LinkList(LinkList *list);

//释放链表内存
void FreeSpace_LinkList(LinkList* list);

//打印链表节点
void print_LinkList(LinkList* list,PRINTLINKNODE print);





#endif /* Linklist_h */
