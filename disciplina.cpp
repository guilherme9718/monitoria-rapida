#include "disciplina.h"

Disciplina::Disciplina()
{

}

Disciplina::Disciplina(int id, QString codigo, QString nome, QString dep) {
    this->disciplinaID = id;
    this->codigo = codigo;
    this->nome = nome;
    this->departamento = dep;
}

Disciplina::~Disciplina() {

}
