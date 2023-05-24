#include <iostream>
using namespace std;

#define MAX 30

// pilha par array
struct Par {
    int num;
    float elementos[MAX];
};

Par* initPar() {
    Par *p = new Par();
    p->num=0;
    return p;
}

int isEmptyPar(Par *p) {
    return (p->num==0);
}

int countPar(Par *p) {
    return (p->num);
}

void freePilhaPar(Par *p) {
    free(p);
}

int pushPar(Par *p, float v) {
    int podeEmpilhar = (p->num < MAX);
    if(podeEmpilhar) {
        p->elementos[p->num++] = v;
    }
    return podeEmpilhar;
}

float popPar(Par *p) {
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

struct Impar {
    float dado;
    struct Impar *prox;
};

struct Pilha {
    Impar *topo;
};

Pilha* initImpar {
    Pilha *p = new Pilha();
	  p->topo = NULL;
	  return p;
}

int isEmptyImpar(Pilha *p) {
	  return (p->topo == NULL);
}

int countImpar(Pilha *p) {
    int i = 0;
	  No *no = p->topo;
	  while (no != NULL) {
		    i++;
		    no = no->prox;
	  }
	  return i;
}

void printImpar(Pilha *p) {
	  No *no = p->topo;
	  cout << "--------------" << endl;
	  cout << "Qtde de elementos: " << count(p) << endl;
	  cout << "--------------" << endl;
	  while (no != NULL) {
		    cout << no->dado << endl;
		    no = no->prox;
	  }
    cout << "--------------" << endl;
}

void pushImpar(Pilha *p, float v) {
	  No *no = new No();
	  no->dado = v;
	  no->prox = p->topo;
	  p->topo = no;
}

float popImpar(Pilha *p) {
	  float ret;
	  int podeDesempilhar = (!isEmpty(p));
	  if (podeDesempilhar) {
	      No *no = p->topo;
		    ret = no->dado;
		    p->topo = p->topo->prox;
		free(no);
	  }
	  else {
		    ret = -1;
	  }
	  return ret;
}

void freePilhaImpar(Pilha *p) {
	  No *no = p->topo;
	  while (no != NULL) {
		    No *aux = no->prox;
		    free(no);
		    no = aux;
	}
	  free(p);
}

int main () {
    int cont=0, numero, anterior;

    Par *par;
    par = new Par();
    par = initPar();

    Pilha *impar;
    impar = initImpar();

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
            pushPar(par, numero);
        } else {
            // gravar na pilha impar
            pushImpar(impar, numero);
        }
    }

    // mostrar os valores em sequencia decrescente
    // independente da pilha

    freePilhaPar(par);
    freePilhaImpar(impar);

    return 0;
}