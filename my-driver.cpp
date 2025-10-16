#include "LinkedQueue.hpp"
#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "=== TEST 1: Integer Queue ===" << endl;
    LinkedQueue<int> q1;

    // Test empty queue exceptions
    try {
        q1.front();
    } catch (string& e) {
        cout << e << endl;
    }

    try {
        q1.back();
    } catch (string& e) {
        cout << e << endl;
    }

    // Enqueue elements
    for (int i = 1; i <= 5; i++) {
        q1.enqueue(i * 10);
    }

    cout << "Front: " << q1.front() << ", Back: " << q1.back() << endl;
    cout << "Length: " << q1.getLength() << endl;

    // Dequeue two elements
    q1.dequeue();
    q1.dequeue();
    cout << "After two dequeues, Front: " << q1.front()
         << ", Length: " << q1.getLength() << endl;

    // Copy constructor test
    LinkedQueue<int> q2 = q1;
    cout << "Copied queue (q2) - Front: " << q2.front()
         << ", Back: " << q2.back()
         << ", Length: " << q2.getLength() << endl;

    // Clear original and confirm q2 unaffected
    q1.clear();
    cout << "After clearing q1, q1 empty? " << (q1.isEmpty() ? "yes" : "no") << endl;
    cout << "q2 still has " << q2.getLength() << " items, Front: " << q2.front() << endl;

    cout << "\n=== TEST 2: String Queue ===" << endl;
    LinkedQueue<string> q3;
    q3.enqueue("apple");
    q3.enqueue("banana");
    q3.enqueue("cherry");

    cout << "Front: " << q3.front() << ", Back: " << q3.back()
         << ", Length: " << q3.getLength() << endl;

    // Dequeue one and show new front
    q3.dequeue();
    cout << "After dequeue, Front: " << q3.front()
         << ", Length: " << q3.getLength() << endl;

    // Assignment operator test
    LinkedQueue<string> q4;
    q4 = q3;
    cout << "Copied via operator= (q4) - Front: " << q4.front()
         << ", Back: " << q4.back()
         << ", Length: " << q4.getLength() << endl;

    // Clear q3
    q3.clear();
    cout << "After clearing q3, empty? " << (q3.isEmpty() ? "yes" : "no") << endl;
    cout << "q4 still has " << q4.getLength() << " items, Front: " << q4.front() << endl;

    cout << "\n=== TEST 3: Double Queue ===" << endl;
    LinkedQueue<double> q5;
    q5.enqueue(3.14);
    q5.enqueue(2.718);
    q5.enqueue(1.618);
    cout << "Front: " << q5.front() << ", Back: " << q5.back()
         << ", Length: " << q5.getLength() << endl;

    q5.dequeue();
    cout << "After dequeue, Front: " << q5.front()
         << ", Length: " << q5.getLength() << endl;

    cout << "Clearing all..." << endl;
    q5.clear();
    cout << "Now empty? " << (q5.isEmpty() ? "yes" : "no") << endl;

    return 0;
}
