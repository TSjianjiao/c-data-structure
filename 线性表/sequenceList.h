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
int initList(sqList *L) {
    L -> elem = (int*)malloc(LIST_INIT_SIZE * sizeof(int));
    if(!L -> elem) return 1;
    L -> currentSize = LIST_INIT_SIZE;
    L -> currentLength = 0;
    return 0;
}

/*
* �Ƿ��ǿ��б�
* @return {int} ״̬�� 0 Ϊ�� 1 ��Ϊ��
*/
int isEmpty(sqList *L) {
    return L->currentLength == 0 ? 0 : 1;
}

/*
* ��ȡ����
* @return {int} �б���
*/
int listLength(sqList L) {
    return L.currentLength;
}

/*
* ����Ԫ�� �滻Ŀ��λ�õ�Ԫ�� �����Ԫ�������
* �㷨2.4
*/
int listInsert(sqList *L, int position, int insertElement) {
    //  1 2 3
    int *newElem;
    int *p, *dest;
    int len = L->currentLength;
    // Ԥ��λ�ó����߽�
    if(position < 0 || position > len + 1) {
        printf("�����߽�");
        return 1;
    }

    // �ڴ�ռ䲻�� ����ռ�
    if(L->currentSize <= L->currentLength) {
        newElem = (int*)realloc(L->elem, sizeof(int) * (L->currentSize + LISTINCRECEMENT));
        if(! newElem) {
            printf("����ռ�ʧ��");
            return 1;
        }
        // �µ��׵�ַ
        L->elem = newElem;
        L->currentSize += LISTINCRECEMENT;
    }

    // Ŀ���ַ ָ����������൱�ں���
    dest = &L->elem[position];

    // ָ��p��ʼλ��Ϊ �б�����
    // �����currentLength��û������ ��û���޸� ����firstNode[L->currentLength]λ����һ���յĵ�ַ
    for(p = &L->elem[L->currentLength]; p > dest; p--) {
        *p = *(p-1); // ����ֵ
    }
    
    // ����
    *dest = insertElement;
    // �޸ĳ���
    L->currentLength++;
    return 0;
}

/*
* push
*/
int push(sqList *L, int pushElement) {
    // �б�ĩβ����
    // 0 1 2 _
    int state = listInsert(L, L->currentLength, pushElement);
    return state;
}

/*
* unshift
*/
int unshift(sqList *L, int unshiftElement) {
    // �б�ͷ������
    int state = listInsert(L, 0, unshiftElement);
    return state;
}

/*
*  ɾ��ĳ��λ�õ�Ԫ�� ���ñ�������
*  �㷨2.5
*/
int deleteListElement(sqList *L, int position, int *feedBack) {
    int *dest; // Ŀ��ָ��
    int *last; // �б�ĩβָ��
    int *i; // ����ָ��
    if(position < 0 || position > L->currentLength - 1) {
        printf("ɾ�����������߽�\n");
        return 1;
    }
    dest = &L->elem[position];
    last = &L->elem[L->currentLength - 1];
    // ����ֵ
    *feedBack = L->elem[position];

    // ����Ԫ��
    for(i = dest + 1; i <= last; i++) {
        *(i-1) = *i;
    }
    
    L->currentLength--;
    return 0;
}

/*
*   pop
*/
int pop(sqList *L, int *feedBack) {
    if( L->currentLength == 0) {
        printf("�б�Ϊ��");
        return 1;
    }
    deleteListElement(L, L->currentLength - 1, feedBack);
    return 0;
}

/*
* shift
*/
int shift(sqList *L, int *feedBack) {
    if( L->currentLength == 0) {
        printf("�б�Ϊ��");
        return 1;
    }
    deleteListElement(L, 0, feedBack);
    return 0;
}

/*
* forEach �����б�
* @prmas {*function} void(*callBack)(int, int)
*/
int forEach(sqList *L, void(*callBack)(int, int)) {
    int index;
    if( L->currentLength == 0) {
        printf("�����б�Ϊ��");
        return 1;
    }
    for(index = 0; index < L->currentLength; index++) {
        int item = L->elem[index];
        callBack(item, index);
    }
    return 0;
}

/*
*  ���б���� ��������
*
*/
void clearList(sqList *L) {
    L->currentLength = 0;
}

/*
*  �����б�
*
*/
void destoryList(sqList *L) {
    // ����Ҫ���ǻ��շ�����ڴ�ռ�
    // �ṹ��L�ĵ�ַ �� Ԫ��L.elem�ĵ�ַ����ͬһ��
    free(L->elem);

    L->elem = NULL;
    L->currentSize = 0;
    L->currentLength = 0;

    // free(L);
}

/*
* ��ȡĳ��λ�õ�Ԫ��
*/
int getListItem(sqList *L, int position, int *feedBack) {
    if(position < 0 || position > L->currentLength - 1) {
        printf("��ȡԪ�أ������߽�");
        return 1;
    }
    *feedBack = L->elem[position];
    return 0;
}

/*
* findIndex 
* @returns ʧ�ܷ���-1 �ɹ����ص�һ��ƥ�������
* c99֮ǰû�� ����ֵ ������0,1����
* �㷨2.6
*/
int findIndex(sqList *L, int(*callBack)(int, int)) {
    int index;
    if(L->currentLength <= 0) {
        printf("findIndex����Ϊ��\n");
        return 1;
    }
    for(index = 0; index < L->currentLength; index++) {
        int res = callBack(L->elem[index], index);
        if(res) {
            return index;
        }
    }
    return -1;
}

/*
* ��ȡĳ��ֵ��λ��
* @returns ʧ�ܷ���-1 �ɹ����ص�һ��ƥ�������
*/
int getItem(sqList *L, int value) {
    int index;
    if(L->currentLength <= 0) {
        printf("findIndex����Ϊ��\n");
        return 1;
    }
    for(index = 0; index < L->currentLength; index++) {
        int res = value == L->elem[index] ? 1 : 0;
        if(res) {
            return index;
        }
    }
    return -1;
}



/*
* ����ĳ��Ԫ�ص�ǰ���ڵ�
* ���ڵڶ������� �ο���ֱ�Ӵ���ֵ ��������������������ظ�ֵ
*/
int priorElem(sqList *L, int current, int *prev) {
    int index = 0;
    if(!isEmpty(L)){
        printf("����ǰ��,����Ϊ��\n");
        return 1;
    }
     // ��һ���ڵ� û��ǰ��
    if(current == L->elem[0]) {
        printf("��һ���ڵ�û��ǰ��\n");
        return 1;
    }
    
    for(index; index < L->currentLength; index++) {
        if(L->elem[index+1] == current) {
            *prev = L->elem[index];
            break;
        }
    }

    return 0;
}

/*
* ��ȡ����
*/
int nextElem(sqList *L, int current, int *next) {
    int index = 1;
    if(!isEmpty(L)){
        printf("����ǰ��,����Ϊ��\n");
        return 1;
    }
     // ���һ���ڵ� û�к���
    if(current == L->elem[L->currentLength - 1]) {
        printf("���һ���ڵ�û�к���\n");
        return 1;
    }

    for(index; index < L->currentLength; index++) {
        if(L->elem[index-1] == current) {
            *next = L->elem[index];
            break;
        }
    }

    return 0;
}
#endif