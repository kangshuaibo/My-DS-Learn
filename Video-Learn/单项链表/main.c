//
//  main.c
//  单项链表
//
//  Created by 张耘博 on 2018/10/16.
//  Copyright © 2018 张耘博. All rights reserved.
//

#include <stdio.h>
#include "LinkList.h" //用尖括号报错：'LinkList.h' file not found with <angled> include; use "quotes" instead提示引号代替：原因：这个头问价为用户自己定义的
typedef struct PERSON{
    char name[64];
    int age ;
    int score;
    
}Person;

void Myprint(void* data){
    Person* p= (Person*)data;
    printf("name:%s  Age:%d  Scord%d\n",p->name,p->age,p->score);
}

int main(int argc, const char * argv[]) {
   //创建链表
    LinkList* list = Init_LinkList();
    
    //创建数据类型
     Person p1={"aaa",18,100};
     Person p2={"bbb",19,99};
     Person p3={"ccc",20,50};
     Person p4={"ddd",17,77};
     Person p5={"eee",16,88};
    
    //数据插入链表
     Insert_LinkList(list, 0, &p1);
     Insert_LinkList(list, 0, &p2);
     Insert_LinkList(list, 0, &p3);
     Insert_LinkList(list, 0, &p4);
     Insert_LinkList(list, 0, &p5);
    
    
    //1、打印
    print_LinkList(list, Myprint);
    
    
    //删除3
    RemoveByPos_LinkList(list, 3);
    
    
    //2、打印
    printf("-----------删除节点后-------------\n");
    print_LinkList(list, Myprint);
    
    
    //返回第一个节点
    printf("------------查找第一个结果------------------\n");
    Person* ret = (Person*)Front_LinkList(list);
    printf("name:%s  Age:%d  Scord%d\n",ret->name,ret->age,ret->score);
    
    
    
    //销毁链表
    FreeSpace_LinkList(list);
    
    
}
