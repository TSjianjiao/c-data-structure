#include <stdio.h>
#include "./sequenceList.c"
// 算法测试

/*
*  不应该直接使用L.elem[i]去取值
*  直接取值的话 封装的函数便没有了意义 而且混合使用容易出错
*  封装的函数里面 很多都没有真正删除元素 只是将长度简短了而已
*/
void forEachCallBack(int item, int index) {
    printf("item: %d  ", item);
    printf("index: %d\n", index);
}

int getItemIndex(int item, int index) {
    if(item >= 2) {
        return 1;
    }else {
        return 0;
    }
}

int main(){
    /****** 基本操作 *****/
    {
        int deleteElement; // 被删除的元素
        int popElement; // 被pop的元素
        int shiftElement; // 被shift的元素
        int getItem; // 获取某个位置的值
        int itemIndex; // 某个元素的索引
        int prevNode; // 前驱节点
        int nextNode; // 后驱节点

        sqList L;

        // 初始化
        initList(&L);
        // 检查是否为空
        isEmpty(&L) ? printf("不是空的\n") : printf("是空的\n");
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
        push(&L, 1);
        push(&L, 2);
        push(&L, 3);
        push(&L, 4);
        // 1234
    
        //destoryList(&L);

        // 获取某个值
        getListItem(&L, 2, &getItem);
        printf("获取到的值：%d\n", getItem);

        // 获取某个值的位置
        itemIndex = findIndex(&L, getItemIndex);
        printf("获取到的索引：%d\n", itemIndex);

        // 获取前驱
        priorElem(&L, 4, &prevNode);
        printf("获取到的前驱节点值：%d\n", prevNode);

        // 获取后驱
        nextElem(&L, 3, &nextNode);
        printf("获取到的后驱节点值：%d\n", nextNode);

        // forEach
        forEach(&L, forEachCallBack);
    }
    
    
    /****** 算法2.1 union操作  *****/

    {
        // 合并两个列表到L1 只保留不同的
        sqList L1;
        sqList L2;
        initList(&L1);
        initList(&L2);
        // L1
        push(&L1, 1);
        push(&L1, 2);
        push(&L1, 3);
        push(&L1, 4);
        // L2
        push(&L2, 4);
        push(&L2, 3);
        push(&L2, 6);
        push(&L2, 1);
        push(&L2, 10);
        Union(&L1, &L2);
        printf("***********union操作************\n");
        forEach(&L1, forEachCallBack);
    }

    /****** 算法2.2 merge合并操作  *****/
    {
        sqList L1;
        sqList L2;
        sqList L3;
        initList(&L1);
        initList(&L2);
        initList(&L3);
        // L1
        push(&L1, 1);
        push(&L1, 2);
        push(&L1, 3);
        push(&L1, 4);
        // L2
        push(&L2, 2);
        push(&L2, 4);
        push(&L2, 5);
        push(&L2, 8); 
        push(&L2, 9);
        // 1 2 2 3 4 4 5 8 9
        mergeList(&L1, &L2, &L3);
        printf("***********merge操作************\n");
        forEach(&L3, forEachCallBack);
    }

    return 0;
}