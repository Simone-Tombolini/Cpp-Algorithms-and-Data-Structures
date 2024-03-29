# Stack-data structure

from wikipedia:

In computer science, a stack is an abstract data type that serves as a collection of elements, with two main operations:

Push, which adds an element to the collection, and
Pop, which removes the most recently added element that was not yet removed.
Additionally, a peek operation can, without modifying the stack, return the value of the last element added. Calling this structure a stack is by analogy to a set of physical items stacked one atop another, such as a stack of plates.

The order in which an element added to or removed from a stack is described as last in, first out, referred to by the acronym LIFO. As with a stack of physical objects, this structure makes it easy to take an item off the top of the stack, but accessing a datum deeper in the stack may require taking off multiple other items first.

Considered as a linear data structure, or more abstractly a sequential collection, the push and pop operations occur only at one end of the structure, referred to as the top of the stack. This data structure makes it possible to implement a stack as a singly linked list and as a pointer to the top element. A stack may be implemented to have a bounded capacity. If the stack is full and does not contain enough space to accept another element, the stack is in a state of stack overflow.

This images can help to visualize how this class work;

![Stack image](https://github.com/Simone-Tombolini/Cpp-Algorithms-and-Data-Structures/blob/main/Stack/Stack.png)

