// matrices.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "CMatrice.h"
#include "CParser.h"

int main(int argc, char* argv[])
{
    if (argc < 2) { return 1;}

    const int iNbMatrices = argc - 1;
    CMatrice<double>** matrices = new CMatrice<double>*[iNbMatrices];

    // Lecture et creation de matrices
    for (int i = 0; i < iNbMatrices; ++i)
    {
        try {
            matrices[i] = new CMatrice<double>(CParser::PARLireMatrice(argv[i + 1]));
            std::cout << "matrice" << i+1 << std::endl;
            matrices[i]->MATAfficherMatrice();
            std::cout << std::endl;
        }
        catch (CException& exc)
        {
            switch (exc.EXCLireErreur())
            {
            case EXC_ErreurOuvertureFichier:
                std::cerr << "Erreur: Impossible d'ouvrir le fichier " << argv[i + 1] << std::endl;
                break;
            case EXC_BaliseIntrouvable:
                std::cerr << "Erreur : balise  introuvable dans le fichier " << argv[i + 1] << std::endl;
                break;
            case EXC_TypeMatriceNonDouble:
                std::cerr << "Erreur: Type de la matrice (non double) non pris en charge du fichier " << argv[i + 1] << std::endl;
                break;
            case EXC_DimensionInvalide:
                std::cerr << "Erreur: Dimension invalide de la matrice dans le fichier " << argv[i + 1] << std::endl;
                break;
            default:
                std::cerr << "ERROR" << std::endl;
            }
            return 1;

        }

    }
    
    double c;
    std::cout << "Entrez une valeur pour c: ";
    std::cin >> c;

    
    for (int i = 0; i < iNbMatrices; ++i)
    {
        try
        { 
            std::cout << "Resultat de la multiplication de la matrice " << i + 1 << " par " << c << " : " << std::endl;
            matrices[i]->operator*(c).MATAfficherMatrice();

        }

        catch (CException& exc)
        {
            switch (exc.EXCLireErreur())
            {
            case EXC_AllocationMemoireEchouee:
                std::cerr << "Erreur: Allocation de memoire a echoue pour le produit de la matrice " << i + 1 << std::endl;
                break;
            default:
                std::cerr << "ERROR" << std::endl;
            }
            return 1;
        }
    }

    
    for (int i = 0; i < iNbMatrices; ++i)
    {
        try
        {
            std::cout << "Resultat de la division de la matrice " << i + 1 << " par " << c << " : " << std::endl;
            matrices[i]->operator/(c).MATAfficherMatrice();
        }
        catch (CException& exc)
        {
            switch (exc.EXCLireErreur())
            {
            case EXC_DivisionParZero:
                std::cerr << "Erreur: Division par zero pour la matrice " << i + 1 << std::endl;
                break;
            case EXC_AllocationMemoireEchouee:
                std::cerr << "Erreur: Allocation de memoire a echoue pour le produit de la matrice " << i + 1 << std::endl;
                break;
            default:
                std::cerr << "ERROR" << std::endl;
            }
            return 1;
        }
    }

    
    try
    {
        std::cout << "Resultat de l'addition de toutes les matrices " << std::endl;
        CMatrice<double> somme(*matrices[0]);
        
        for (int i = 1; i < iNbMatrices; ++i)
        {
           
            CMatrice<double> temporaire = (somme + *matrices[i]);
            
            somme = temporaire;
            
        }
        
        somme.MATAfficherMatrice();
    }
    catch (CException& exc)
    {
        switch (exc.EXCLireErreur())
        {
        case EXC_TaillesMatricesNonIdentiques:
            std::cerr << "Exception : Tailles des matrices non identiques." << std::endl;
            break;
        case EXC_AllocationMemoireEchouee:
            std::cerr << "Exception : Allocation memoire echouee" << std::endl;
            break;
        case EXC_ErreurHorsLimite:
            std::cerr << "Exception : Erreur hors limite" << std::endl;
            break;
        default:
            std::cerr << "ERROR" << std::endl;
        }
        return 1;
    }

    
    try
    {
        std::cout << "Resultat de l'operation: M1 - M2 + M3 - M4 + M5 - M6 + ... " << std::endl;
        CMatrice<double> additionetsoustraction(*matrices[0]);
        for (int i = 1; i < iNbMatrices; ++i)
        {
            if (i % 2 == 0) 
            {
                CMatrice<double> temporaire = (additionetsoustraction + *matrices[i]);

                additionetsoustraction = temporaire;
            }
            else
            {
                CMatrice<double> temporaire = (additionetsoustraction - *matrices[i]);

                additionetsoustraction = temporaire;
            }
        }
        additionetsoustraction.MATAfficherMatrice();
    }
    catch (CException& exc)
    {
        switch (exc.EXCLireErreur())
        {
        case EXC_TaillesMatricesNonIdentiques:
            std::cerr << "Exception : Tailles des matrices non identiques." << std::endl;
            break;
        case EXC_AllocationMemoireEchouee:
            std::cerr << "Exception : Allocation memoire echouee" << std::endl;
            break;
        case EXC_ErreurHorsLimite:
            std::cerr << "Exception : Erreur hors limite" << std::endl;
            break;
        default:
            std::cerr << "ERROR" << std::endl;
        }
        return 1;
    }

    
    try
    {
        std::cout << "Resultat du produit des matrices " << std::endl;
        CMatrice<double> produit(*matrices[0]);
        for (int i = 1; i < iNbMatrices; ++i)
        {
            produit = produit.operator*(*matrices[i]);

        }
        produit.MATAfficherMatrice();
    }
    catch (CException& exc)
    {
        switch (exc.EXCLireErreur())
        {

        case EXC_AllocationMemoireEchouee:
            std::cerr << "Exception : Echec d'allocation de memoire." << std::endl;
            break;
        case EXC_TaillesMatricesNonIdentiques:
            std::cerr << "Exception : Tailles des matrices non identiques." << std::endl;
            break;
        case EXC_ErreurConditionTaillePourMultiplication:
            std::cerr << "Exception : Erreur de condition de taille pour la multiplication." << std::endl;
            break;
        case EXC_ErreurHorsLimite:
            std::cerr << "Exception : Erreur hors limite" << std::endl;
            break;
        default:
            std::cerr << "ERROR" << std::endl;
        }
        return 1;
    }
  
   return 0;
}
