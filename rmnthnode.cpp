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
        cout << "Constructor:\tWelcome to create the sorted order list\n";
    }

    // Insert in sorted order
    void insert(T d) {
        Node* newnode = new Node(d);

        if (head == nullptr || head->data >= d) {
            newnode->next = head;
            head = newnode;
            return;
        }

        Node* prev = head;
        Node* move = head->next;

        while (move != nullptr && move->data <= d) {
            prev = move;
            move = move->next;
        }

        prev->next = newnode;
        newnode->next = move;
    }

    // Remove Nth node from end 
    Node* removeNthFromEnd(int n) {
        Node* fast = head;
        Node* slow = head;

        // Move fast n steps ahead
        for (int i = 0; i < n; i++) {
            if (fast == nullptr) return head; // list shorter than n
            fast = fast->next;
        }

        // If fast reached null, remove head
        if (fast == nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        // Move both until fast->next is null
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Delete the node
        Node* temp = slow->next;
        slow->next = temp->next;
        delete temp;

        return head;
    }

    void print() {
        Node* move = head;
        while (move != nullptr) {
            cout << move->data << " ";
            move = move->next;
        }
        cout << endl;
    }

    ~List() {
        while (head != nullptr) {
            Node* del = head;
            head = head->next;
            delete del;
        }
    }
};

int main() {
    List<int> L;

    L.insert(1000);
    L.insert(50);
    L.insert(600);
    L.insert(600);
    L.insert(80);
    L.insert(90);
    L.insert(10);

    cout << "\nOriginal List: ";
    L.print();

    L.removeNthFromEnd(2); 
    cout << "After removing 2nd node from end: ";
    L.print();

    L.removeNthFromEnd(5);
    cout << "After removing 5th node from end: ";
    L.print();

    return 0;
}
