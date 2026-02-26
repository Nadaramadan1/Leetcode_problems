class Solution {
public:
    // تسريع الـ I/O
    struct FastIO {
        FastIO() {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
        }
    } fast_io;

    ListNode* sortList(ListNode* head) {
        // Base Case: لو القائمة فاضية أو فيها عنصر واحد
        if (!head || !head->next) return head;

        // 1. تقسيم القائمة لنصين (Split)
        ListNode* mid = getMid(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = nullptr; // قطع الصلة بين النصين

        // 2. ترتيب كل نص لوحده (Sort)
        left = sortList(left);
        right = sortList(right);

        // 3. دمج النصين المترتبين (Merge)
        return merge(left, right);
    }

private:
    // دالة لإيجاد منتصف القائمة (Slow and Fast Pointers)
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // دالة الدمج اللي اتعلمناها المسألة اللي فاتت
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};