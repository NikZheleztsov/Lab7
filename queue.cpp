//Queue implementation

#include <iostream>
#include <climits>

struct queue_knot
{
	int data;
	queue_knot* link;
};

struct queue
{
	queue_knot* top;
	queue_knot* bottom;
};

void construct(queue& que)
{
	que.top = nullptr;
	que.bottom = nullptr;
}

unsigned int size (const queue& que) 
{
    int size = 1;
    if (que.top != nullptr)
    {
        queue_knot* new_one = que.top;

        while (new_one->link != nullptr)
        {
            ++size;
            new_one = new_one->link;
        }

        return size;

    } else 
    {
        std::cout << "Your queue is empty\n";
        return 0;
    }
}

queue_knot* pop (queue& que) 
{
    if (que.top != nullptr) 
    {
        queue_knot* new_one = que.top;

        if (que.top != que.bottom)
            que.top = que.top->link;
        else {
            que.top = nullptr;
            que.bottom = nullptr;
        }

        new_one->link = nullptr;

        return new_one;

    } else 

        return 0;
}

void destruct(queue& que)
{
	int s = size(que);
	for (int i = 0; i < s; i++)
		delete pop(que);

    delete que.top;
}

void push (queue& que, int data)
{
	queue_knot* new_knot = new queue_knot;
	new_knot->data = data;
	new_knot->link = nullptr;

	if (que.bottom != nullptr)
		que.bottom -> link = new_knot;
	que.bottom = new_knot;

	if (que.top == nullptr)
	{
		que.top = new_knot;
	}
}
	
void print (const queue& que) 
{
    if (que.top != nullptr)
    { 
        queue_knot* new_one = que.top;
        while (new_one != nullptr)
        {
            std::cout << new_one->data << ' ';
            new_one = new_one->link;
        }

    } else 
        std::cout << "Your queue is empty";
}

int main () 
{
    queue root;
    construct(root);

    std::string str;
    std::cout << "In order to end input, print ' ' \nPlease, enter elements of queue (1 or more):\n";
    std::string a;
    std::getline(std::cin, a);

    do {
	    push(root, stoi(a));
        std::getline(std::cin, a);
	} while (a != " ");

    std::cout << "End of input\n";

    while (str != "quit" && str != "q")
    {
        std::cout << "> ";
        std::cin >> str;
        if (str == "push")
        {
            std::cout << "In order to end input, print ' ' \nPlease, enter elements of queue:\n";
            std::string a;
            std::cin.ignore(INT_MAX, '\n');
            std::getline(std::cin, a);

            do {
                push(root, stoi(a));
                std::getline(std::cin, a);
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
            queue_knot* pop_elem = pop(root);
            std::cout << "Popped element: " << pop_elem->data << std::endl;
            delete pop_elem; // по заданию pop возвращает node. Т.к. мы его не планируем использовать, память надо очистить, чтобы избежать утечки
        } 
    }

    destruct(root);
    return 0;
}
	
