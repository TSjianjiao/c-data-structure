#include <stdlib.h>

#ifndef SEQUENCE_LIST_H
#define SEQUENCE_LIST_H

// 常量
#define LIST_INIT_SIZE 100
#define LISTINCRECEMENT 10

// 顺序列表结构体
typedef struct {
    int *firstNode; // 第一个节点地址
    int currentLength; // 当前长度
    int currentSize; // 当前存储容量
} sqList;

/*
* 初始化列表
* @prama {sqList*} L 一个sqList类型变量
* @return {int} 状态码 0 成功 1 失败
*/
int initList(sqList *L) {
    L -> firstNode = (int*)malloc(LIST_INIT_SIZE * sizeof(int));
    if(!L -> firstNode) return 1;
    L -> currentSize = LIST_INIT_SIZE;
    L -> currentLength = 0;
    return 0;
}

/*
* 是否是空列表
* @return {int} 状态码 0 为空 1 不为空
*/
int isEmpty(sqList L) {
    return L.currentLength == 0 ? 0 : 1;
}

/*
* 插入元素
* 
*/
int insertBefore(sqList *L, int position, int insertElement) {
    if(position < 1 || position > L -> currentLength + 1)
}




#endif