#include <stdio.h>
#include "./sequenceList.h"

/*
*  ��Ӧ��ֱ��ʹ��L.elem[i]ȥȡֵ
*  ֱ��ȡֵ�Ļ� ��װ�ĺ�����û�������� ���һ��ʹ�����׳���
*  ��װ�ĺ������� �ܶ඼û������ɾ��Ԫ�� ֻ�ǽ����ȼ���˶���
*/
void forEachCallBack(int item, int index) {
    printf("item: %d  ", item);
    printf("index: %d\n", index);
}

int main(){
    int deleteElement; // ��ɾ����Ԫ��
    int popElement; // ��pop��Ԫ��
    int shiftElement; // ��shift��Ԫ��
    int getItem;
    sqList L;

    // ��ʼ��
    initList(&L);
    // ����Ƿ�Ϊ��
    isEmpty(L) ? printf("���ǿյ�\n") : printf("�ǿյ�\n");
    // ����Ԫ��
    listInsert(&L, 0, 1);
    listInsert(&L, 1, 2);
    listInsert(&L, 0, 3);
    listInsert(&L, 3, 4);
    listInsert(&L, 1, 5);

    // push����
    push(&L, 6);
    // unshift����
    unshift(&L, 7);
    // 7351246

    // ɾ������
    deleteListElement(&L, 2, &deleteElement);
    printf("ɾ����Ԫ���ǣ�%d\n", deleteElement);
    // 731246

    // pop����
    pop(&L, &popElement);
    printf("��pop��Ԫ���ǣ�%d\n", popElement);
    // 73124
    
    // shift����
    shift(&L, &shiftElement);
    printf("��shift��Ԫ���ǣ�%d\n", shiftElement);
    // 3124

    // ���
    clearList(&L);
    push(&L, 6);
    // 6
    
    // destoryList(&L);
    
    // ��ȡĳ��ֵ
    getListItem(&L, 0, &getItem);
    printf("��ȡ����ֵ��%d\n", getItem);
    // forEach
    forEach(&L, forEachCallBack);
    


    return 0;
}