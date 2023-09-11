/*
  RMIT University Vietnam
  Course: EEET2482/COSC2082
  Semester: 2023-2
  Lab Assessment: 2
  Author: Huynh Bao Cuong
  ID: 3978719
  Compiler used:  8.1.0
  Created  date:  (e.g. 09/09/2023)
  Acknowledgement: List the resources that you use to complete this assessment (write 'None' if you don't use any).
*/


#include <iostream>

class Place{
    private:
    std::string name;
    double distance;
    Place* nextPlace;

    public:
    Place(std::string nameInput = "", double DistanceInput = 0):
    name(nameInput), distance(DistanceInput){};
    
    // Place(std::string nameInput, double DistanceInput){
    //     this->name = nameInput;
    //     this->distance = DistanceInput;
    // }

    void setNext(Place *nNext){
        this->nextPlace = nNext;
    } 

    std::string getName(){
        return name;
    }

    double getDistance(){
        return distance;
    }

    Place* getPointer(){
        return nextPlace;
    }

};

void printLinkedList(Place *head){
    // temp will be the pointer use for printing
    Place *temp = head;

    // temp will stop when it meets n1 (which is end) --> edit: this doesnt work
    // solution: use count
    int count = 0;
    while (count < 5){
        std::cout << temp->getName() << " --> ";
        temp = temp->getPointer();
        std::cout << temp->getName() << ": " << temp->getDistance() << " km.\n";
        count ++;
    }
}

void totalDistance(Place *start){
    int count = 0;
    double total_distance = 0;

    Place* temp = start;
  
    while (count < 5){
        total_distance += temp->getDistance();
        temp = temp->getPointer();
        count ++;
    }

    std::cout << "Total distance in 1 round: " << total_distance << " km.\n";
}

void specificDestination(Place *start, Place *end){
    double calDistance = 0;
    while(start->getPointer() != end){
        calDistance += start->getDistance();
        start = start->getPointer();
    }
    std::cout << "Total distance: " << calDistance << " km.\n";
}

int main(int argc, char* argv[]){
    Place n1("Rmit", 1.2);
    Place n2("Lotte Mart", 3.0);
    Place n3("Go! Supermarket", 3.1);
    Place n4("Cresent Mall", 1.8);
    Place n5("Sc VivoCity", 2.5);

    Place *head = &n1;
    Place *end = &n2;

    n1.setNext(&n2);
    n2.setNext(&n3);
    n3.setNext(&n4);
    n4.setNext(&n5);
    n5.setNext(&n1);

    printLinkedList(head);
    totalDistance(head);
    specificDestination(&n5, &n1);

}