#include <iostream>

/*
TODO
- swap function
- order function bubble something 
*/

class Node{
    public:
    int value;
    Node *NextNode = nullptr;
    Node *lastNode = nullptr;

    // constructor
    Node(int value = 0) : value(value) {};

    // methods
    void assignLink(Node *next, Node *last){
        this->NextNode = next;
        this->lastNode = last;
    }

    // void assignLink(nullptr, Node &last){
    //     this->NextNode = &next;
    //     this->lastNode = &last;
    // }

    // friend function
    friend void insertNode(Node *&head, Node *&end, Node *priorNode, Node *newNode);
    friend void deleteNode(Node *&head, Node *&end, Node *delNode);
    friend void swapNode(Node *n1, Node *n2);
};

void printForward(Node *head){
        Node *temp = head;
        while(temp != nullptr){
        // access the value from pointer temp
        // then access linknode which contain next address, point temp to that address
        // as a result, advancing to the next node
        std::cout << temp->value << "-->";
        temp = temp -> NextNode;
        }
    }

void printBackward(Node *end){
        Node *temp2 = end;
        while (end != nullptr){
        std::cout << end->value << "-->";
        end = end->lastNode;
        }
    }

void insertNode(Node *&head, Node *&end, Node *priorNode, Node *newNode){
    if(priorNode == nullptr){
        // next node of newnode will be the head
        // it becomes the new 'head'
        // therefore last node is 
        newNode->lastNode = nullptr;
        newNode->NextNode = head;
        newNode->NextNode->lastNode = newNode;
        head = newNode;
    }
    else {
        //connect newnode to prior next node and vice versa
        newNode->NextNode = priorNode->NextNode;
        newNode->NextNode->lastNode = newNode;

        // connect prior node and new node
        newNode->lastNode = priorNode;
        priorNode->NextNode = newNode;
    }
}

void deleteNode(Node *&head, Node *&end, Node *delNode){
    // if delnode is end, delnote last next will be nullptr
    // delnote last will be end
    if(delNode->NextNode == nullptr){
        delNode->lastNode->NextNode = nullptr;
        end = delNode->lastNode;
    }
    else if(delNode->lastNode == nullptr){
        delNode->NextNode->lastNode = nullptr;
        head = delNode->NextNode;
    }
    else{
        delNode->lastNode->NextNode = delNode->NextNode;
        delNode->NextNode->lastNode = delNode->lastNode;
    }
}

void swapNode(Node *n1, Node *n2){
    Node temp1;
    Node temp2;
    // establish a clone node
    temp1.NextNode = n1->NextNode;
    temp1.lastNode = n1->lastNode;

    temp2.NextNode = n2->NextNode;
    temp2.lastNode = n2->lastNode;

    // copy clone node to n2
    n1->NextNode = temp2.NextNode;  

}

int main(int argc, char* argv[]){
    Node n1(8) , n2(5), n3(3), n4(6);

    // pointer head node points to address of n1
    // then access the linknode pointer object and change its address instead of nullptr

    Node *head = &n1; 
    Node *end = &n4;

    n1.assignLink(&n2, nullptr);
    n2.assignLink(&n3, &n1);
    n3.assignLink(&n4, &n2);
    n4.assignLink(nullptr, &n3);
  
    printForward(head);
    std::cout << "\n";
    printBackward(end);
    std::cout << "\n";

    Node n5(107);
    Node n6(200);
    insertNode(head, end, nullptr, &n6);
    insertNode(head, end, &n2, &n5);
    printForward(head);
    std::cout << "\n";
    deleteNode(head, end, &n4);
    printForward(head);
    std::cout << "\n";
    swapNode(&n1, &n6);
    printForward(head);
}