#include <iostream>
using namespace std;

template <typename E>
class Node {
public:
    E value;
    Node<E>* next;

    explicit Node(Node<E>* nextNode = NULL) {
        next = nextNode;
    }

    explicit Node(E nodeValue, Node<E>* nextNode = NULL) {
        value = nodeValue;
        next = nextNode;
    }
};

template <typename E>
class LinkedList {
public:
    LinkedList() {
        head = tail = cursor = new Node<E>;
        length = 0;
    }

    void insert(E value) {
        cursor->next = new Node<E>(value, cursor->next);

        if (cursor == tail) {
            tail = cursor->next;
        }

        length++;
    }

    E remove() {
        if (cursor->next == NULL) {
            cerr << "Error: there is no element to remove at the current cursor position!";
            exit(1);
        }

        Node<E>* tempNode = cursor->next;
        E tempValue = tempNode->value;

        if (cursor->next == tail) {
            tail = cursor;
        }

        cursor->next = cursor->next->next;

        length--;

        delete tempNode;

        return tempValue;
    }

    void clear() {
        Node<E>* tempNode;

        cursor = head->next;
        while (cursor != NULL) {
            tempNode = cursor;
            cursor = cursor->next;

            delete tempNode;
        }

        cursor = tail = head;

        head->next = NULL;

        length = 0;
    }

    void cursorToPos(int cursorPos) {
        if (cursorPos < 0 || cursorPos > length) {
            cerr << "Error: this cursor position is out of range!";
            exit(1);
        }

        cursor = head;
        for (int i = 0; i < cursorPos; ++i) {
            cursor = cursor->next;
        }
    }

    void cursorToStart() {
        cursor = head;
    }

    void cursorToEnd() {
        cursor = tail;
    }

    void cursorPrev() {
        if (cursor != head) {
            Node<E>* tempNode = head;
            while (tempNode->next != cursor) {
                tempNode = tempNode->next;
            }
            cursor = tempNode;
        }
    }

    void cursorNext() {
        if (cursor != tail) {
            cursor = cursor->next;
        }
    }

    E getValue() {
        if (cursor == tail) {
            cerr << "Error: there is no element at the current cursor position!";
            exit(1);
        }

        return cursor->next->value;
    }

    int getCursor() {
        Node<E>* tempNode = head;

        int i;
        for (i = 0; tempNode != cursor; ++i) {
            tempNode = tempNode->next;
        }
        return i;
    }

    int getLength() {
        return length;
    }

    Node<E>* getHead() {
        return head;
    }

private:
    Node<E>* head;
    Node<E>* tail;
    Node<E>* cursor;
    int length;
};

int main() {
    return 0;
}
