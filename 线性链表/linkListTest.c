#include "./linkList.c"

int main() {
    
    
    /**********��������***********/
    {
        // ��ʼ��
        LinkList L; // ���Lʵ���Ͼ���ͷָ��
        initLinkList(&L);

        // �Ƿ�Ϊ��
        !isEmpty(&L) ? printf("����Ϊ��\n") : printf("����ǿ�\n");


    }
    return 0;
}