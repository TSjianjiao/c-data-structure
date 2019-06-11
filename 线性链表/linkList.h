// �����˳�� ��ǰԪ�ر�������һ��Ԫ�صĵ�ַ  

#ifndef LINK_LIST_H
#define LINK_LIST_H

#include <stdlib.h> // malloc realloc
#include <stdio.h>

// �Ǹ��ṹ��ָ�����дstruct ������ֱ��LNode *next
typedef struct {
    int data;// ����
    struct LNode *next; // ָ����һ��Ԫ��
} LNode;

/*
    Ϊʲô����ʹ���˶���ָ�룿
    �������
*/
typedef LNode* LinkList; // LinkList��һ��ָ��ָ���ָ��


/*
*  ��ʼ���б�
*  ����Ĵ��벢������������ ��ᷢ���㴫���L��data��û�б��ı� 
*  ����c���Բ������� ���ǰ�ֵ���ݵ� ���������Lֻ�Ǻ�ʵ�εĵ�ֵַһ������  ʵ���ϻ������������ı���
*  Ȼ������malloc���·����˿ռ���β� ����͵����βεĵ�ַ��ʵ�εĵ�ַ��һ����  �����ں���ִ����Ϻ�ʵ��L��ֵ��û�б��ı�
*  �����Ϊʲô��Ҫ����ָ�� ���޸�ָ��ĵ�ַ
*  Ϊʲôǰ���˳���û���ö���ָ��  ʵ����˳���Ҳ������ͬ�ĵ��� ˳���ĵ�ַ�����˽ṹ������ �����൱���ýṹ��䵱������ �Ͷ���ָ��嵽����һ��
*  https://www.zhihu.com/question/41476387/answer/91566794
*  ��֮ ��Ҫ�ں��������޸�ָ��ĵ�ַ ����Ҫ����ָ��
*/
int initLinkListErrorCase(LNode *L) {
    // ��ʵ��������һ��ͷ���
    L = (LNode*)malloc(sizeof(LNode));
    if(!L) {
        printf("�ռ䲻��\n");
        return 1;
    }
    L->data = 10;
    L->next = NULL;
    return 0;
}
/*
*   ��ʼ���б�
*/
int initLinkList(LinkList *L) {
    //*L��ʾһ��LinkNode�ĵ�ַ Ҳ����ͷָ�� ��������� ��Ȼ���ȼ��Ͳ�����
    (*L) = (LNode*)malloc(sizeof(LNode));
    if(!(*L)) {
        printf("�ռ���չʧ��");
        return 1;
    }
    (*L)->next = NULL;
    return 0;
}

/*
*   �Ƿ�Ϊ��
*/
int isEmpty(LinkList *L) {
    if(!L || (*L)->next == NULL) {
        return 0;
    }else {
        return 1;
    }
}


#endif