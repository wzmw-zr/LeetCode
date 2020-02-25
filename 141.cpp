/*************************************************************************
	> File Name: 141.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月25日 星期二 21时42分04秒
 ************************************************************************/

#includtruct ListNode ListNode;

bool HasCycle(struct ListNode *head) {
    if (!head) return false;
    ListNode *p = head, *q = head;
    do {
        p = p->next;
        q = q->next;
        if (!q || !q->next) return false;
        q = q->next;
    } while (p != q);
    return true;
}
