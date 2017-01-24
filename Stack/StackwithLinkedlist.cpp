
#include <iostream>

template<class  T>
class Node
{
    public:
    T Data;
    Node<T> * next=NULL;
    Node(T Data,Node<T> * next)
    {
        this->Data=Data;
        this->next=next;

    }
    ~Node(){};
};

template<class  T>
class stacklinked
{
    private:
        int counter = 0;
        Node<T>* top = NULL;
    public:
        stacklinked(T data)
        {

           Push(data);

        }
        void Pop()
        {   if(counter != -1 && top!=NULL)
            {
                Node<T>* temp = top;
                top = top->next;
                delete temp;
                counter = counter -1;
            }
            else
            {
                std::cout <<"Inadequate objects"<<std::endl;

            }

        }
    void Top()
    {
        std::cout<<top->Data<<std::endl;
    }

    void Count()
    {
        std::cout<<counter<<std::endl;
    }

    void Push(T item)
    {
    Node<T> * temp =top;
    Node<T> * newnode=new Node<T>(item, temp);
    top = newnode;
    counter++;
    }
    ~stacklinked();

};


int main()
{
stacklinked<int> * star = new stacklinked<int>(10);
star->Count();
star->Pop();
star->Count();
star->Push(100);
star->Count();
star->Top();

return 0;
}
