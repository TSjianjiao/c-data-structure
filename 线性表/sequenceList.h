#include <stdlib.h>

#ifndef SEQUENCE_LIST_H
#define SEQUENCE_LIST_H

// ����
#define LIST_INIT_SIZE 100
#define LISTINCRECEMENT 10

// ˳���б�ṹ��
typedef struct {
    int *firstNode; // ��һ���ڵ��ַ
    int currentLength; // ��ǰ����
    int currentSize; // ��ǰ�洢����
} sqList;

/*
* ��ʼ���б�
* @prama {sqList*} L һ��sqList���ͱ���
* @return {int} ״̬�� 0 �ɹ� 1 ʧ��
*/
int initList(sqList *L) {
    L -> firstNode = (int*)malloc(LIST_INIT_SIZE * sizeof(int));
    if(!L -> firstNode) return 1;
    L -> currentSize = LIST_INIT_SIZE;
    L -> currentLength = 0;
    return 0;
}

/*
* �Ƿ��ǿ��б�
* @return {int} ״̬�� 0 Ϊ�� 1 ��Ϊ��
*/
int isEmpty(sqList L) {
    return L.currentLength == 0 ? 0 : 1;
}

/*
* ����Ԫ��
* 
*/
int insertBefore(sqList *L, int position, int insertElement) {
    if(position < 1 || position > L -> currentLength + 1)
}




#endif