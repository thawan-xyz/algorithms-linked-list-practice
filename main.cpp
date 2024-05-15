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
        numberElements = 0;
    }

    void print() {
        Node<E>* temp = head->next;
        for (int i = 0; temp != NULL; ++i) {
            cout << "[" << i << "] = " << temp->value << endl;
            temp = temp->next;
        }
    }

    E getValue() {
        if (cursor == tail) {
            cerr << "Error: there is no element at the current cursor";
            exit(1);
        }
        return (cursor->next)->value;
    }

    void insert(E value) {
        cursor->next = new Node<E>(value, cursor->next);

        if (cursor == tail) {
            tail = cursor->next;
        }

        numberElements++;
    }

    E remove() {
        if (cursor == tail) {
            cerr << "Error: the list is already empty!";
            exit(1);
        }

        Node<E>* temp = cursor->next;
        E value = (cursor->next)->value;

        cursor->next = (cursor->next)->next;

        if (temp == tail) {
            tail = cursor;
            cursorPrevious();
        }

        numberElements--;

        delete temp;

        return value;
    }

    int getCursorPosition() {
        Node<E>* temp = head;

        int i = 0;
        while (cursor != temp) {
            temp = temp->next;
            ++i;
        }
        return i;
    }

    void cursorToPosition (int position) {
        if (position < 0 || position > numberElements - 1) {
            cerr << "Error: position is out of range!";
            exit(1);
        }

        cursor = head;
        for (int i = 0; i < position; ++i) {
            cursor = cursor->next;
        }
    }

    void cursorToStart() {
        cursor = head;
    }

    void cursorToEnd() {
        while (cursor->next != tail) {
            cursor = cursor->next;
        }
    }

    void cursorPrevious() {
        if (cursor != head) {
            Node<E>* temp = head;
            while (cursor != temp->next) {
                temp = temp->next;
            }
            cursor = temp;
        }
    }

    void cursorNext() {
        if (cursor->next != tail) {
            cursor = cursor->next;
        }
    }

    int getNumberElements() {
        return numberElements;
    }

private:
    Node<E>* head;
    Node<E>* tail;
    Node<E>* cursor;
    int numberElements;
};

int main() {
    return 0;
}
