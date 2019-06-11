#include <stdio.h>
#include "./sequenceList.c"
// �㷨����

/*
*  ��Ӧ��ֱ��ʹ��L.elem[i]ȥȡֵ
*  ֱ��ȡֵ�Ļ� ��װ�ĺ�����û�������� ���һ��ʹ�����׳���
*  ��װ�ĺ������� �ܶ඼û������ɾ��Ԫ�� ֻ�ǽ����ȼ���˶���
*/
void forEachCallBack(int item, int index) {
    printf("item: %d  ", item);
    printf("index: %d\n", index);
}

int getItemIndex(int item, int index) {
    if(item >= 2) {
        return 1;
    }else {
        return 0;
    }
}

int main(){
    /****** �������� *****/
    {
        int deleteElement; // ��ɾ����Ԫ��
        int popElement; // ��pop��Ԫ��
        int shiftElement; // ��shift��Ԫ��
        int getItem; // ��ȡĳ��λ�õ�ֵ
        int itemIndex; // ĳ��Ԫ�ص�����
        int prevNode; // ǰ���ڵ�
        int nextNode; // �����ڵ�

        sqList L;

        // ��ʼ��
        initList(&L);
        // ����Ƿ�Ϊ��
        isEmpty(&L) ? printf("���ǿյ�\n") : printf("�ǿյ�\n");
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
        push(&L, 1);
        push(&L, 2);
        push(&L, 3);
        push(&L, 4);
        // 1234
    
        //destoryList(&L);

        // ��ȡĳ��ֵ
        getListItem(&L, 2, &getItem);
        printf("��ȡ����ֵ��%d\n", getItem);

        // ��ȡĳ��ֵ��λ��
        itemIndex = findIndex(&L, getItemIndex);
        printf("��ȡ����������%d\n", itemIndex);

        // ��ȡǰ��
        priorElem(&L, 4, &prevNode);
        printf("��ȡ����ǰ���ڵ�ֵ��%d\n", prevNode);

        // ��ȡ����
        nextElem(&L, 3, &nextNode);
        printf("��ȡ���ĺ����ڵ�ֵ��%d\n", nextNode);

        // forEach
        forEach(&L, forEachCallBack);
    }
    
    
    /****** �㷨2.1 union����  *****/

    {
        // �ϲ������б�L1 ֻ������ͬ��
        sqList L1;
        sqList L2;
        initList(&L1);
        initList(&L2);
        // L1
        push(&L1, 1);
        push(&L1, 2);
        push(&L1, 3);
        push(&L1, 4);
        // L2
        push(&L2, 4);
        push(&L2, 3);
        push(&L2, 6);
        push(&L2, 1);
        push(&L2, 10);
        Union(&L1, &L2);
        printf("***********union����************\n");
        forEach(&L1, forEachCallBack);
    }

    /****** �㷨2.2 merge�ϲ�����  *****/
    {
        sqList L1;
        sqList L2;
        sqList L3;
        initList(&L1);
        initList(&L2);
        initList(&L3);
        // L1
        push(&L1, 1);
        push(&L1, 2);
        push(&L1, 3);
        push(&L1, 4);
        // L2
        push(&L2, 2);
        push(&L2, 4);
        push(&L2, 5);
        push(&L2, 8); 
        push(&L2, 9);
        // 1 2 2 3 4 4 5 8 9
        mergeList(&L1, &L2, &L3);
        printf("***********merge����************\n");
        forEach(&L3, forEachCallBack);
    }

    return 0;
}