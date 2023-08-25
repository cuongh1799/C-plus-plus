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
            std::cout << "\n";
            
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
        friend matrix operator-(matrix obj1, matrix obj2);
        friend matrix operator*(matrix obj, int num);
        friend matrix operator*(matrix obj1, matrix obj2);
};

matrix operator*(matrix obj1, matrix obj2){
    matrix result;

    //top row
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(j == 0){
                result.toprow[i] += obj1.toprow[j] * obj2.toprow[i];
                result.middlerow[i] += obj1.middlerow[j] * obj2.toprow[i];
                result.bottomrow[i] += obj1.bottomrow[j] * obj2.toprow[i];
            }
            else if(j == 1){
                result.toprow[i] += obj1.toprow[j] * obj2.middlerow[i];
                result.middlerow[i] += obj1.middlerow[j] * obj2.middlerow[i];
                result.bottomrow[i] += obj1.bottomrow[j] * obj2.middlerow[i];
            }
            else if(j == 2){
                result.toprow[i] += obj1.toprow[j] * obj2.bottomrow[i];
                result.middlerow[i] += obj1.middlerow[j] * obj2.bottomrow[i];
                result.bottomrow[i] += obj1.bottomrow[j] * obj2.bottomrow[i];
            }
            
        }
    }

    //middle row
    for(int i = 0; i < 3; i++){

    }
    //bottom row
    return result;
}

matrix operator*(matrix obj, int num){
    matrix result;
    for(int i = 0; i < 3; i++){
        result.toprow[i] = obj.toprow[i] * num;
    }

    for(int i = 0; i < 3; i++){
        result.middlerow[i] = obj.middlerow[i] * num;
    }

    for(int i = 0; i < 3; i++){
        result.bottomrow[i] = obj.bottomrow[i] * num;
    }

}

matrix operator+(matrix obj1, matrix obj2){
    matrix result;
    for(int i = 0; i < 3; i++){
        result.toprow[i] = obj1.toprow[i] + obj2.toprow[i];
    }
    for(int i = 0; i < 3; i++){
        result.middlerow[i] = obj1.middlerow[i] + obj2.middlerow[i];
    }
    for(int i = 0; i < 3; i++){
        result.bottomrow[i] = obj1.bottomrow[i] + obj2.bottomrow[i];
    }
    return result;
}

matrix operator-(matrix obj1, matrix obj2){
    matrix result;
    for(int i = 0; i < 3; i++){
        result.toprow[i] = obj1.toprow[i] - obj2.toprow[i];
    }
    for(int i = 0; i < 3; i++){
        result.middlerow[i] = obj1.middlerow[i] - obj2.middlerow[i];
    }
    for(int i = 0; i < 3; i++){
        result.bottomrow[i] = obj1.bottomrow[i] - obj2.bottomrow[i];
    }
    return result;
}


int main(int argc, char* agrv[]){
    matrix pog;
    pog(2,1) = 9;
    //pog.print();
    matrix test1, test2, test3, test4, test5;
    test1.settop(1,3,0);
    test1.setmiddle(0,1,3);
    test1.setbottom(0,0,1);

    test2.settop(1,0,0);
    test2.setmiddle(4,1,0);
    test2.setbottom(0,4,1);

    test3 = test1 + test2;
    test4 = test1 - test2;
    test5 = test1 * test2;
    std::cout << "testing operator +\n";
    test3.print();
    std::cout << "testing operator -\n";
    test4.print();
    std::cout << "testing operator *\n"; 
    test5.print();

}