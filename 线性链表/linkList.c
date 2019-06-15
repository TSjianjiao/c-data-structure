#ifndef LINK_LIST_C
#define LINK_LIST_C
#include <stdlib.h> // malloc realloc
#include <stdio.h>
#include "linkList.h"
/****��������****/
/*
*   ��ʼ���б�
*   Ϊʲô����ʹ���˶���ָ�룿
*/
int initLinkList(LinkList *L) {
    //*L LNode*��ָ�� Ҳ���Ƕ���ָ��
    // ֱ��ʹ��L �������濪�ٿռ�ʱ�����βκ�ʵ��ָ��ͬ�ĵ�ַ
    // �޸ľͻ���Ч
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
int isEmpty(LinkList header) {
    if(header->next == NULL) {
        return 0;
    }else {
        return 1;
    }
}

/*
* �㷨2.9
* ����Ԫ��
*/
int insertItem(LinkList header, int position, int item) {
    LinkList current = header;
    // һ��Ҫ��ָ�� ��Ȼ����һ���ֲ����� ����ִ�����û����
    // ָ��ǵó�ʼ��
    LNode *newNode = (LNode*)malloc(sizeof(LNode)); 
    int index = 0;
    // 0 1 2 3 // ע�ⷶΧ ��0��ʼ
    // ����Ҫ����λ����1 ��������λ����2 ��Ҫ֪��λ��2ǰһ���ڵ����ϢҲ�����������1
    // ��index=0ʱcurrentָ������λ��1�ĵ�ַ
    // ����current���Ǳ�ʾĿ��λ��ǰһ���ڵ�
    while(index < position){
        if(!current->next){break;}
        current = current->next; // С�Ĳ�����current=NULL
        index++;
    }
    newNode->data = item;
    newNode->next = current->next;
    current->next = newNode;
    return 0;
}

/*
*   �㷨2.8
*   ��ȡĳ��λ�õ�Ԫ��
*   û�ҵ��᷵�����һ��ֵ
*/
LNode getItem(LinkList header, int position) {
    LinkList current = header;
    int index = 0;
    // h 1 2 3
    while(index <= position) {
        current = current->next;
        index++;
    }
    return (*current);
}

/*
*   �����ڵ�
*   @prams {LinkList} header ͷ���
*   @prams {function} callBack �ص����� ��һ�������ǽڵ�ֵ���ڶ���������ʾ����
*/
void forEach(LinkList header, void(*callBack)(int, int)) {
    LinkList prev = header;
    int index = 0;
    if(!isEmpty(header)) {
        printf("����Ϊ��\n");
        return;
    }
    while(1) {
        prev = prev->next;
        // printf("ָ���ַ%p", (*prev).next);
        callBack(prev->data, index);
        if(!prev->next)break;
        index++;
    }
}

/*
*   ��ȡ������
*/
int getLength(LinkList header) {
    LinkList prev = header;
    int count = 0;
    if(!isEmpty(header)) {
        printf("����Ϊ��\n");
        return 0;
    }
    while(prev->next) {
        prev = prev->next;
        count++;
    }
    return count;
}

/**
 * ��ȡĿ��λ�õ�ǰ��
 */
LNode getPrevNode(LinkList header, int position) {
    LinkList current = header;
    int index = 0;
    if(!isEmpty(header)) {
        printf("����Ϊ��\n");
    }
    while(index < position && current->next) {
        current = current->next;
        index++;
    }
    if(index < position) {
        printf("�Ƿ�λ��\n");
        current = header->next;
    }
    if(current == header) {
        printf("�׽ڵ�û��ǰ��\n");
        current = header->next;
    }
    return (*current);
}

/**
 * ��ȡĿ��λ�ú���
 * û���ҵ������׽ڵ�
 */
LNode getNextNode(LinkList header, int position) {
    LinkList current = header;
    int index = 0;
    if(!isEmpty(header)) {
        printf("����Ϊ��\n");
    }
    while(index <= position + 1) {
        current = current->next;
        index++;
    }
    if(!current) {
        printf("β�ڵ�û�к���\n");
        current = header->next;
    }
    return (*current);
}

/*
*   �㷨2.10
*   ɾ��ĳ��λ�õĽڵ�
*/

int deleteNode(LinkList header, int position) {
    LinkList current = header;
    LNode *prevNode;
    int res;
    int index = 0;
    if(!isEmpty(header)) {
        printf("����Ϊ��\n");
    }

    // ��ǰ��
    while(index <= position && current->next) {
        prevNode = current;
        current = current->next;
        index++;
    }
    prevNode->next = current->next;
    res = current->data;
    // �ͷű�ɾ���Ľڵ�
    free(current);
    return res;
}

/**
 * ĩβ����push
 */
int push(LinkList header, int item) {
    LinkList current = header;
    LNode *newNode = (LNode*)malloc(sizeof(LNode));
    while(current->next) {
        current = current->next;
    }
    newNode->data = item;
    newNode->next = NULL;
    current->next = newNode;
    return 0;
}

/**
 * unshift
 */
int unshift(LinkList header, int item) {
    LinkList current = header;
    LinkList newNode = (LinkList)malloc(sizeof(LNode));
    newNode->data = item;
    newNode->next = current->next;
    current->next = newNode;
    return 0;
}

/**
 * pop
 * ���س�ջ��data ��������-1
 */
int pop(LinkList header) {
    LinkList current = header;
    LinkList prevNode;
    int res = -1;
    if(!isEmpty(header)) {
        printf("����Ϊ��\n");
        return res;
    }
    while(current->next) {
        prevNode = current;
        current = current->next;
    }
    prevNode->next = NULL;
    res = current->data;
    free(current);
    return res;
}

/**
 * shift
 */
int shift(LinkList header) {
    LinkList firstNode;
    int res = -1;
    if(!isEmpty(header)) {
        printf("����Ϊ��\n");
        return res;
    }
    firstNode = header->next;
    header->next = firstNode->next;
    res = firstNode->data;
    free(firstNode);
    return res;
}

/**
 * ���������Ԫ�� ��������
 */
int findIndex(LinkList header, int (*callBack)(int, int)) {
    LinkList current = header;
    int index = 0;
    if(!isEmpty(header)) {
        printf("����Ϊ��\n");
        return -1;
    }
    while(current->next) {
        current = current->next;
        if(!callBack(current->data, index)){
            return index;
        }
        index++;
    }
    return -1;

}
/**
 * ����б� ����ͷ���
 */
int clearList(LinkList header) {
    LinkList current = header;
    LinkList prevNode;
    int index = 0;
    while(current->next) {
        if(index > 1) {
            free(prevNode);
        }
        prevNode = current;
        current = current->next;
        index++;
    }
    header->next=NULL;
    return 0;
}

/**
 * �ݻ��б�
 */
int destoryList(LinkList header) {
    clearList(header);
    free(header);
    return 0;
}
/**********��������***********/

/** Ӧ�� */
/**
 * �㷨2.11
 * �����������
 */
void creatList(LinkList *header, int count) {
    int input;
    LNode *newNode;
    (*header) = (LNode*)malloc(sizeof(LNode));
    (*header)->next = NULL;
    while(count > 0) {
        scanf("%d", &input);
        // ע��newNodeÿ�ζ�Ҫ���·����¿ռ� �൱�ڴ���һ���±���
        newNode = (LNode*)malloc(sizeof(LNode));
        newNode->data = input;
        newNode->next = (*header)->next;
        (*header)->next = newNode;
        count--;
    }
}

/**
 * �㷨2.12
 * ���б�ת
 * https://www.cnblogs.com/huangxincheng/p/4051854.html
 */
LinkList reverse(LinkList header) {
    LinkList current = header;
    LinkList prevNode;
    if(!current->next) return current;
    prevNode = reverse(current->next);
    

}   

#endif