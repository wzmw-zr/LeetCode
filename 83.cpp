/*************************************************************************
	> File Name: 83.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月25日 星期二 21时41分27秒
 ************************************************************************/

struct ListNode* deleteDuplicates(struct ListNode* head){
    if (!head) return head;
    struct ListNode *first = head, *second;

    while (first && first->next) {
        if (first->val - first->next->val) first = first->next;
        else {
            second = first->next;
            first->next = second->next;
            free(second);
        }
    }
    return head;
}
