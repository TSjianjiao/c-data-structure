#ifndef SEQUENCELIST_C
#define SEQUENCELIST_C
#include "./sequenceList.h"

// Ҫ�����Ա���в��� ����Ƚ�������

/*
* �㷨2.1 union���� �ϲ������б�L1 ֻ������ͬ��
*/
void Union(sqList *L1, sqList *L2) {
    int i = 0;
    int j = 0;
    for (i; i < L2->currentLength; i++)
    {
        int res = getItem(L1, L2->elem[i]);
        if (res < 0)
        {
            push(L1, L2->elem[i]);
        }
    }
}

/*
* �㷨2.2 merge�ϲ����� �����ǵݼ��б� �ϲ�ΪL3 L3Ҳ�Ƿǵݼ��б� ��ȥ��
*/
void mergeList(sqList *L1, sqList *L2, sqList *L3) {
    // ��ʹ�ñ����ϳ����б� �������Ƚ�������һ���б� ���������Ͳ��뵽��� ʱ�临�Ӷ�ΪO(L1.len * L2.len)
    // ʵ���ϻ��ǿα������
    int i = 0;
    int j = 0;
    while(i < L1->currentLength && j < L2->currentLength) {
       // ���������б� �ȴ���ȳ�����
       int L1Item = L1->elem[i];
       int L2Item = L2->elem[j];
       if(L1Item >= L2Item) {
            push(L3, L2Item);
            j++;
       }else {
            push(L3, L1Item);
            i++;
       }
    }
    
    // �����whileֻ���һ�� ���ȱȽϳ����Ǹ�
    // ��������������while ˵����һ��while���һ��ѭ����ĳһ���� ������һ���б���κ�һ��������
    // �������б��Ƿǵݼ��� ����ֱ�Ӳ��������
    while(i < L1->currentLength) {
        push(L3, L1->elem[i++]);
    }
    while(j < L2->currentLength) {
        push(L3, L2->elem[j++]);
    }
}
#endif