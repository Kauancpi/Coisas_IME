#include <iostream>

using namespace std;

class classe_base {
    int valor;
    bool foi_atualizado;
    classe_base *prox;

public:
    classe_base() : valor(0), prox(NULL), foi_atualizado(false) {}

    // Copy constructor to perform deep copy
    classe_base(const classe_base &help) : valor(help.valor), foi_atualizado(help.foi_atualizado), prox(NULL) {
        if (help.prox != NULL) {
            prox = new classe_base(*help.prox);
        }
    }

    classe_base* adicionar_valor(int valor) {
        classe_base* auxiliar = this;

        if (!foi_atualizado) {
            this->valor = valor;
            foi_atualizado = true;
            this->prox = new classe_base;
        } else {
            while (auxiliar->prox != NULL && auxiliar->prox->foi_atualizado) {
                auxiliar = auxiliar->prox;
            }
            auxiliar->prox = new classe_base;
            auxiliar->prox->valor = valor;
            auxiliar->prox->foi_atualizado = true;
        }

        return this;
    }

    void imprimir() {
        classe_base* auxiliar = this;

        while (auxiliar != NULL && auxiliar->foi_atualizado) {
            cout << auxiliar->valor << endl;
            auxiliar = auxiliar->prox;
        }
    }

    ~classe_base() {
        delete prox;
    }
};

int main() {
    classe_base obj;
    obj.adicionar_valor(1);
    obj.adicionar_valor(2);
    obj.adicionar_valor(3);
    obj.imprimir();

    classe_base obj2=obj;

    obj2.adicionar_valor(4);

    obj2.imprimir();
    obj.imprimir();
}
