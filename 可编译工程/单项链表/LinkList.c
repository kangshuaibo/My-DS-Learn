//
//  Linklist.c
//  单项链表
//
//  Created by 张耘博 on 2018/10/16.
//  Copyright © 2018 张耘博. All rights reserved.
//

#include "LinkList.h"
//初始化链表
LinkList* Init_LinkList()
{
    LinkList* list = (LinkList*)malloc(sizeof(LinkList));
    list->size=0;
    
    //头结点不保存数据信息
    list->head = (LinkNode*)malloc(sizeof(LinkNode));
    list->head->data = NULL;
    list->head->next = NULL;
                                  
    
    
    return list;
}

//在指定位置插入
void Insert_LinkList(LinkList* List,int pos,void* data)
{
    if(List==NULL)
        return;
    if(data== NULL)
        return;
    //pos越界,友好判断
    if(pos < 0 || pos > List->size)
        pos = List->size;
    //创建新的节点
    LinkNode* newnode = (LinkNode*)malloc(sizeof(LinkNode));
    newnode->data = data;
    newnode->next = NULL;
    
    //找节点
    //辅助指针变量
    LinkNode* pCurrent = List->head;
    for(int i=0;i<pos;i++)
    {
        pCurrent = pCurrent->next;
    }
    
    //新节点入链表
    newnode->next = pCurrent->next;
    pCurrent->next =newnode;
    
    List->size++;
    
    
}

//删除指定节点的值
void RemoveByPos_LinkList(LinkList* List,int pos)
{
    if(List==NULL)
    {
        return;
    }
    if(pos <0||pos >= List->size)
    {
        return;
    }
    //查找删除节点的前一个节点
    LinkNode* pCurrent = List->head;
    for(int i=0;i<pos;i++)
    {
        pCurrent = pCurrent->next;
    }
    //缓存删除的节点
    LinkNode* pDel = pCurrent->next;
    pCurrent->next=pDel->next;
    free(pDel);
    List->size--;
    
    
        
    
}

//获得链表的长度
int Size_LinkList(LinkList *list)
{
    
    return list->size;
}

//查找(指定数据)
int Find_LinkList(LinkList* List,void* data)
{
    if(List==NULL)
    {
        return -1;
    }
    if(data==NULL)
    {
        return -1;
    }
    //遍历查找
    //辅指针
    LinkNode* pCurrent = List->head->next;//由于头节点不保存数据从头节点的下一个开始遍历数据
    int i=0;
    while(pCurrent!=NULL)
    {
        if(pCurrent->data==data)
        {
            break;
        }
        i++;
        pCurrent=pCurrent->next;
    }
    
    return i;
}

                                    
                                    
//返回第一个节点
void* Front_LinkList(LinkList *list)
{
    
    return list->head->next->data;
}

        
        
                                    
//打印链表节点
void print_LinkList(LinkList* list,PRINTLINKNODE print)
{
    if(list==NULL)
    {
        return;
    }
    //辅助指针变量
    LinkNode* pCurrent = list->head->next;
    while(pCurrent!=NULL){
        (*print)(pCurrent->data);//相当于 Myprint(pCurrent->data)
        pCurrent=pCurrent->next;
    }
    
    
}
                                    
                                    
//释放链表内存
void FreeSpace_LinkList(LinkList* list)
{
    if(list==NULL)
    {
        return;
    }
    //辅助指针变量
    LinkNode* pCurrent = list->head;
    while(pCurrent!=NULL)
    {
        //缓存下一个节点
        LinkNode* pNext = pCurrent->next;
        free(pCurrent);
        pCurrent=pNext;
    }
    //释放链表内存
    list->size=0;
    free(list);
    
}


