#include "CAction.h"



double CAction::CalculDeterminantVandermonde(const CMatrice<double>& MATparam) {
    
    unsigned int nbligne = MATparam.MATAvoirNbLignes();
    unsigned int nbcolonne = MATparam.MATAvoirNbColonnes();
    
    if (nbcolonne != nbligne) 
	{
		throw CException( EXC_ErreurMatriceNonCarree );//"matrice n´est pas caréé"
	}
    

    
    double detVandermonde  = 1;

    
    double** elements = MATparam.MATAvoirElement();
    for (unsigned int i = 0; i < nbligne - 1; i++) {
        
    for (unsigned int j = i + 1; j < nbcolonne; j++) {
        
        detVandermonde *= (elements[j][1] - elements[i][1]);
    }
}

    return detVandermonde;
}