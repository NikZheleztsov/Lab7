//Stack implementation
//More than 2 elements 

#include <iostream>
#include <vector>

struct Stack_knot
{
    int data;
    Stack_knot* link;
};

struct Stack 
{
    Stack_knot* top; 
};

////////////////////////////////////////////////////////

void construct (Stack& st)
{
    Stack_knot* zero = new Stack_knot;
    st.top = zero;
    st.top->link= NULL;
}

int size(const Stack& st)
{
    int size = 1;

    Stack_knot* new_stack = st.top->link;
    do {
        ++size;
        new_stack = new_stack->link;
    } while (new_stack->link != NULL);

    return size;
}

void push (Stack& st, int data)
{
    Stack_knot* new_one = new Stack_knot;
    new_one->data = data;
    new_one->link = st.top;
    st.top = new_one;
}

Stack_knot* pop (Stack& st) // return
{
    if (size(st) > 2)
    {
        Stack_knot* new_st = st.top;
        st.top = st.top->link;
        return new_st;

    } else {
        std::cout << "Unable to pop an element\n";
        return 0;
    }
}

void print(const Stack& st)
{
    std::cout << st.top->data;
    Stack_knot* new_stack = st.top->link;
    do {
    std::cout << new_stack->data;
    new_stack = new_stack->link;
    } while (new_stack->link != NULL);
}

void destruct(Stack& st)
{
    int s = size(st);
    for (int i = 0; i < s + 1; i++)
        delete pop(st);
}

int main () 
{
    Stack root;
    construct(root);

    std::string str;
    std::cout << "In order to end input, print '-1' \nPlease, enter elements of stack:\n";
    int a;
	do {
		a = 0;
		std::cin >> a;
		if (a != -1) push(root, a);
    } while (a != -1);

    std::cout << "End of input\n";

    std::cout << "Please, enter command:\n";

    while (!(str == "quit"))
    {
        std::cin >> str;
        if (str == "push")
        {
            std::cout << "In order to end input, print '-1' \nPlease, enter elements of stack:\n";
            int a;
            do {
                a = 0;
                std::cin >> a;
                if (a != -1) push(root, a);
            } while (a != -1);
            std::cout << "End of input\n";
        } else if (str == "print")
        {
            print(root);
            std::cout << std::endl;
        } else if (str == "size")
            std::cout << size(root) << std::endl;
        else if (str == "pop")
        {
            if (pop(root) != 0)
            {
                std::cout << "Popped element: " << pop(root)->data << std::endl;
                print(root);
                std::cout << std::endl;
                std::cout << "Size of stack(after pop): " << size(root) << std::endl;
            }
        }
    }

    destruct(root);
    return 0;
}
