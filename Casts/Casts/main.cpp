//
//  main.cpp
//  Casts
//
//  Created by Анастасия Мехова on 14.01.2025.
//  Преобразования
// static cast к базовому классу от наследника (наоборот небезопасно)
// dynamic от базового к наследнику (работает медленнее чем static) для его работы нужно хотя бы одна вирт ф-ия; выводит ошибку
//

#include <iostream>


class Base {
public:
    int _base = 1;
    virtual void o_1() {}
};

class Derived : public Base {
public:
    int _derived = 10;
    
};


void f(Base const * const a) {
    Base* s = const_cast<Base*>(a);
    s->_base = 3;
}



int main(int argc, const char * argv[]) {
    
    Base* b_1 = new Base();
    
    Derived* d_1 = static_cast<Derived*>(b_1);
    
    std::cout<< d_1->_base << std::endl;
    std::cout<< d_1->_derived << std::endl;
    
    Derived* d_2 = dynamic_cast<Derived*>(b_1);
    if(d_2 != nullptr) {
        std::cout<< d_2->_base << std::endl;
        std::cout<< d_2->_derived << std::endl;
    }
    
    std::cout<< "___" << std::endl;
    
    Base* b_2 = new Derived();
    Derived* d_3 = static_cast<Derived*>(b_2);
    
    std::cout<< d_3->_base << std::endl;
    std::cout<< d_3->_derived << std::endl;
    
    Derived* d_4 = dynamic_cast<Derived*>(b_2);
    if(d_4 != nullptr) {
        std::cout<< d_4->_base << std::endl;
        std::cout<< d_4->_derived << std::endl;
    }
    
    std::cout<< "Changing d_4" << std::endl;
    
    
    std::cout<< d_4->_base << std::endl;
    f(d_4);
    std::cout<< d_4->_base << std::endl;
    
    int value = 42;
    void* void_ptr = reinterpret_cast<void*>(&value);
    int* int_ptr = reinterpret_cast<int*>(void_ptr);
    
    std::cout<< *int_ptr << std::endl;
    
    
//    
//    
//    Base* b = new Derived();
//    std::cout << b->_base << std::endl;
//    Derived* d = static_cast<Derived*>(b);
//    std::cout<< d->_base << std::endl;
//    std::cout<< d->_derived << std::endl;
//    
//    
//    Derived* d = dynamic_cast<Derived*>(b);
//    if(d != nullptr) {
//        std::cout<< d->_derived << std::endl;
//    }
    
    return 0;
    
    
}
