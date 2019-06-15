#include <stdlib.h> // malloc realloc

#ifndef SEQUENCE_LIST_H
#define SEQUENCE_LIST_H

// ����
#define LIST_INIT_SIZE 100
#define LISTINCRECEMENT 10

// ˳���б�ṹ��
typedef struct {
    int *elem; // �ڵ��ַ ��ʼ�ǵ�һ���ڵ�ĵ�ַ
    int currentLength; // ��ǰ�б���
    int currentSize; // ��ǰ�洢���� ���ÿռ�
} sqList;

/*
*   �ؼ������� ��ʼ��initList �� ����Ԫ��listInsert
*/

/*
* ��ʼ���б�
* @prama {sqList*} L һ��sqList���ͱ���
* @return {int} ״̬�� 0 �ɹ� 1 ʧ��
* �㷨2.3
*/
int initList(sqList *L);

/*
* �Ƿ��ǿ��б�
* @return {int} ״̬�� 0 Ϊ�� 1 ��Ϊ��
*/
int isEmpty(sqList *L);

/*
* ��ȡ����
* @return {int} �б���
*/
int listLength(sqList L);
/*
* ����Ԫ�� �滻Ŀ��λ�õ�Ԫ�� �����Ԫ�������
* �㷨2.4
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
*  ɾ��ĳ��λ�õ�Ԫ�� ���ñ�������
*  �㷨2.5
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
* forEach �����б�
* @prmas {*function} void(*callBack)(int, int)
*/
int forEach(sqList *L, void(*callBack)(int, int));

/*
*  ���б���� ��������
*
*/
void clearList(sqList *L);

/*
*  �����б�
*
*/
void destoryList(sqList *L);

/*
* ��ȡĳ��λ�õ�Ԫ��
*/
int getListItem(sqList *L, int position, int *feedBack);

/*
* findIndex 
* @returns ʧ�ܷ���-1 �ɹ����ص�һ��ƥ�������
* c99֮ǰû�� ����ֵ ������0,1����
* �㷨2.6
*/
int findIndex(sqList *L, int(*callBack)(int, int));



/*
* ����ĳ��Ԫ�ص�ǰ���ڵ�
* ���ڵڶ������� �ο���ֱ�Ӵ���ֵ ��������������������ظ�ֵ
*/
int priorElem(sqList *L, int current, int *prev);

/*
* ��ȡ����
*/
int nextElem(sqList *L, int current, int *next);
#endif