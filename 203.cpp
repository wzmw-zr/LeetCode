/*************************************************************************
	> File Name: 203.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月27日 星期四 20时50分11秒
 ************************************************************************/

typedef struct ListNode ListNode;
struct ListNode* removeElements(struct ListNode* head, int val){
    ListNode first, *p, *q;
    first.next = head;
    p = &first;
    while (p && p->next) {
        if (p->next->val == val) {
            q = p->next;
            p->next = q->next;
            free(q);
        } else {
            p = p->next;
        }
    }
    return first.next;
}
