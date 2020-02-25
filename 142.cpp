/*************************************************************************
	> File Name: 142.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月25日 星期二 21时43分19秒
 ************************************************************************/

typedef struct ListNode ListNode;

struct ListNode *detectCycle(struct ListNode *head) {
    if (!head) return NULL;
    // 指定快慢指针
    ListNode *p = head, *q = head;
    do {
        p = p->next;
        q = q->next;
        // 快指针由于一次会处理两个节点，所以需要判断当前节点和下一个结点是否为空，只要有一个为空就退出循环
        if (!q || !q->next) return NULL;
        q = q->next;
    } while (p != q);
    //判断有环之后计算环的长度
    int cnt = 0;
    do {
        cnt++;
        p = p->next;
    } while (p != q);
    // 寻找环的第一个节点
    p = head, q = head;
    while (cnt--) q = q->next;
    while (p != q) p = p->next, q = q->next;
    return p;
}
