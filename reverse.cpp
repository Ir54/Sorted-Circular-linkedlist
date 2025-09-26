#include <iostream>
using namespace std;

template <class T>
class List {
private:
    class Node {
    public:
        T data;
        Node* next;
        Node(T d) : data(d), next(nullptr) {}
    };

    Node* head;

public:
    List() : head(nullptr) {
    }

    // Insert at head (for simplicity in this example)
    void insertFront(T d) {
        Node* newnode = new Node(d);
        newnode->next = head;
        head = newnode;
    }

    // ✅ Reverse the linked list in place
    Node* reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;

        while (curr != nullptr) {
            next = curr->next;   // save next node
            curr->next = prev;   // reverse the link
            prev = curr;         // move prev forward
            curr = next;         // move curr forward
        }

        head = prev; // new head
        return head;
    }

    // Print list
    void print() {
        Node* move = head;
        while (move != nullptr) {
            cout << move->data << " ";
            move = move->next;
        }
        cout << endl;
    }

    ~List() {
        Node* del;
        while (head != nullptr) {
            del = head;
            head = head->next;
            delete del;
        }
    }
};

int main() {
    List<int> L;

    // Insert numbers
    L.insertFront(10);
    L.insertFront(20);
    L.insertFront(30);
    L.insertFront(40);

    cout << "Original List: ";
    L.print();

    L.reverse();

    cout << "Reversed List: ";
    L.print();

    return 0;
}
