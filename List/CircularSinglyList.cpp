// 单项循环链表
// Created by Jack King on 9/4/16.
//

//todo: Circular Singly List

template<typename ElemType>
struct CircularSinglyList{
    struct Node{
        ElemType elem;
        Node *next;
    };

    Node *head;

    CircularSinglyList(){
        this->head=new Node();
        this->head->next=this->head;
    }

    ~CircularSinglyList() {
        // free every node from head
        }
    }


};