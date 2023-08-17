#include <iostream>

class matrix{
    public:
        int toprow[3], middlerow[3], bottomrow[3];

        matrix(){
           for(int i = 0; i < 3; i++){
                toprow[i] = 0;
                middlerow[i] = 0;
                bottomrow[i] = 0;
           }
        }

        void settop(int first, int second, int third){
            this->toprow[0] = first;
            this->toprow[1] = second;
            this->toprow[2] = third;
        }

        void setmiddle(int first, int second, int third){
            this->middlerow[0] = first;
            this->middlerow[1] = second;
            this->middlerow[2] = third;
        }

        void setbottom(int first, int second, int third){
            this->bottomrow[0] = first;
            this->bottomrow[1] = second;
            this->bottomrow[2] = third;
        }
        void print(){
            for(int i = 0; i < 3; i++){
                std::cout << toprow[i] << " ";
            }
            std::cout << "\n";
            for(int i = 0; i < 3; i++){
                std::cout << middlerow[i] << " ";
            }
            std::cout << "\n";
            for(int i = 0; i < 3; i++){
                std::cout << bottomrow[i] << " ";
            }
            
        }

        //OPERATOR
        int& operator()(int col, int position){
            if(col == 0){
                return toprow[position];
            }
            else if(col == 1){
                return middlerow[position];
            }
            else if(col == 2){
                return bottomrow[position];
            }
        }
        friend matrix operator+(matrix obj1, matrix obj2);
        friend std::istream& operator >>(std::istream& input, matrix obj);
};

std::istream& operator >>(std::istream& input, matrix& obj){
    
}

matrix operator+(matrix obj1, matrix obj2){
    matrix result;
    for(int i = 0; i < 3; i++){
        result.toprow[i] = obj1.toprow[i] + obj1.toprow[i];
    }
    for(int i = 0; i < 3; i++){
        result.middlerow[i] = obj1.middlerow[i] + obj1.middlerow[i];
    }
    for(int i = 0; i < 3; i++){
        result.bottomrow[i] = obj1.bottomrow[i] + obj1.bottomrow[i];
    }
    return result;
}

int main(int argc, char* agrv[]){
    matrix pog;
    pog(2,1) = 9;
    pog.print();
    matrix test1, test2, test3;
    

}