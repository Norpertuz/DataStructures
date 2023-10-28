#include <iostream>
//this list is only one-way
class Element {

public:
    int data;
    Element* next;

    Element(int val) : data(val), next(nullptr) {}
};

class LinkedList{

    private:
        Element* head;
        int size;

    public:
         LinkedList() : head(nullptr), size(0) {}

    void append(int val){
        Element* newElement = new Element(val);
        if (!head) {
            head = newElement;
        } else {
            Element* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newElement;
        }
        size++;
    }

    void display() {
        Element* current = head;
        while (current) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    int getSize() {
        return size;
    }

    ~LinkedList() {
        while (head) {
            Element* temp = head;
            head = head->next;
            delete temp;
        }
    }

};

int main(){
    LinkedList list;

    list.append(1);
    list.append(44);
    list.append(155);

    std::cout << "Linked List: ";
    list.display();

    std::cout << "Size of the list: " << list.getSize() << std::endl;

    return 0;
}