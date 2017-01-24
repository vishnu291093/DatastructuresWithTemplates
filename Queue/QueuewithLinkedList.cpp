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
class queuelinked
{
    private:
        int counter = 0;
        Node<T>* first = NULL;
        Node<T>* last = NULL;
    public:
        queuelinked(T data)
        {

           Enqueue(data);

        }
        void Dequeue()
        {   if(counter != 0)
            {
                Node<T>* temp = first;
                first = first->next;
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
        std::cout<<first->Data<<std::endl;
    }

    void Count()
    {
        std::cout<<counter<<std::endl;
    }

    void Enqueue(T item)
    {
    Node<T> * temp =last;
    Node<T> * newnode=new Node<T>(item, NULL);
    if ( counter==0 ) {
           // Add the first element
           first = last = newnode;
    }
    else
    {
    temp->next=newnode;
    last=newnode;
    }
    counter++;
   }
    ~queuelinked(){};

};

int main()
{
queuelinked<int> * star = new queuelinked<int>(10);
star->Enqueue(100);
star->Dequeue();
star->Top();

return 0;
}
