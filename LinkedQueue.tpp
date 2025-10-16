template <typename T>
LinkedQueue<T>::LinkedQueue() {
    this->length = 0;
    head = nullptr;
    last = nullptr;
}

template <typename T>
T LinkedQueue<T>::back() const {
    if (isEmpty()) {
        throw string("Queue is empty");
    }
    return last->value;
}

template <typename T>
void LinkedQueue<T>::clear() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    last = nullptr;
    this->length = 0;
}

template <typename T>
void LinkedQueue<T>::copy(const LinkedQueue<T>& copyObj) {
    head = nullptr;
    last = nullptr;
    this->length = 0;

    Node* curr = copyObj.head;
    while (curr != nullptr) {
        enqueue(curr->value);
        curr = curr->next;
    }
}

template <typename T>
void LinkedQueue<T>::dequeue() {
    if (isEmpty()) {
        throw string("Queue is empty");
    }

    Node* temp = head;
    head = head->next;
    delete temp;
    this->length--;

    if (this->length == 0) {
        last = nullptr;
    }
}

template <typename T>
void LinkedQueue<T>::enqueue(const T& elem) {
    Node* newNode = new Node(elem);

    if (isEmpty()) {
        head = last = newNode;
    } else {
        last->next = newNode;
        last = newNode;
    }

    this->length++;
}

template <typename T>
T LinkedQueue<T>::front() const {
    if (isEmpty()) {
        throw string("Queue is empty");
    }
    return head->value;
}
