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

    // Helper to reverse a list from given node
    Node* reverseList(Node* node) {
        Node* prev = nullptr;
        Node* curr = node;
        Node* next = nullptr;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev; // new head of reversed part
    }

public:
    List() : head(nullptr) {
    }

    void insertFront(T d) {
        Node* newnode = new Node(d);
        newnode->next = head;
        head = newnode;
    }

    // ✅ Check if list is a palindrome
    bool isPalindrome() {
        if (head == nullptr || head->next == nullptr) return true;

        // 1. Find middle (slow will point to mid)
        Node* slow = head;
        Node* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. Reverse second half
        Node* secondHalf = reverseList(slow->next);

        // 3. Compare halves
        Node* firstHalf = head;
        Node* check = secondHalf;
        bool palindrome = true;
        while (check != nullptr) {
            if (firstHalf->data != check->data) {
                palindrome = false;
                break;
            }
            firstHalf = firstHalf->next;
            check = check->next;
        }

        // 4. Restore second half (optional)
        slow->next = reverseList(secondHalf);

        return palindrome;
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

    // Palindrome example: 1 -> 2 -> 3 -> 2 -> 1
    L.insertFront(1);
    L.insertFront(2);
    L.insertFront(3);
    L.insertFront(2);
    L.insertFront(5);

    cout << "List: ";
    L.print();

    if (L.isPalindrome())
        cout << "The list is a Palindrome\n";
    else
        cout << "The list is NOT a Palindrome\n";

    return 0;
}
