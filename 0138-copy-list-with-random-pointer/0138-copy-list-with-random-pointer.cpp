class Solution {
public:
    Node* copyRandomList(Node* head) {

        if (head == NULL) {
            return NULL;
        }

        unordered_map<Node*, Node*> m;

        // Create first node
        Node* newHead = new Node(head->val);

        Node* oldTemp = head->next;
        Node* newTemp = newHead;

        // Copy nodes and next pointers
        while (oldTemp != NULL) {

            Node* copyNode = new Node(oldTemp->val);

            m[oldTemp] = copyNode;

            newTemp->next = copyNode;

            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        // Add mapping for the first node
        m[head] = newHead;

        // Copy random pointers
        oldTemp = head;
        newTemp = newHead;

        while (oldTemp != NULL) {

            if (oldTemp->random != NULL) {
                newTemp->random = m[oldTemp->random];
            }

            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        return newHead;
    }
};