#include <iostream>
#include <fstream>

int main(int argc, char* argv[]){
    std::ifstream myfile;
    myfile.open("Results.txt", std::ios::binary);
    myfile.seekg(0, std::ios::end);
    int size = myfile.tellg();
    std::cout << size << std::endl;
    myfile.close();

    float* buffer = new float[100];
    myfile.open("Results.txt", std::ios::out);
    std::string tmp;
    for(int i = 0; i < 100; i++){
        std::getline(myfile, tmp, '\n');
        *(buffer + i) = stof(tmp);
        tmp.clear();
    }
    myfile.close();

    std::ofstream newfile("ResultsClone.txt");
    for(int i = 0; i < 100; i++){
        newfile << *(buffer + i) << "\n";
    }

    delete buffer;
}