#include <stdio.h>
#include "./sequenceList.h"

/*
*  不应该直接使用L.elem[i]去取值
*  直接取值的话 封装的函数便没有了意义 而且混合使用容易出错
*  封装的函数里面 很多都没有真正删除元素 只是将长度简短了而已
*/
void forEachCallBack(int item, int index) {
    printf("item: %d  ", item);
    printf("index: %d\n", index);
}

int main(){
    int deleteElement; // 被删除的元素
    int popElement; // 被pop的元素
    int shiftElement; // 被shift的元素
    int getItem;
    sqList L;

    // 初始化
    initList(&L);
    // 检查是否为空
    isEmpty(L) ? printf("不是空的\n") : printf("是空的\n");
    // 插入元素
    listInsert(&L, 0, 1);
    listInsert(&L, 1, 2);
    listInsert(&L, 0, 3);
    listInsert(&L, 3, 4);
    listInsert(&L, 1, 5);

    // push操作
    push(&L, 6);
    // unshift操作
    unshift(&L, 7);
    // 7351246

    // 删除操作
    deleteListElement(&L, 2, &deleteElement);
    printf("删除的元素是：%d\n", deleteElement);
    // 731246

    // pop操作
    pop(&L, &popElement);
    printf("被pop的元素是：%d\n", popElement);
    // 73124
    
    // shift操作
    shift(&L, &shiftElement);
    printf("被shift的元素是：%d\n", shiftElement);
    // 3124

    // 清空
    clearList(&L);
    push(&L, 6);
    // 6
    
    // destoryList(&L);
    
    // 获取某个值
    getListItem(&L, 0, &getItem);
    printf("获取到的值：%d\n", getItem);
    // forEach
    forEach(&L, forEachCallBack);
    


    return 0;
}