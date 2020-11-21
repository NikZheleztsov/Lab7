//Queue implementation

#include <iostream>

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
	que.top = NULL;
	que.bottom = NULL;
}

unsigned int size (const queue& que) 
{
    int size = 1;
	queue_knot* new_one = que.top;

	while (new_one->link != NULL)
    {
			 ++size;
	  		 new_one = new_one->link;
    }

    return size;
}

queue_knot* pop (queue& que) 
{
    if (size(que) > 1) 
    {
        queue_knot* new_one = que.top;
        que.top = que.top->link;
        return new_one;
    } else return 0;
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
	new_knot->link = NULL;
	if (que.bottom != NULL)
		que.bottom -> link = new_knot;
	que.bottom = new_knot;

	if (que.top == NULL)
	{
		que.top = new_knot;
	}
}
	
void print (const queue& que) 
{
	queue_knot* new_one; 
	std::cout << que.top->data;
	if (que.top->link != NULL)
	{
		new_one = que.top->link;
	
		do {
			std::cout << new_one->data;
			if (new_one->link != 0)
				new_one = new_one->link;
		} while (new_one ->link != NULL);

	    std::cout << new_one->data;
	}
}

int main () 
{
    queue root;
    construct(root);

    std::string str;
    std::cout << "In order to end input, print '-1' \nPlease, enter elements of queue (1 or more):\n";
	int a;
    do {
		a = 0;
		std::cin >> a;
	    if (a != -1) push(root, a);
	} while (a != -1);
    std::cout << "End of input\n";

    while (str != "quit")
    {
        std::cout << "Please, enter command:\n";
        std::cin >> str;
        if (str == "push")
        {
            std::cout << "In order to end input, print '-1' \nPlease, enter elements of queue:\n";
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
            } else std::cout << "Unable to pop an element\n";
        } 
    }

    destruct(root);
    return 0;
}
	
