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
    void pop_back(int a){
        std::cout << "jjjj" << std::endl;
        if ((size+1) < capacity){
            std::cout << "jjjj" <<size<< std::endl;
            int* result = new int[size+1];
            result[0] = a;
            for(int i=1;i<=size;++i){
                result[i] = array[i-1];
            }
            size = size + 1;
            delete [] array;
            array = result;
        }
        else{
            std::cout << "bbb" <<size<< std::endl;
            capacity = 2*size;
            int* result = new int[capacity];
            result[0] = a;
            for(int i=1;i<=size;++i){
                result[i] = array[i-1];
            }
            size += 1;
            delete [] array;
            array = result;
        }
    }
    void insert(int a,int index){
        std::cout << "jjjj" << std::endl;
        if ((size+1) < capacity){
            std::cout << "jjjj" <<size<< std::endl;
            int* result = new int[size+1];
            //result[0] = a;
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
            std::cout << "jjjj" <<size<< std::endl;
            int* result = new int[size-1];
            for(int i = 0;i<index;++i){
                result[i] = array[i];
            }
            for(int i = index;i<size;++i){
                result[i] = array[i+1];
            }
            size = size - 1;
            delete [] array;
            array = result;
        
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
