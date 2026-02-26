class Solution {
public:
    // التريكاية رقم 1: تسريع القراءة والكتابة
    struct FastIO {
        FastIO() {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
        }
    } fast_io;

    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // التريكاية رقم 2: التعامل مع الحالات الفارغة فوراً
        if (lists.empty()) return nullptr;
        if (lists.size() == 1) return lists[0];

        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        for (auto l : lists) {
            if (l) pq.push(l);
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();

            tail->next = node;
            tail = tail->next;

            if (node->next) {
                pq.push(node->next);
            }
        }

        return dummy.next;
    }
};