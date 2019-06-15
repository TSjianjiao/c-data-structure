#include "./linkList.c"

void printList(int item, int index) {
    printf("第%d个，值为%d\n", index, item);
}

int findIndexCB(int item, int index) {
    // 返回第一个大于2的元素的索引
    if(item > 2) {
        return 0;
    }else {
        return 1;
    }
}

int main() {
    
    /**********基本操作***********/
    {
        // 初始化

        LinkList header; // 头指针
        initLinkList(&header);
        
        // 插入
        
        insertItem(header, 0, 1);
        insertItem(header, 1, 2);
        insertItem(header, 2, 3);
        insertItem(header, 1, 4);
        insertItem(header, 4, 5);
        // h 1 4 2 3 5
        // 是否为空
        !isEmpty(header) ? printf("链表为空\n") : printf("链表非空\n");
        
        // 获取某个位置的元素
        printf("获取到的元素是%d\n", getItem(header, 2).data);

        // 获取指定位置的前驱
        printf("前驱节点的数据为%d\n", getPrevNode(header, 2).data);

        // 获取指定位置后驱
        printf("后驱节点的数据为%d\n", getNextNode(header, 2).data);

        // 遍历元素
        forEach(header, printList);

        // 链表长度
        printf("链表长度为%d\n", getLength(header));

        // 删除指位置的节点
        printf("被删除的节点是%d\n", deleteNode(header, 1));
        forEach(header, printList); // h 1 2 3 5

        // push
        printf("push操作\n");
        push(header, 6);
        forEach(header, printList);//h 1 2 3 5 6

        // unshift
        printf("unshift操作\n");
        unshift(header, 7);
        forEach(header, printList);//h 7 1 2 3 5 6

        // pop
        printf("pop操作\n");
        pop(header);
        forEach(header, printList);//h 7 1 2 3 5

        // shift
        printf("shift操作\n");
        shift(header);
        forEach(header, printList);//h 1 2 3 5

        // findIndex
        printf("第一个大于2的元素的索引为%d\n", findIndex(header, findIndexCB));

        // clearList
        clearList(header);
        printf("链表长度为%d\n", getLength(header));

        // destoryList
        destoryList(header);
    }

    /*** 算法2.11 unshift产生列表*/
    {
        LinkList header;
        creatList(&header, 5);
        forEach(header, printList);
    }

    /***** 算法2.12 */
    {
        
    }
}