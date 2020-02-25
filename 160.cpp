/*************************************************************************
	> File Name: 160.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月25日 星期二 21时43分47秒
 ************************************************************************/

#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b, b = __temp;\
}

typedef struct ListNode ListNode;

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int cntA = 0, cntB = 0;
    ListNode *p = headA, *q = headB;
    while (p) cntA++, p = p->next;
    while (q) cntB++, q = q->next;
    int m = cntA - cntB;
    p = headA, q = headB;
    if (m < 0) {
        swap(p, q);
        m = -m;
    }
    // 对齐操作
    while (m--) p = p->next;
    while (p != q) p = p->next, q = q->next;
    return p;
}
