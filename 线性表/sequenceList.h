#include <stdlib.h> // malloc realloc

#ifndef SEQUENCE_LIST_H
#define SEQUENCE_LIST_H

// 常量
#define LIST_INIT_SIZE 100
#define LISTINCRECEMENT 10

// 顺序列表结构体
typedef struct {
    int *elem; // 节点地址 初始是第一个节点的地址
    int currentLength; // 当前列表长度
    int currentSize; // 当前存储容量 可用空间
} sqList;

/*
* 初始化列表
* @prama {sqList*} L 一个sqList类型变量
* @return {int} 状态码 0 成功 1 失败
*/
int initList(sqList *L) {
    L -> elem = (int*)malloc(LIST_INIT_SIZE * sizeof(int));
    if(!L -> elem) return 1;
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
* 获取长度
* @return {int} 列表长度
*/
int listLength(sqList L) {
    return L.currentLength;
}

/*
* 插入元素 替换目标位置的元素 后面的元素向后移
* 
*/
int listInsert(sqList *L, int position, int insertElement) {
    //  1 2 3
    int *newElem;
    int *p, *dest;
    int len = L->currentLength;
    // 预计位置超出边界
    if(position < 0 || position > len + 1) {
        printf("超出边界");
        return 1;
    }

    // 内存空间不够 申请空间
    if(L->currentSize <= L->currentLength) {
        newElem = (int*)realloc(L->elem, sizeof(int) * (L->currentSize + LISTINCRECEMENT));
        if(! newElem) {
            printf("申请空间失败");
            return 1;
        }
        // 新的首地址
        L->elem = newElem;
        L->currentSize += LISTINCRECEMENT;
    }

    // 目标地址 指针加中括号相当于后移
    dest = &L->elem[position];

    // 指针p初始位置为 列表的最后
    // 这里的currentLength并没有增加 还没有修改 所以firstNode[L->currentLength]位置是一个空的地址
    for(p = &L->elem[L->currentLength]; p > dest; p--) {
        *p = *(p-1); // 互换值
    }
    
    // 插入
    *dest = insertElement;
    // 修改长度
    L->currentLength++;
    return 0;
}

/*
* push
*/
int push(sqList *L, int pushElement) {
    // 列表末尾插入
    // 0 1 2 _
    int state = listInsert(L, L->currentLength, pushElement);
    return state;
}

/*
* unshift
*/
int unshift(sqList *L, int unshiftElement) {
    // 列表头部插入
    int state = listInsert(L, 0, unshiftElement);
    return state;
}

/*
*  删除某个位置的元素 并用变量返回
*/
int deleteListElement(sqList *L, int position, int *feedBack) {
    int *dest; // 目标指针
    int *last; // 列表末尾指针
    int *i; // 索引指针
    if(position < 0 || position > L->currentLength - 1) {
        printf("删除操作超出边界\n");
        return 1;
    }
    dest = &L->elem[position];
    last = &L->elem[L->currentLength - 1];
    // 返回值
    *feedBack = L->elem[position];

    // 左移元素
    for(i = dest + 1; i <= last; i++) {
        *(i-1) = *i;
    }
    
    L->currentLength--;
    return 0;
}

/*
*   pop
*/
int pop(sqList *L, int *feedBack) {
    if( L->currentLength == 0) {
        printf("列表为空");
        return 1;
    }
    deleteListElement(L, L->currentLength - 1, feedBack);
    return 0;
}

/*
* shift
*/
int shift(sqList *L, int *feedBack) {
    if( L->currentLength == 0) {
        printf("列表为空");
        return 1;
    }
    deleteListElement(L, 0, feedBack);
    return 0;
}

/*
* forEach 遍历列表
* @prmas {*function} void(*callBack)(int, int)
*/
int forEach(sqList *L, void(*callBack)(int, int)) {
    int index;
    if( L->currentLength == 0) {
        printf("遍历列表为空");
        return 1;
    }
    for(index = 0; index < L->currentLength; index++) {
        int item = L->elem[index];
        callBack(item, index);
    }
    return 0;
}

/*
*  将列表清空 不是销毁
*
*/
void clearList(sqList *L) {
    L->currentLength = 0;
}

/*
*  销毁列表
*
*/
void destoryList(sqList *L) {
    // 最重要的是回收分配的内存空间
    // 结构体L的地址 和 元素L.elem的地址不是同一个
    free(L->elem);

    L->elem = NULL;
    L->currentSize = 0;
    L->currentLength = 0;
}

/*
* 获取某个位置的元素
*/
int getListItem(sqList *L, int position, int *feedBack) {
    if(position < 0 || position > L->currentLength - 1) {
        printf("获取元素，超出边界");
        return 1;
    }
    *feedBack = L->elem[position];
    return 0;
}
#endif