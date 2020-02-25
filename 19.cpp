/*************************************************************************
	> File Name: 19.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月25日 星期二 21时40分06秒
 ************************************************************************/
typedef struct ListNode ListNode;

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){

    ListNode ret, *p, *q;
    ret.next = head;
    p = q = &ret; 
    while (n--) p = p->next;
    while (p->next) p = p->next, q = q->next;
    p = q->next;
    q->next = p->next;
    free(p);
    return ret.next;
}
