#ifndef SEQUENCELIST_C
#define SEQUENCELIST_C
#include "./sequenceList.h"

// 要对线性表进行操作 最好先进行排序

/*
* 算法2.1 union操作 合并两个列表到L1 只保留不同的
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
* 算法2.2 merge合并操作 两个非递减列表 合并为L3 L3也是非递减列表 不去重
*/
void mergeList(sqList *L1, sqList *L2, sqList *L3) {
    // 若使用遍历较长的列表 依次作比较与另外一个列表 如果比它大就插入到其后方 时间复杂度为O(L1.len * L2.len)
    // 实际上还是课本的最好
    int i = 0;
    int j = 0;
    while(i < L1->currentLength && j < L2->currentLength) {
       // 遍历两个列表 先处理等长部分
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
    
    // 下面的while只会进一个 长度比较长的那个
    // 如果进入了这里的while 说明上一个while最后一次循环的某一个数 比另外一个列表的任何一个数都大
    // 而两个列表都是非递减的 所以直接插入就行了
    while(i < L1->currentLength) {
        push(L3, L1->elem[i++]);
    }
    while(j < L2->currentLength) {
        push(L3, L2->elem[j++]);
    }
}
#endif