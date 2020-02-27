/*************************************************************************
	> File Name: 206.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月27日 星期四 20时50分48秒
 ************************************************************************/

typedef struct ListNode ListNode;
struct ListNode* reverseList(struct ListNode* head){
    ListNode ret, *p, *q;
    ret.next = NULL;
    p = head;
    while (p) {
        q = p->next;
        p->next = ret.next;
        ret.next = p;
        p = q;
    }
    return ret.next;
}
