#include <iostream>

using namespace std;

template <typename E>
class Node {
public:
    E value;
    Node* next;

    explicit Node(Node* nextNode = NULL) {
        next = nextNode;
    }

    explicit Node(E nodeValue, Node* nextNode = NULL) {
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

        E value = (cursor->next)->value;

        if (cursor->next == tail) {
            tail = cursor;
        }

        cursor->next = (cursor->next)->next;

        numberElements--;

        if (cursor == tail) {
            cursorPrevious();
        }

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
    auto* pointerList = new LinkedList<int>;
    for (int i = 1; i > 0; --i) {
        pointerList->insert(i);
    }
    pointerList->print();
    cout << "--------" << endl;
    pointerList->remove();
    cout << "--------" << endl;
    pointerList->remove();
    cout << "[" << pointerList->getCursorPosition() << "] = " << pointerList->getValue() << endl;
    cout << "--------" << endl;


    delete pointerList;
    return 0;
}
