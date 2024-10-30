#if !defined(PERSISTENCIA_DE_QUARTO_H)
#define PERSISTENCIA_DE_QUARTO_H

#include "Quarto.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class PersistenciaDeQuarto {
  // Faca as alteracoes necessarias
private:
string arquivo;
public:
  PersistenciaDeQuarto(string arquivo);
  virtual ~PersistenciaDeQuarto();
  void inserir(Quarto *q);
  Quarto **obter(int &quantidade);
};

#endif // PERSISTENCIA_DE_QUARTO_H
