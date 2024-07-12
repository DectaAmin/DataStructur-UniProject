#ifndef Sparce
#define Sparce

#include <iostream>
using namespace std;

class Node{
public :
    long col, row;
    double valu;
    Node* next;
};

void sort(Node* p) {
    long num = p->valu;
    for (long i = 0; i < num; ++i) {
        Node* q = p->next;
        while (q != nullptr && q->next != nullptr) {
            if (q->row > q->next->row || (q->row == q->next->row && q->col > q->next->col)) {
                Node* help = p;
                while (help->next != q) {
                    help = help->next;
                }
                help->next = q->next;
                Node* yu = q->next;
                q->next = q->next->next;
                yu->next = q;
            }
            q = q->next;
        }
    }
}

Node* getNode(long row, long col, long num){
    Node *first;
    first = new struct Node;
    first->col = col, first->row = row, first->valu = num, first->next = nullptr;
    return first;
}

bool NodeT(Node*p, Node* q);
double check(Node *p, Node *q){
    double index = 0;
    if(NodeT(p, q)){
        Node *l, *m;
        l = p, m = q;
        for(l = l->next ; l != nullptr; l = l->next){
            for( ; m != nullptr; m = m->next){
                if(m->col == l->col && m->row == l->row){
                    index++;
                }
            }
            m = q;
            m = m->next;
        }
    }

    double FV = (p->valu - index) + (q->valu - index) + index;
    return FV;
}

double FullN(Node *p) {
    Node *q = p;
    double index = 0;
    if(!q->next){
        return 1;
    }
    while (q->next) {
        index++;
        q = q->next;
    }
    return ++index;
}

void addNode(Node* head, long row, long col, double valu){
    if(FullN(head) <= head->valu){
        Node* pre;
        pre = getNode(row, col, valu);
        Node *ser = head;
        if(!ser->next){
            ser->next = pre;

            return ;
        }else{
            ser = ser->next;
        }
        while(ser){
            if(ser->col == pre->col && pre->row == ser->row){
                delete(pre);

                return ;
            }
            ser = ser->next;
        }
        delete(ser);
        Node *qre;
        qre = head;
        while(qre-> next){
            qre = qre->next;
        }
        qre->next = pre;
    }
    sort(head);
    return;
}

bool NodeT(Node*p, Node* q){
    if(p->row == q->row){
        if(p->col == q->col){
            return true;
        }
        return false;
    }

    return false;
}

bool exist(Node* p, Node* q){
    Node *r = q->next;
    while(r){
        if(p->row == r->row && p->col == r->col && p->valu == r->valu){
            return true;
        }
        r = r->next;
    }

    return false;
}

void print(Node *head){
    sort(head);
    Node *pre = head;
    while(pre){
        cout << pre->row << "\t" << pre->col << "\t" << pre->valu << "\n";
        pre = pre->next;
    }
    return ;
}


void deleteZero(Node* p){
    Node* qb = p->next, *qf, *del;
    while(qb){
        if(qb->valu == 0){
            qf = p;
            while(qf->next != qb){
                qf = qf->next;
            }
            del = qb;
            qf->next = qb->next;
            delete del;
        }
        qb = qb->next;
    }
}

Node *add(Node *first, Node *secend){
    if(NodeT(first, secend)){
        Node* Full = getNode(first->row, first->col, check(first, secend));
        Node *p, *q;

        p = first->next, q = secend->next;
        while(p){
            while(q){
                if(p->row == q->row){
                    if(p->col == q->col){
                        addNode(Full, p->row, p->col, p->valu + q->valu);
                    }
                }
                q = q->next;
            }
            q = secend->next;
            p = p->next;
        }

        p = first->next, q = secend->next;
        while(p){
            while(q){
                if(!exist(p, Full)){
                    addNode(Full, p->row, p->col, p->valu);
                }if(!exist(q, Full)){
                    addNode(Full, q->row, q->col, (q->valu));
                }
                q = q->next;
            }
            q = secend->next;
            p = p->next;
        }
        sort(Full);
        deleteZero(Full);
        double num = FullN(Full);
        Full->valu = --num;

        return Full;
    }
    return nullptr;
}


Node *Notadd(Node *first, Node *secend){
    if(NodeT(first, secend)){
        Node* Full = getNode(first->row, first->col, check(first, secend));
        Node *p, *q;

        p = first->next, q = secend->next;
        while(p){
            while(q){
                if(p->row == q->row){
                    if(p->col == q->col){
                        addNode(Full, p->row, p->col, p->valu - q->valu);
                    }
                }
                q = q->next;
            }
            q = secend->next;
            p = p->next;
        }

        p = first->next, q = secend->next;
        while(p){
            while(q){
                if(!exist(p, Full)){
                    addNode(Full, p->row, p->col, p->valu);
                }if(!exist(q, Full)){
                    addNode(Full, q->row, q->col, -1 * (q->valu));
                }
                q = q->next;
            }
            q = secend->next;
            p = p->next;
        }
        sort(Full);
        deleteZero(Full);
        double num = FullN(Full);
        Full->valu = --num;

        return Full;
    }
    return nullptr;
}

Node* T(Node *head){
    Node* pre = head->next;
    Node* q = getNode(head->col, head->row, head->valu);
    while(pre){
        addNode(q, pre->col, pre->row, pre->valu);
        pre = pre->next;
    }

    return q;
}

double checkZero(Node* p){
    Node* q = p->next;
    double index = 0, fullR = 0, fullC = 0;
    for(int i = 0; i < p->row; i++){
        for(int j = 0; j < p->col, q = q->next; j++){
            if(q->row == i && q->col == j){
                if(q->valu != 0){
                    index++;
                }
                
            }
            if(index != 0){
                fullR++;
            }
            index = 0;
        }
        q = p->next;
    }

    for(int j = 0; j < p->col; j++){
        for(int i = 0; i < p->row, q = q->next; i++){
            if(q->col == i && q->row == j){
                if(q->valu != 0){
                    index++;
                }
            }
            if(index != 0){
                fullC++;
            }
            index = 0;
        }
        q = p->next;
    }

    return fullR + fullC;

}

Node* mult(Node* p, Node* q) {
    if (p->col == q->row) {
        Node* full = getNode(p->row, q->col, p->row * q->col);
        for (long i = 0; i < p->row; i++) {
            for (long j = 0; j < q->col; j++) {
                double sum = 0;
                for (Node* preP = p->next; preP != nullptr; preP = preP->next) {
                    for (Node* preQ = q->next; preQ != nullptr; preQ = preQ->next) {
                        if (preP->row == i && preP->col == preQ->row && preQ->col == j) {
                            sum += (preQ->valu * preP->valu);
                        }
                    }
                }
                // cout << sum << endl;
                if(sum != 0){
                    addNode(full, i, j, sum);
                    sum = 0;
                }
            }
        }
        double num = FullN(full);
        full->valu = --num;
        return full;
    }
    return nullptr;
}
#endif