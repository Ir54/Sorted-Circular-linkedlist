#include <iostream>
using namespace std;

class List {
private:
    class Node {
    public:
        int data;
        Node* next;
        Node(int d) : data(d), next(nullptr) {}
    };

    Node* head;

public:
    List() : head(nullptr) {}

    // Insert at end (for testing)
    void insert(int d) {
        Node* newnode = new Node(d);
        if (!head) {
            head = newnode;
            return;
        }
        Node* move = head;
        while (move->next) move = move->next;
        move->next = newnode;
    }

    // Find Nth node from the end
    int getNthFromEnd(int n) {
        Node* fast = head;
        Node* slow = head;

        // Move fast n steps ahead
        for (int i = 0; i < n; i++) {
            if (!fast) throw out_of_range("List has fewer nodes than n");
            fast = fast->next;
        }

        // Move both until fast reaches end
        while (fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow->data;
    }

    void print() {
        Node* move = head;
        while (move) {
            cout << move->data << " ";
            move = move->next;
        }
        cout << endl;
    }

    ~List() {
        while (head) {
            Node* del = head;
            head = head->next;
            delete del;
        }
    }
};

int main() {
    List L;

    L.insert(10);
    L.insert(20);
    L.insert(30);
    L.insert(40);
    L.insert(50);

    cout << "List: ";
    L.print();

    try {
        cout << "2nd node from the end: " << L.getNthFromEnd(2) << endl;
        cout << "5th node from the end: " << L.getNthFromEnd(5) << endl;
    } catch (out_of_range &e) {
        cout << e.what() << endl;
    }

    return 0;
}
