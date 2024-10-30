#include "CMatrice.h"
#include "CException.h"
#define EXC_ErreurMatriceNonCarree 19

class CAction {
public:
    
    template <class MType>
     CMatrice<MType> OPMTransposee(const CMatrice<MType>& MATparam);
    static double CalculDeterminantVandermonde(const CMatrice<double>& MATparam);
};

template <class MType>
CMatrice<MType> CAction::OPMTransposee(const CMatrice<MType>& MATparam) {
    unsigned int nbligne = MATparam.MATAvoirNbLignes();
    unsigned int nbcolonne = MATparam.MATAvoirNbColonnes();

    CMatrice<MType> MATResult(nbcolonne, nbligne);
    MType** resElements = MATResult.MATAvoirElement();
    MType** paramElements = MATparam.MATAvoirElement();

    for (unsigned int i = 0; i < nbcolonne; i++) {
        for (unsigned int j = 0; j < nbligne; j++) {
            resElements[i][j] = paramElements[j][i];
        }
    }

    return MATResult;
}






