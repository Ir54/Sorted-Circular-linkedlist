#include <iostream>
using namespace std;

template <class T>
class CircularList {
private:
    class Node {
    public:
        T data;
        Node* next;
        Node(T d) : data(d), next(nullptr) {}
    };

    Node* head;

public:
    CircularList() : head(nullptr) {
        cout << "Constructor:\tCreated a sorted circular linked list\n";
    }

    // Insert in sorted order
    void insert(T d) {
        Node* newnode = new Node(d);

        // Case 1: empty list
        if (head == nullptr) {
            head = newnode;
            head->next = head;
            return;
        }

        // Case 2: insert before head (new head)
        if (d <= head->data) {
            Node* temp = head;
            while (temp->next != head) temp = temp->next; // find last node
            temp->next = newnode;
            newnode->next = head;
            head = newnode; // update head
            return;
        }

        // Case 3: insert in between or at end
        Node* move = head;
        while (move->next != head && move->next->data < d) {
            move = move->next;
        }
        newnode->next = move->next;
        move->next = newnode;
    }

    // Delete a node
    void deletenode(T d) {
        if (head == nullptr) {
            cout << "\nList is empty";
            return;
        }

        Node* curr = head;
        Node* prev = nullptr;

        // Case 1: only one node
        if (head->data == d && head->next == head) {
            delete head;
            head = nullptr;
            return;
        }

        // Case 2: delete head node
        if (head->data == d) {
            Node* temp = head;
            while (temp->next != head) temp = temp->next; // last node
            temp->next = head->next;
            head = head->next;
            delete curr;
            return;
        }

        // Case 3: delete non-head node
        do {
            prev = curr;
            curr = curr->next;
            if (curr->data == d) {
                prev->next = curr->next;
                delete curr;
                return;
            }
        } while (curr != head);

        cout << "\nData not found";
    }

    // Print circular list
    void print() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        Node* move = head;
        do {
            cout << move->data << " ";
            move = move->next;
        } while (move != head);
        cout << endl;
    }

    ~CircularList() {
        cout << "Destructor:\tCleaning memory...\n";
        if (head == nullptr) return;

        Node* curr = head->next;
        Node* del;

        while (curr != head) {
            del = curr;
            curr = curr->next;
            delete del;
        }

        delete head;
        cout << "\tDone.\n";
    }
};

int main() {
    CircularList<int> CL;

    CL.insert(30);
    CL.insert(5);
    CL.insert(70);
    CL.insert(25);
    CL.insert(10);
    CL.insert(90);
    CL.insert(15);

    cout << "\nYou have inserted the following data (sorted):\n";
    CL.print();

    CL.deletenode(90);
    CL.deletenode(5);
    CL.deletenode(75);

    cout << "\nAfter deleting some data:\n";
    CL.print();

    return 0;
}
