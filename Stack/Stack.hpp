#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <ostream> 
#include <cassert> 

template<typename T>
class Stack
{
private:

    typedef int size_type;
    /**
    * @brief Single item of the stack 
    * only internal usage, this class rappresent the value of a signle poin of the stack
    */
    struct Node
    {
        /* Single item of the stack */

        //data
        T value;
        Node* under;

        //method

      /**
       * @brief Construct a new Node object
       * 
       */
        Node() : under(nullptr) {}

        /**
         * @brief Construct a new Node object
         * 
         * @param value the value to put in the node
         * @param under the connection between node, if is null ptr is the bottom
         */
        Node(T value, Node* under) :
            value(value),
            under(under) {}

        /**
         * @brief Copy Constructor 
         * 
         * @param other 
         */
        Node(const Node& other) : value(other.value), under(other.next) {}

        /**
         * @brief Destroy the Node object
         * 
         */
        ~Node() {}

        /**
         * @brief redfinition of = operator
         * 
         * @param other rigth 
         * @return Node& left
         */
        Node& operator=(const Node& other) {
            value = other.value;
            under = other.under;
            return *this;

        }
    };   

    //pointer to the top of the stack
    Node* _top;
    //size of the stack
    size_type _size;

public:

    /**
     * @brief Construct a new Stack object
     * 
     */
    Stack() :
        _top(nullptr),
        _size(0) {}

    /**
     * @brief copy constuctor
     * 
     * @param other the original stack 
     */
    Stack(const Stack &other): _top(nullptr), _size(0) 
    {
        Node *curr = other._top;
        try {
            while (curr != nullptr)
            {
                this->push(curr->value);
                curr = curr->under;
            }
            this->reverse();
        }
        catch (...) {

            this->clear();
            throw;
        }
    }

    /**
     * @brief Destroy the Stack object
     * 
     */
    ~Stack() {
        clear();
    }

    /**
     * @brief Construct a new Stack object whith iteretor
     * use a defind iterator to create a new stak whith the data, need to be a forward iteraro
     * the begin will start to the bottom of the stack
     * @tparam iter the itaretor
     * @param b begin
     * @param e end
     */
    template<typename iter>
    Stack(iter b, iter e) : _top(nullptr), _size(0)
    {
        try {
            for (; b != e; ++b) {
                push(static_cast<T>(*b));//all the push 
            }
        }
        catch (...) {//if new fail need to remove memory leak
            this->clear();
            throw;
        }
    }
    /**
     * @brief redfinition of = operator
     * 
     * @param other rigth
     * @return Stack& left
     */
    Stack& operator=(const Stack& other) {
        if (this != &other) {
            Stack tmp(other);
            std::swap(this->_top, tmp._top);
            std::swap(this->_size, tmp._size);
        }
        return *this;
    }

    //utiltys

    /**
     * @brief print the stack on std::cout
     * Debug metohd
     */
    void print() 
    {
        std::cout << "Top" << std::endl;
        Node *curr = _top;
        while (curr != nullptr) {
            std::cout << curr->value << std::endl;
            curr = curr->under;
        }
        std::cout << "Bottom" << std::endl;

    }
    /**
     * @brief Reverse the stack
     * using other 2 stack reverse the original stack to another
     */
    void reverse() 
    {
        if (this->is_empty() == false) {

            Stack<T> tmp1;
            Stack<T> tmp2;

            try{//this is for eventual new in push() fails
            //create 2 temporary stack, got ot the memoary heap
   
            //stack to tmp1
            while (this->is_empty() == false)
            {
                tmp1.push(this->_top->value);
                this->pop();
            }

            //tmp1 to tmp2
            while (tmp1.is_empty() == false)
            {
                tmp2.push(tmp1._top->value);
                tmp1.pop();
            }

            //tmp2 to stack
            while (tmp2.is_empty() == false)
            {
                this->push(tmp2._top->value);
                tmp2.pop();
            }
            //should be no memory leak but for seafty i do 2 clear on the tmp
            tmp1.clear();
            tmp2.clear();
      
            }
            catch (...) 
            {
                //if new fail should be memory leak for seafty clear all
                this->clear();
                tmp1.clear();
                tmp2.clear();
    
                throw;
            }
        }
    }
    /**
     * @brief check if the stack is empty
     * simple method that determine if a stack is epty or not
     * @return true if stack is empty
     * @return false if stack is not empty
     */
    bool is_empty() {
        if (_top == nullptr) {
            return true;
        }
        return false;
    }
    /**
     * @brief retur the size of the array
     * 
     * @return size_type size of stack
     */
    size_type size() {
        return _size;
    }

    /**
     * @brief push a T value in the stack
     * push in to the stack a value, use memory on the heap
     * @param _value the value to insert
     */
    void push(const T& _value) {
        if (this->is_empty() == true)//empty stack
        {
            Node* n = new Node(_value, nullptr);
            _top = n;
            ++_size;
        }
        else {
            Node* n = new Node(_value, _top);
            _top = n;
            ++_size;
        }
    }
    /**
     * @brief pop the first item on the stack
     * delete the first item on the stack, the return is the item popped, if is empty
     * @return T the item popped
     * @pre stack cannot be empty
     */
    T pop() {
        assert(this->is_empty()==false);
        T tmp = _top->value;
        if (!this->is_empty()) {

            Node* tmp = _top;
            _top = tmp->under;
            --_size;
            delete tmp;

        }
        return tmp;
    }
    /**
     * @brief clear all the stack
     * pop all the content of the stack
     * @post size must be 0
     */
    void clear() {
        while (!this->is_empty())
        {
            this->pop();
        }
        assert(this->size()==0);
    }

    /**
     * @brief standar redifinig output << operator
     * 
     * @param os 
     * @param stack 
     * @return std::ostream& 
     */
    friend std::ostream& operator<<(std::ostream& os,
        const Stack &stack) {

        Node *curr = stack._top;
        while (curr != nullptr) {
            os << curr->value << " ";
            curr = curr->under;
        }

        return os;
    }


    /**
     * @brief standard const_iterator
     * 
     */
    class const_iterator {
        
    public:
        typedef std::forward_iterator_tag iterator_category;
        typedef T value_type;
        typedef ptrdiff_t difference_type;
        typedef const T* pointer;
        typedef const T& reference;


        const_iterator() : ptr(nullptr) {}

        const_iterator(const const_iterator& other) : ptr(other.ptr) {}

        const_iterator& operator=(const const_iterator& other) {
            ptr = other.ptr;
            return this;
        }

        ~const_iterator() {}

        reference operator*() const {
            return ptr->value;
        }

        pointer operator->() const {
            return &(ptr->value);
        }

        const_iterator operator++(int) {
            const_iterator tmp(*this);
            ptr = ptr->under;
            return tmp;
        }

        const_iterator& operator++() {
            ptr = ptr->under;
            return *this;
        }

        bool operator==(const const_iterator& other) const {
            return (ptr == other.ptr);
        }

        bool operator!=(const const_iterator& other) const {
            return (ptr != other.ptr);
        }

       

    private:
      
        friend class Stack; 

        const Node *ptr;
        
        const_iterator(const Node *p) :  ptr (p) {}

       

    }; 

    /**
     * @brief const iteretor to the top of the stack 
     * 
     * @return const_iterator 
     */
    const_iterator begin() const {
        return const_iterator(_top);
    }

    /**
     * @brief @brief const iteretor to the bottom of the stack
     * 
     * @return const_iterator 
     */
    const_iterator end() const {
        return const_iterator(nullptr);
    }


};
#endif



