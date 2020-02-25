/*************************************************************************
	> File Name: 24.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月25日 星期二 21时41分17秒
 ************************************************************************/

typedef struct ListNode ListNode;
struct ListNode* swapPairs(struct ListNode* head){

	ListNode ret, *p, *q;
    ret.next = head;
    p = &ret;
    q = head;

    while (q && q->next) {
        p->next = q->next;
        q->next = p->next>next;
        p-next->next = q;
        p = q;
        q = q->next;
    }
    return ret.next;
}
