#include<iostream>
using namespace std;

class LL2{

    private:   
        struct Node
        {
            int value;
            Node* next;

            Node(int value){
                this->value=value;
                this->next=nullptr;
            }
            Node(int value,Node* next){
                this->value=value;
                this->next=next;
            }
            
        };

        Node* head;
        Node* tail;
        int size;

    public:
        LL2(){
            size=0;
            head=nullptr;
            tail=nullptr;
        }

        void insertAtFirst(int val){
            Node* node=new Node(val);
            node->next=head;
            head=node;

            if(tail==nullptr){
                tail=head;
            }

            size++;
        }

        void display(){
            Node* temp=head;
            while (temp!=nullptr)
            {
                cout<<temp->value<<" -> ";
                temp=temp->next;
            }

            cout<<"END"<<endl;
            
        }

        void insertAtLast(int val){
            if(tail==nullptr){
                insertAtFirst(val);
                return;
            }
            Node* node=new Node(val);
            tail->next=node;
            tail=node;

            size++;
        }

        void insert(int val,int index){
            if(index==0){
                insertAtFirst(val);
                return;
            }
            if(index==size){
                insertAtLast(val);
                return;
            }
            Node* temp=head;
            for(int i=1;i<index;i++){
                temp=temp->next;
            }
            Node* node=new Node(val,temp->next);
            temp->next=node;

            size++;

        }

        int deleteFirst(){
            int val=head->value;
            head=head->next;
            if (head==nullptr)
            {   
                tail=nullptr;
            }
            size--;
            return val;
        }

        Node* get(int index){
            Node* temp=head;
            for (int i = 0; i < index; i++)
            {
                temp=temp->next;
            }
            return temp;
            
        }

        int deleteLast(){
            if (size<=0)
            {
                return deleteFirst();
            }
            Node* secondLast=get(size-2);
            int val=tail->value;
            tail=secondLast;
            tail->next=nullptr;
            size--;
            return val;
        }

        int deleteItem(int index){
            if(index==0){
                return deleteFirst();
            }
            if(index==size-1){
                return deleteLast();
            }
            Node* prev=get(index-1);
            int val=prev->next->value;
            prev->next=prev->next->next;
            size--;
            return val;
        }

        Node* find(int val){
            Node* node=head;
            while(node!=nullptr){
                if (node->value==val)
                {
                    return node;
                }
                node=node->next;  
            }
            return node;
        }
};