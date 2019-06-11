#include "./linkList.c"

int main() {
    
    
    /**********基本操作***********/
    {
        // 初始化
        LinkList L; // 这个L实际上就是头指针
        initLinkList(&L);

        // 是否为空
        !isEmpty(&L) ? printf("链表为空\n") : printf("链表非空\n");


    }
    return 0;
}