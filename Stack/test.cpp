#include <iostream>

#include "Stack.hpp"
//test
//not commented

int main()
{
    Stack<int> stack;
    std::cout << "is empty? " << stack.is_empty() << std::endl;
    //stack.pop();
    stack.push(1);
    std::cout << "is empty? " << stack.is_empty() << std::endl;
    
    std::cout << "size" << stack.size() << std::endl;
    stack.pop();
    stack.push(100);
    int i = stack.pop();
    std::cout << "i variable " << i << std::endl;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    Stack<int> stack2(stack);
    stack.print();
    std::cout << "stack 2" << std::endl;
    stack2.print();
    stack.reverse();
    std::cout << "reverse e << operator" << std::endl;
    std::cout << stack << std::endl;
    std::cout << "size " << stack.size() << std::endl;
    stack.clear();
    std::cout << "clear" << std::endl;
    stack.print();
    std::cout << "size " << stack.size() << std::endl;
    stack2.print();
    std::cout << stack;
    stack.push(4);
    stack.push(5);
    stack2 = stack;
    std::cout << "operator =" << std::endl;
    stack2.print();
    

    double a[5] = {0.1, 2.4, 4.445, 7.553, 3.14};
    Stack<double>  stack3(a, a+5);
    stack3.print();
    
    Stack<int> stack4(stack2.begin(), stack2.end());
    stack4.print();
    stack2.clear();
}
