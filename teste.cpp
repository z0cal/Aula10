// Faca os includes necessarios
#include "PersistenciaDeQuarto.h"
using namespace std;

void teste1() {
  // implemente
    Quarto* quarto1 = new Quarto(1, 4);  // Quarto 1 com 4 camas
    Quarto* quarto2 = new Quarto(2, 2);  // Quarto 2 com 2 camas
    Quarto* quarto3 = new Quarto(3, 1);  // Quarto 3 com 1 cama

    PersistenciaDeQuarto persistencia("teste1.txt");

    
    persistencia.inserir(quarto1);
    persistencia.inserir(quarto2);
    persistencia.inserir(quarto3);

    delete quarto1;
    delete quarto2;
    delete quarto3;
}

void teste2() {
    try {
        // 1. Criação do objeto PersistenciaDeQuarto com o arquivo "teste2.txt"
        PersistenciaDeQuarto persistencia("teste2.txt");

        // 2. Carregar os objetos Quarto do arquivo usando obter
        int quantidade = 0;
        Quarto** quartos = persistencia.obter(quantidade);

        // 3. Verificar se o vetor de quartos não é nullptr e imprimir os dados
        if (quartos != nullptr) {
            for (int i = 0; i < quantidade; ++i) {
                quartos[i]->imprimir();  // Supõe que existe um método imprimir na classe Quarto
                delete quartos[i];       // Libera cada objeto Quarto individualmente
            }
            delete[] quartos;  // Libera o vetor de objetos Quarto
        }

    } catch (const exception& e) {
        // Captura e imprime a mensagem de exceção
        cout << e.what() << endl;
    }

    // O objeto PersistenciaDeQuarto será automaticamente destruído ao sair do escopo
}