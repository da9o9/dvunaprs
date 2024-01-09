
#include <iostream>

struct Node{
    int x;
    Node *Next, *Prev, *Data;
};
int schet = 0;
class List{
    Node *Head, *Tail;
public:
    List(): Head(NULL), Tail(NULL){};
    ~List();
    void Vivod();
    void Add(int x);
    void Sort();
};

List::~List(){
    while(Head){
        Tail = Head -> Next;
        delete Head;
        Head = Tail;
    }
}

void List::Add(int x){
    Node *temp = new Node;
    temp -> Next = NULL;
    temp -> x = x;
    if(Head != NULL){
        temp -> Prev = Tail;
        Tail -> Next = temp;
        Tail = temp;
    }
    else{
        temp -> Prev = NULL;
        Head = Tail = temp;
    }
    ++schet;
    
}

void List::Vivod(){
    bool k;
    std::cout << "Способ вывода(Прямой(0), Обратный(1)):" << std::endl;
    std::cin >> k;
    if(k){
        Node *temp = Tail;
        while (temp != NULL){
            std::cout << temp -> x << " ";
            temp = temp -> Prev;
        }
        std::cout << std::endl;
    }
    else{
        Node *temp = Head;
        while (temp != NULL)
        {
            std::cout << temp -> x << " ";
            temp = temp -> Next;
        }
        std::cout << std::endl;
    }
}



void List::Sort(){
    Node* t = new Node;
        Node* prev = Head;
        Node* next = Head -> Next;
        while (prev -> Next){
            while (next){
                if ((prev -> x) > (next -> x)){
                    t -> x = prev -> x;
                    prev -> x = next -> x;
                    next -> x = t -> x;
                }
                next = next -> Next;
            }
            prev = prev -> Next;
            next = prev -> Next;
        }
    return;
}

int main(){
    List list;
    list.Add(2);
    list.Add(1);
    list.Add(3);
    list.Add(4);
    list.Add(5);
    list.Sort();
    list.Vivod();
    
    return 0;
}

