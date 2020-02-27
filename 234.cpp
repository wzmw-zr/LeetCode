/*************************************************************************
	> File Name: 234.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月27日 星期四 20时53分50秒
 ************************************************************************/

typedef struct ListNode ListNode;

 int get_length(ListNode *head) {
     int n = 0;
     while (head) n++, head = head->next;
     return n;
}

ListNode *reverse(ListNode *head, int n) {
    ListNode ret, *p = head, *q;
    while (n--) p = p->next;
    ret.next = NULL;
    while (p) {
        q = p->next;
        p->next = ret.next;
        ret.next = p;
        p = q;
    }
    return ret.next;
}

bool isPalindrome(struct ListNode* head){
    int len = get_length(head);
    ListNode *p = head, *q;
    q = reverse(head, (len + 1) >> 1);
    while (q) {
        if (p->val - q->val) return false;
        p = p->next;
        q = q->next;
    }
    return true;
}
