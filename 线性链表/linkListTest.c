#include "./linkList.c"

void printList(int item, int index) {
    printf("��%d����ֵΪ%d\n", index, item);
}

int findIndexCB(int item, int index) {
    // ���ص�һ������2��Ԫ�ص�����
    if(item > 2) {
        return 0;
    }else {
        return 1;
    }
}

int main() {
    
    /**********��������***********/
    {
        // ��ʼ��

        LinkList header; // ͷָ��
        initLinkList(&header);
        
        // ����
        
        insertItem(header, 0, 1);
        insertItem(header, 1, 2);
        insertItem(header, 2, 3);
        insertItem(header, 1, 4);
        insertItem(header, 4, 5);
        // h 1 4 2 3 5
        // �Ƿ�Ϊ��
        !isEmpty(header) ? printf("����Ϊ��\n") : printf("����ǿ�\n");
        
        // ��ȡĳ��λ�õ�Ԫ��
        printf("��ȡ����Ԫ����%d\n", getItem(header, 2).data);

        // ��ȡָ��λ�õ�ǰ��
        printf("ǰ���ڵ������Ϊ%d\n", getPrevNode(header, 2).data);

        // ��ȡָ��λ�ú���
        printf("�����ڵ������Ϊ%d\n", getNextNode(header, 2).data);

        // ����Ԫ��
        forEach(header, printList);

        // ������
        printf("������Ϊ%d\n", getLength(header));

        // ɾ��ָλ�õĽڵ�
        printf("��ɾ���Ľڵ���%d\n", deleteNode(header, 1));
        forEach(header, printList); // h 1 2 3 5

        // push
        printf("push����\n");
        push(header, 6);
        forEach(header, printList);//h 1 2 3 5 6

        // unshift
        printf("unshift����\n");
        unshift(header, 7);
        forEach(header, printList);//h 7 1 2 3 5 6

        // pop
        printf("pop����\n");
        pop(header);
        forEach(header, printList);//h 7 1 2 3 5

        // shift
        printf("shift����\n");
        shift(header);
        forEach(header, printList);//h 1 2 3 5

        // findIndex
        printf("��һ������2��Ԫ�ص�����Ϊ%d\n", findIndex(header, findIndexCB));

        // clearList
        clearList(header);
        printf("������Ϊ%d\n", getLength(header));

        // destoryList
        destoryList(header);
    }

    /*** �㷨2.11 unshift�����б�*/
    {
        LinkList header;
        creatList(&header, 5);
        forEach(header, printList);
    }

    /***** �㷨2.12 */
    {
        
    }
}