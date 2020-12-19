//Stack implementation

#include <iostream>
#include <vector>
#include <climits>

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
    st.top = nullptr;
}

int size(const Stack& st)
{
    int size = 0;

    if (st.top != nullptr)
    {
        Stack_knot* new_one = st.top;
        size++;
        
        while ((new_one = new_one->link) != nullptr)
        {
            //new_one = new_one->link;
            size++;
        }
    }

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
    if (st.top != nullptr)
    {
        Stack_knot* new_one = st.top;
        if (size(st) == 1)
           st.top = nullptr; 
        else 
           st.top = new_one->link;
        
        new_one->link = nullptr;
        return new_one;

    } else {
        std::cout << "Your stack is empty\n";
        return nullptr;
    }
}

void print(const Stack& st)
{
    if (st.top != nullptr)
    {
        Stack_knot* new_one = st.top;
        while (new_one != nullptr)
        {
            std::cout << new_one->data << ' ';
            new_one = new_one->link;
        }

    } else
        std::cout << "Your stack is empty";
}

void destruct(Stack& st)
{
    while (st.top != nullptr)
    {
        delete pop(st);
    }
}

int main () 
{
    Stack root;
    construct(root);

    std::string str;
    std::cout << "In order to end input, print ' ' \nPlease, enter elements of stack:\n";
    std::string a;

    do {
        std::getline(std::cin, a);
        if (a != " ") 
            push(root, stoi(a));
    } while (a != " ");

    std::cout << "End of input\n";

    while (str != "quit" && str != "q")
    {
        std::cout << "> ";
        std::cin >> str;
        if (str == "push")
        {
            std::cout << "In order to end input, print ' ' \nPlease, enter elements of stack:\n";
            std::string a;
            std::cin.ignore(INT_MAX, '\n');

            do {
                std::getline(std::cin, a);
                if (a != " ")
                    push(root, stoi(a));
            } while (a != " ");
            std::cout << "End of input\n";

        } else if (str == "print")
        {
            print(root);
            std::cout << std::endl;

        } else if (str == "size")
            std::cout << size(root) << std::endl;

        else if (str == "pop")
        {
            Stack_knot* pop_elem = pop(root);
            if (pop_elem != 0)
            {
                std::cout << "Popped element: " << pop_elem->data << std::endl;
            }

            delete pop_elem; 
        } 
    }

    destruct(root);
    return 0;
}
