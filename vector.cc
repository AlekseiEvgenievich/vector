#include <stddef.h>
#include <iostream>
class my_out_of_range:public std::exception{
    const char* what() const noexcept override{
        return "out of range!";
    }
};
template <typename T>
class Vector{
private:
    T* array;
    size_t size;
    size_t capacity = 4;
public:
    Vector(T* array_,size_t size_){
        if (size_ < capacity){
            size = size_;
            array = new T[capacity];
            for(int i=0;i<size;++i){
                array[i] = array_[i];
            }
        }
        else{
            size = size_;
            capacity = 2*size;
            array = new T[capacity];
            for(int i=0;i<size;++i){
                array[i] = array_[i];
            }
        }
    }
    ~Vector(){
        delete [] array;
    }
    void push_back(T a){
        std::cout << "jjjj" << std::endl;
        if ((size) < capacity){
            std::cout << "jjjj" <<size<< std::endl;
            array[size] = a;
            size = size + 1;
        }
        else{
            T * result = nullptr;
            try {
                result = new T[capacity];
            }
            catch (const std::bad_alloc& e) {
                std::cerr << "Failed to allocate memory in constructor: " << e.what() << std::endl;
                throw e;
            }
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
        else{
             throw std::underflow_error("Vector is empty");
        }
    }
    void insert(T a,int index){
        std::cout << "jjjj" << std::endl;
        if((index<0)&&(index>size)){
            //throw std::out_of_range("Index is out of range");
            throw my_out_of_range();
        }
        if ((size) < capacity){
            std::cout << "jjjj" <<size<< std::endl;
            for(int i = size;i>index;--i){
                    array[i] = array[i-1];
                }
            array[index] = a;

            size = size + 1;
            std::cout << "bbb" <<size<< std::endl;
            capacity = 2*size;
          
        }
        else{
            std::cout << "bbb" <<size<< std::endl;
            capacity = 2*size;
            T* result = nullptr;
            try {
                result = new T[capacity];
            }
            catch (const std::bad_alloc& e) {
                std::cerr << "Failed to allocate memory in constructor: " << e.what() << std::endl;
                throw e;
            }
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
        if (((index>=0)&&(index<size))){
            std::cout << "jjjj" <<size<< std::endl;
            for(int i = index;i<size-1;++i){
                array[i] = array[i+1];
            }
            size = size - 1;
        }
        else{
            throw my_out_of_range();
           // throw std::out_of_range("Index is out of range");
            
        }
    }
    
    void Print(){
        for(int i=0;i<size;++i){
            std::cout << array[i] << " ";
        }
    }
};

int main(){
    try{
    double a[3] = {2.1,3.1,5.1};
    Vector v(a,3);
  //  v.Print();
    v.push_back(7);
  //  v.Print();
        v.remove(10);
        v.Print();
    }
    catch (std::exception& ex) {
           std::cerr << "Caught exception: " << ex.what() << std::endl;
       }
    return 0;
}
