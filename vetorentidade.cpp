#include "vetorentidade.h"

VetorEntidade::VetorEntidade()
{

}

VetorEntidade::~VetorEntidade() {
    for(int i=0; i < vetor.size(); i++) {
        delete(vetor[i]);
    }
}
