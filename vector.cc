#include <stddef.h>
#include <iostream>
class Vector{
private:
    int* array;
    size_t size;
    size_t capacity = 5;
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
            capacity = 1.5*size;
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
            capacity = 2*size;
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
    void pop_back(){
        std::cout << "jjjj" <<size<< std::endl;
        if (size > 0){
            size = size - 1;
        }
    }
    void insert(int a,int index){
        std::cout << "jjjj" << std::endl;
        if ((size+1) < capacity){
            std::cout << "jjjj" <<size<< std::endl;
            for(int i = size;i>index;--i){
                    array[i] = array[i-1];
                }
            array[index] = a;

            size = size + 1;
        }
        else{
            std::cout << "bbb" <<size<< std::endl;
            capacity = 2*size;
            int* result = new int[capacity];
            for(int i = 0;i<index;++i){
                result[i] = array[i];
            }
            result[index] = a;
            for(int i = index+1;i<=size;++i){
                result[i] = array[i-1];
            }
            size = size + 1;
            delete [] array;
            array = result;
        }
    }
    void remove(int index){
        if (index>=0){
            std::cout << "jjjj" <<size<< std::endl;
            for(int i = index;i<size-1;++i){
                array[i] = array[i+1];
            }
            size = size - 1;
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
  //  v.Print();
  //  v.pop_back(7);
  //  v.Print();
    v.remove(2);
    v.Print();
    return 1;
}
