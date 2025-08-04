#include <stddef.h>
#include <iostream>
class Vector{
private:
    int* array;
    size_t size;
    size_t capacity = 4;
public:
    Vector(int* array_,size_t size_){
        if (size_ < capacity){
            size = size_;
            array = new int[capacity];
            for(int i=0;i<size;++i){
                array[i] = array_[i];
            }
        }
        else{
            size = size_;
            capacity = 1.5*capacity;
            array = new int[capacity];
            for(int i=0;i<size;++i){
                array[i] = array_[i];
            }
        }
    }
    ~Vector(){
        delete [] array;
    }
    void push_back(int a){
        std::cout << "jjjj" << std::endl;
        if ((size+1) < capacity){
            std::cout << "jjjj" <<size<< std::endl;
            array[size] = a;
            size = size + 1;
        }
        else{
            std::cout << "bbb" <<size<< std::endl;
            capacity = 1.5*capacity;
            int* result = new int[capacity];
            for(int i=0;i<size;++i){
                result[i] = array[i];
            }
            result[size] = a;
            size += 1;
            delete [] array;
            array = result;
        }
    }
    void Print(){
        for(int i=0;i<size;++i){
            std::cout << array[i];
        }
    }
};

int main(){
    int a[3] = {2,3,5};
    Vector v(a,3);
    v.Print();
    v.push_back(7);
    v.Print();
    return 1;
}
