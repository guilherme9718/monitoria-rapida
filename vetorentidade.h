#ifndef VETORENTIDADE_H
#define VETORENTIDADE_H

#include "entidade.h"
#include <QVector>

class VetorEntidade
{
public:
    VetorEntidade();
    ~VetorEntidade();

    QVector<Entidade*> vetor;
};

#endif // VETORENTIDADE_H
