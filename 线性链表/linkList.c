#ifndef LINK_LIST_C
#define LINK_LIST_C
#include <stdlib.h> // malloc realloc
#include <stdio.h>
#include "linkList.h"
/****基本操作****/
/*
*   初始化列表
*   为什么这里使用了二级指针？
*/
int initLinkList(LinkList *L) {
    //*L LNode*的指针 也就是二级指针
    // 直接使用L 会在下面开辟空间时导致形参和实参指向不同的地址
    // 修改就会无效
    (*L) = (LNode*)malloc(sizeof(LNode));
    if(!(*L)) {
        printf("空间扩展失败");
        return 1;
    }
    (*L)->next = NULL;
    return 0;
}


/*
*   是否为空
*/
int isEmpty(LinkList header) {
    if(header->next == NULL) {
        return 0;
    }else {
        return 1;
    }
}

/*
* 算法2.9
* 插入元素
*/
int insertItem(LinkList header, int position, int item) {
    LinkList current = header;
    // 一定要用指针 不然就是一个局部变量 函数执行完就没有了
    // 指针记得初始化
    LNode *newNode = (LNode*)malloc(sizeof(LNode)); 
    int index = 0;
    // 0 1 2 3 // 注意范围 从0开始
    // 假设要插入位置是1 在链表中位置是2 需要知道位置2前一个节点的信息也就是链表里的1
    // 当index=0时current指向链表位置1的地址
    // 这样current总是表示目标位置前一个节点
    while(index < position){
        if(!current->next){break;}
        current = current->next; // 小心不能让current=NULL
        index++;
    }
    newNode->data = item;
    newNode->next = current->next;
    current->next = newNode;
    return 0;
}

/*
*   算法2.8
*   获取某个位置的元素
*   没找到会返回最后一个值
*/
LNode getItem(LinkList header, int position) {
    LinkList current = header;
    int index = 0;
    // h 1 2 3
    while(index <= position) {
        current = current->next;
        index++;
    }
    return (*current);
}

/*
*   遍历节点
*   @prams {LinkList} header 头结点
*   @prams {function} callBack 回调函数 第一个参数是节点值，第二个参数表示索引
*/
void forEach(LinkList header, void(*callBack)(int, int)) {
    LinkList prev = header;
    int index = 0;
    if(!isEmpty(header)) {
        printf("链表为空\n");
        return;
    }
    while(1) {
        prev = prev->next;
        // printf("指针地址%p", (*prev).next);
        callBack(prev->data, index);
        if(!prev->next)break;
        index++;
    }
}

/*
*   获取链表长度
*/
int getLength(LinkList header) {
    LinkList prev = header;
    int count = 0;
    if(!isEmpty(header)) {
        printf("链表为空\n");
        return 0;
    }
    while(prev->next) {
        prev = prev->next;
        count++;
    }
    return count;
}

/**
 * 获取目标位置的前驱
 */
LNode getPrevNode(LinkList header, int position) {
    LinkList current = header;
    int index = 0;
    if(!isEmpty(header)) {
        printf("链表为空\n");
    }
    while(index < position && current->next) {
        current = current->next;
        index++;
    }
    if(index < position) {
        printf("非法位置\n");
        current = header->next;
    }
    if(current == header) {
        printf("首节点没有前驱\n");
        current = header->next;
    }
    return (*current);
}

/**
 * 获取目标位置后驱
 * 没有找到返回首节点
 */
LNode getNextNode(LinkList header, int position) {
    LinkList current = header;
    int index = 0;
    if(!isEmpty(header)) {
        printf("链表为空\n");
    }
    while(index <= position + 1) {
        current = current->next;
        index++;
    }
    if(!current) {
        printf("尾节点没有后驱\n");
        current = header->next;
    }
    return (*current);
}

/*
*   算法2.10
*   删除某个位置的节点
*/

int deleteNode(LinkList header, int position) {
    LinkList current = header;
    LNode *prevNode;
    int res;
    int index = 0;
    if(!isEmpty(header)) {
        printf("链表为空\n");
    }

    // 找前驱
    while(index <= position && current->next) {
        prevNode = current;
        current = current->next;
        index++;
    }
    prevNode->next = current->next;
    res = current->data;
    // 释放被删除的节点
    free(current);
    return res;
}

/**
 * 末尾插入push
 */
int push(LinkList header, int item) {
    LinkList current = header;
    LNode *newNode = (LNode*)malloc(sizeof(LNode));
    while(current->next) {
        current = current->next;
    }
    newNode->data = item;
    newNode->next = NULL;
    current->next = newNode;
    return 0;
}

/**
 * unshift
 */
int unshift(LinkList header, int item) {
    LinkList current = header;
    LinkList newNode = (LinkList)malloc(sizeof(LNode));
    newNode->data = item;
    newNode->next = current->next;
    current->next = newNode;
    return 0;
}

/**
 * pop
 * 返回出栈的data 空链表返回-1
 */
int pop(LinkList header) {
    LinkList current = header;
    LinkList prevNode;
    int res = -1;
    if(!isEmpty(header)) {
        printf("链表为空\n");
        return res;
    }
    while(current->next) {
        prevNode = current;
        current = current->next;
    }
    prevNode->next = NULL;
    res = current->data;
    free(current);
    return res;
}

/**
 * shift
 */
int shift(LinkList header) {
    LinkList firstNode;
    int res = -1;
    if(!isEmpty(header)) {
        printf("链表为空\n");
        return res;
    }
    firstNode = header->next;
    header->next = firstNode->next;
    res = firstNode->data;
    free(firstNode);
    return res;
}

/**
 * 按规则查找元素 返回索引
 */
int findIndex(LinkList header, int (*callBack)(int, int)) {
    LinkList current = header;
    int index = 0;
    if(!isEmpty(header)) {
        printf("链表为空\n");
        return -1;
    }
    while(current->next) {
        current = current->next;
        if(!callBack(current->data, index)){
            return index;
        }
        index++;
    }
    return -1;

}
/**
 * 清空列表 保留头结点
 */
int clearList(LinkList header) {
    LinkList current = header;
    LinkList prevNode;
    int index = 0;
    while(current->next) {
        if(index > 1) {
            free(prevNode);
        }
        prevNode = current;
        current = current->next;
        index++;
    }
    header->next=NULL;
    return 0;
}

/**
 * 摧毁列表
 */
int destoryList(LinkList header) {
    clearList(header);
    free(header);
    return 0;
}
/**********基本操作***********/

/** 应用 */
/**
 * 算法2.11
 * 逆序产生链表
 */
void creatList(LinkList *header, int count) {
    int input;
    LNode *newNode;
    (*header) = (LNode*)malloc(sizeof(LNode));
    (*header)->next = NULL;
    while(count > 0) {
        scanf("%d", &input);
        // 注意newNode每次都要重新分配新空间 相当于创建一个新变量
        newNode = (LNode*)malloc(sizeof(LNode));
        newNode->data = input;
        newNode->next = (*header)->next;
        (*header)->next = newNode;
        count--;
    }
}

/**
 * 算法2.12
 * 将列表倒转
 * https://www.cnblogs.com/huangxincheng/p/4051854.html
 */
LinkList reverse(LinkList header) {
    LinkList current = header;
    LinkList prevNode;
    if(!current->next) return current;
    prevNode = reverse(current->next);
    

}   

#endif