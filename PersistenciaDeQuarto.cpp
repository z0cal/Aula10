#include "PersistenciaDeQuarto.h"
// inclua o que for necessario

// Implemente
PersistenciaDeQuarto::PersistenciaDeQuarto(string arquivo) :arquivo(arquivo) {

}

PersistenciaDeQuarto::~PersistenciaDeQuarto() {
}

// Implemente
void PersistenciaDeQuarto::inserir(Quarto *q) {
    ofstream file(arquivo,ios::app);
    if(file.is_open()){
        file<<q->getNumero()<<endl<<q->getNumeroDeCamas()<<endl;
        file.close();
    }
    
}


// Implemente
Quarto **PersistenciaDeQuarto::obter(int &quantidade) {
    ifstream entrada;
    entrada.open(arquivo);
    if(entrada.fail()){
        throw invalid_argument("Erro de leitura");
        entrada.close();

    }
    int quantidade2=0;
    
    int numero,numeroDeCamas;
    
    
    while(entrada>>numero>>numeroDeCamas){
        if(entrada.fail()){
            throw logic_error("Arquivo com formatacao inesperado");
        }
        quantidade2++;
    

    }
    




    if(quantidade2==0){
        quantidade=0;
        return nullptr;
    }
    entrada.clear();
     entrada.seekg(0, ios::beg);
    quantidade=quantidade2;
    int i=0;
    Quarto** vetorQuartos = new Quarto*[quantidade];

    entrada.seekg(0, ios::beg);

      while (entrada >> numero >> numeroDeCamas) {
        vetorQuartos[i] = new Quarto(numero, numeroDeCamas);
        i++;
    }

    entrada.close();


    


    return vetorQuartos;
}
