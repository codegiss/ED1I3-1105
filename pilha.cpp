#include <iostream>
using namespace std;

#define MAX 30

// pilha par array
struct Par {
    int num;
    float elementos[MAX];
};

Par* init() {
    Par *p = new Par();
    p->num=0;
    return p;
}

int isEmpty(Par *p) {
    return (p->num==0);
}

int count(Par *p) {
    return (p->num);
}

void freePilha(Par *p) {
    free(p);
}

int push(Par *p, float v) {
    int podeEmpilhar = (p->num < MAX);
    if(podeEmpilhar) {
        p->elementos[p->num++] = v;
    }
    return podeEmpilhar;
}

float pop(Par *p) {
    float v;
    int podeDesempilhar = !(isEmpty(p));
    if(podeDesempilhar) {
        v = p->elementos[p->num-1];
        p->num--;
    } else {
        v=-1;
    }
    return v;
}

// pilha impar ponteiro

int main () {
    int cont=0, numero, anterior;

    Par *par;
    par = new Par();
    par = init();

    for(cont=1; cont<=30; cont++) {
        if(cont == 1) {
            cout << "Digite o 1o. numero inteiro: ";
            cin >> numero;
        } else {
            anterior = numero;

            do {
                cout << "Digite o " << cont << "o. numero inteiro: ";
                cin >> numero;
            } while (numero <= anterior);
        }
        
        if(numero%2 == 0) {
            push(par, numero);
        } else {
            // gravar na pilha impar
        }
    }

    // mostrar os valores em sequencia decrescente
    // independente da pilha

    return 0;
}