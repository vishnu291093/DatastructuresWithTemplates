
#include<iostream>
#include <vector>


template <class T>
class Heaptemplate{
    public:
        Heaptemplate(T data)
        {
            InsertHeap(data);
        }
        ~Heaptemplate(){};
        void InsertHeap(T);
        T PopHeap();
        void PrintHeap();
    private:
        std::vector<T>  Heap ;
        void HeapifyUp(int index);
        void HeapifyDown(int index);

};
template <class T>
void Heaptemplate<T>::PrintHeap()
{
    for(int i =0;i<Heap.size();i++)
    {
        std::cout<< Heap[i]<<std::endl;
    }
}

template <class T>
void Heaptemplate<T>::HeapifyDown(int Index)
{
    int LeftChild= int(2*Index +1);
    int RightChild = int(2*Index +2);

    if (LeftChild > Heap.size())
        return;
    int NewIndex = Index;

    if(Heap[LeftChild] < Heap[NewIndex])
    {
        NewIndex = LeftChild;
    }

    if(RightChild< Heap.size() && Heap[RightChild] < Heap[NewIndex])
    {
        NewIndex = RightChild;

    }
    if(NewIndex != Index)
    {
        int temp = Heap[Index];
        Heap[Index] = Heap[NewIndex];
        Heap[NewIndex] = temp;
        HeapifyDown(NewIndex);


    }
}

template <class T>
void Heaptemplate<T>::InsertHeap(T data)
{   int length = Heap.size();
    Heap.push_back(data);
    HeapifyUp(length);
}

template <class T>
void Heaptemplate<T>::HeapifyUp(int Index)
{
    if (Index == 0)
    return;
    else
    {
        int Parent = int(Index -2)/2;
        if(Heap[Index] < Heap[Parent] )
        {
            T temp = Heap[Parent];
            Heap[Parent]  = Heap[Index];
            Heap[Index] = temp;
            HeapifyUp(Parent);
        }
    }
}

template <class T>
T Heaptemplate<T>::PopHeap()
{
    T value= Heap[0];
    int length = Heap.size();
    Heap[0] = Heap[length - 1];
    Heap.pop_back();
    HeapifyDown(0);
    return value;

}




int main()
{
Heaptemplate<int> Heap(99);
Heap.InsertHeap(7);
Heap.InsertHeap(10);
Heap.InsertHeap(1);
Heap.InsertHeap(5);
Heap.InsertHeap(1000);
Heap.InsertHeap(2);
Heap.PrintHeap();
std::cout<<"popped heap is "<<Heap.PopHeap()<<std::endl;

std::cout<<"df"<<std::endl;
Heap.PrintHeap();
Heap.InsertHeap(20);
Heap.PrintHeap();
}


