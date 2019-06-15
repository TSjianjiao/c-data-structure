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
*   关键函数是 初始化initList 和 插入元素listInsert
*/

/*
* 初始化列表
* @prama {sqList*} L 一个sqList类型变量
* @return {int} 状态码 0 成功 1 失败
* 算法2.3
*/
int initList(sqList *L);

/*
* 是否是空列表
* @return {int} 状态码 0 为空 1 不为空
*/
int isEmpty(sqList *L);

/*
* 获取长度
* @return {int} 列表长度
*/
int listLength(sqList L);
/*
* 插入元素 替换目标位置的元素 后面的元素向后移
* 算法2.4
*/
int listInsert(sqList *L, int position, int insertElement);

/*
* push
*/
int push(sqList *L, int pushElement);

/*
* unshift
*/
int unshift(sqList *L, int unshiftElement);

/*
*  删除某个位置的元素 并用变量返回
*  算法2.5
*/
int deleteListElement(sqList *L, int position, int *feedBack);

/*
*   pop
*/
int pop(sqList *L, int *feedBack);

/*
* shift
*/
int shift(sqList *L, int *feedBack);

/*
* forEach 遍历列表
* @prmas {*function} void(*callBack)(int, int)
*/
int forEach(sqList *L, void(*callBack)(int, int));

/*
*  将列表清空 不是销毁
*
*/
void clearList(sqList *L);

/*
*  销毁列表
*
*/
void destoryList(sqList *L);

/*
* 获取某个位置的元素
*/
int getListItem(sqList *L, int position, int *feedBack);

/*
* findIndex 
* @returns 失败返回-1 成功返回第一个匹配的索引
* c99之前没有 布尔值 所以用0,1代替
* 算法2.6
*/
int findIndex(sqList *L, int(*callBack)(int, int));



/*
* 返回某个元素的前驱节点
* 由于第二个参数 参考点直接传的值 所以这个函数不能区分重复值
*/
int priorElem(sqList *L, int current, int *prev);

/*
* 获取后驱
*/
int nextElem(sqList *L, int current, int *next);
#endif