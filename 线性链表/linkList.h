// 链表的顺序 当前元素保存着下一个元素的地址  

#ifndef LINK_LIST_H
#define LINK_LIST_H

#include <stdlib.h> // malloc realloc
#include <stdio.h>

// 那个结构体指针必须写struct 而不是直接LNode *next
typedef struct {
    int data;// 数据
    struct LNode *next; // 指向下一个元素
} LNode;

/*
    为什么这里使用了二级指针？
    下面解释
*/
typedef LNode* LinkList; // LinkList是一个指向指针的指针


/*
*  初始化列表
*  下面的代码并不会正常工作 你会发现你传入的L的data并没有被改变 
*  首先c语言参数传递 都是按值传递的 这个函数的L只是和实参的地址值一样而已  实际上还是两个独立的变量
*  然后这里malloc重新分配了空间给形参 结果就导致形参的地址和实参的地址不一样了  所以在函数执行完毕后实参L的值并没有被改变
*  这就是为什么需要二级指针 来修改指针的地址
*  为什么前面的顺序表没有用二级指针  实际上顺序表也用了相同的道理 顺序表的地址存在了结构体里面 所以相当于用结构体充当了桥梁 和二级指针冲到桥梁一样
*  https://www.zhihu.com/question/41476387/answer/91566794
*  总之 想要在函数里面修改指针的地址 就需要二级指针
*/
int initLinkListErrorCase(LNode *L) {
    // 其实就是生成一个头结点
    L = (LNode*)malloc(sizeof(LNode));
    if(!L) {
        printf("空间不足\n");
        return 1;
    }
    L->data = 10;
    L->next = NULL;
    return 0;
}
/*
*   初始化列表
*/
int initLinkList(LinkList *L) {
    //*L表示一个LinkNode的地址 也就是头指针 必须加括号 不然优先级就不对了
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
int isEmpty(LinkList *L) {
    if(!L || (*L)->next == NULL) {
        return 0;
    }else {
        return 1;
    }
}


#endif