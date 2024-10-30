#pragma once
#ifndef CMATRICE_H
#define CMATRICE_H

#include <iostream>
#include "CException.h"
//� partir de 10
#define EXC_ErreurHorsLimite 11
#define EXC_DivisionParZero 12
#define EXC_TaillesMatricesNonIdentiques 13
#define EXC_ErreurConditionTaillePourMultiplication 14
#define EXC_DimensionInvalide 15
#define EXC_AllocationMemoireEchouee 16


template <class MType>class CMatrice
{
private:
	unsigned int uiMATNbligne;
	unsigned int uiMATNbcolonne;
	MType** pMATElement;

public:

/******************************************************************************************************
***** CMatrice : constructeur par d�fault permet de cr�er ine instanciation de la classe CMatrice *****
***** Entr�e : n�ant	*****
***** N�cessite : n�ant *****
***** Sortie : n�ant	*****
***** Entra�ne : Les membres de la classes sont initialis�es  *****
******************************************************************************************************/
	CMatrice<MType>();



/***********************************************************************************************************************************************
***** CMatrice : constructeur de recopie  de la classe CMatrice permet de copier la matrice MATarg en une nouvelle instance CMatrice<MType>*****
***** Entr�e : constante r�f�rent vers une CMatrice<MType>*****
***** N�cessite : n�ant	*****
***** Sortie : n�ant *****
***** Entra�ne : La copie de la matrice MATarg est faite *****
***********************************************************************************************************************************************/
	CMatrice<MType>(const CMatrice<MType>& MATarg);



/******************************************************************************************************
***** CMatrice : constructeur de confort de la classe CMatrice permet de cr�e une nouvelle matrice*****
***** Entr�e : nombre de lignes et colonnes	*****
***** N�cessite : n�ant *****
***** Sortie : n�ant	*****
***** Entra�ne : Creation d'une matrice avec les attribues donn�es *****
******************************************************************************************************/
	CMatrice<MType>(unsigned int lignes, unsigned  int colonnes);
	


/*******************************************************************************************
***** ~CMatrice : destructeur  de la classe CMatrice permet de d�truire l�objet allou� *****
***** Entr�e : n�ant	*****
***** N�cessite : La matrice doit �tre initialis�e *****
***** Sortie : n�ant	*****
***** Entra�ne : L'objet est d�truit*****
*******************************************************************************************/
	~CMatrice();



/*************************************************************************
***** MATAvoirNbLignes : retourne le nombre de lignes de la matrice *****
***** Entr�e : n�ant	*****
***** N�cessite : n�ant *****
***** Sortie : entier qui represente le nombre de ligne de la matrice*****
***** Entra�ne : Le nombre de ligne est retourn�  *****
*************************************************************************/
	unsigned int MATAvoirNbLignes() const;
	
/****************************************************************************
***** MATAvoirNbColonnes : retourne le nombre de colonnes de la matrice *****
***** Entr�e : n�ant	*****
***** N�cessite : n�ant *****
***** Sortie : entier represente le nombre de colonne de la matrice	*****
***** Entra�ne : Le nombre de colonne est retourn�  *****
****************************************************************************/
	unsigned int MATAvoirNbColonnes() const;
	


/**************************************************************************************************************************************************************
***** MATModifierElement : modifier l'�l�ment de la matrice situ� � une position (i ,j) pr�cis *****
***** Entr�e : deux entiers i,j representent l'indice de la ligne (colonne respectivement) ,et une valeur � affecter � l'�l�ment situ� � la position(i,j) *****
***** N�cessite : o =< i <= uiMATNbligne-1 ; 0 =< j <= uiMATNbcolonne-1 *****
***** Sortie : n�ant	*****
***** Entra�ne : L'�l�ment de la marice est modifi�  *****
***************************************************************************************************************************************************************/
	void MATModifierElement(unsigned int i, unsigned int j, MType valeur);
	

	
/********************************************************************************************************
***** MATObtenirElement: Cette fonction permet d�obtenir la valeur de l'�l�ment � une position(i,j) *****
***** Entr�e : Les indices i,j pour acc�der � l'�l�ment	*****
***** N�cessite : n�ant *****
***** Sortie : La valeur de l��l�ment de position(i,j)	*****
***** Entra�ne : La valeur de l��l�ment de la position (i,j) est obtenu  *****
********************************************************************************************************/
	MType MATObtenirElement(unsigned int i, unsigned int j) const;



/************************************************************************************************************
***** operator* : surcharge de l'op�rateur * *****
***** Entr�e : un nombre r�el c de type double	*****
***** N�cessite : n�ant *****
***** Sortie : nouvelle matrice r�sultant de la multiplication de la matrice en cour par le scalaire c	*****
***** Entra�ne : la matrice r�sultant est retourn�e  *****
************************************************************************************************************/
	CMatrice<MType> operator*(const double c) const;
	


/********************************************************************************************************
***** operator/ : surcharge de l�operateur / *****
***** Entr�e : la constante c de type double � diviser	*****
***** N�cessite : const c doit �tre diff�rent de z�ro *****
***** Sortie : nouvelle matrice r�sultant de la division de la matrice en cours par la constant c	*****
***** Entra�ne : la matrice r�sultant est retourn�e  *****
********************************************************************************************************/
	CMatrice<MType> operator/(const double c) const;
	


/**********************************************************************************
***** MATAfficherMatrice: cette fonction fait l�affichage de la matrice voulu *****
***** Entr�e : n�ant	*****
***** N�cessite : n�ant *****
***** Sortie : affiche la matrice  sur le console	*****
***** Entra�ne : La matrice est affich�e *****
**********************************************************************************/
	void MATAfficherMatrice() const;
	


/************************************************************************************************
***** operator+ : surcharge de l'op�rateur + *****
***** Entr�e : r�f�rent vers une CMatrice<MType>	*****
***** N�cessite : les deux matrices doivent avoir les m�me tailles *****
***** Sortie : nouvelle matrice r�sultant de l'addition de la matrice en cours avec MATarg	*****
***** Entra�ne : la matrice r�sultant est retourn�e *****
************************************************************************************************/
	CMatrice<MType> operator+(const CMatrice& MATarg) const;
	


/****************************************************************************************************
***** operator- : surcharge de l'op�rateur - *****
***** Entr�e : r�f�rent vers une CMatrice<MType>	*****
***** N�cessite : les deux matrices doivent avoir les m�me tailles *****
***** Sortie : nouvelle matrice r�sultant de la soustraction de la matrice en cours avec MATarg	*****
***** Entra�ne : la matrice r�sultant est retourn�e *****
****************************************************************************************************/
	CMatrice<MType> operator-(const CMatrice& MATarg) const;
	

	
/****************************************************************************************************************
***** operator- : surcharge de l'op�rateur * *****
***** Entr�e : r�f�rent vers une CMatrice<MType>	*****
***** N�cessite : le nombre de colonne de la matrice appelante doit �tre �gal au nombre de lignes de MATarg *****
***** Sortie : nouvelle matrice r�sultant de la multiplication de la matrice appelante avec MATarg	*****
***** Entra�ne : la matrice r�sultant est retourn�e *****
****************************************************************************************************************/
	CMatrice<MType> operator*(const CMatrice& MATarg) const;
	


/************************************************************************************
***** operator= : Surcharge de l'op�rateur = *****
***** Entr�e : r�f�rent vers une CMatrice<MType>	*****
***** N�cessite : n�ant *****
***** Sortie : CMatrice<MType>	*****
***** Entra�ne : Affecte l'objet CMatrice pass� en param�tre � l'objet en cours *****
************************************************************************************/
	CMatrice<MType>& operator=(const CMatrice<MType>& MATarg);
	


/**************************************************************************************
***** MATTranspose:  cette fonction permet de faire la transpos� le matrice voulu *****
***** Entr�e : n�ant	*****
***** N�cessite : n�ant *****
***** Sortie : CMatrice<MType>	*****
***** Entra�ne : la transpos� de la matrice voulu est retourn�   *****
**************************************************************************************/
	CMatrice <MType> MATTranspose() const;

	  MType **  MATAvoirElement() const ;

};

/*************************************************************************************************
***** operator* : surcharge de l'op�rateur * ******
***** Entr�e : un nombre r�el c de type double et une matrice MATarg de type CMatrice<MType> *****
***** N�cessite : n�ant *****
***** Sortie : nouvelle matrice r�sultant de la multiplication de (c * MATarg)	*****
***** Entra�ne : la matrice r�sultant est retourn�e  *****
*************************************************************************************************/
template <class MType> CMatrice<MType> operator*(const double c, const CMatrice<MType>& MATarg) 
{
	return MATarg * c;
};


template <class MType> CMatrice<MType>::CMatrice()
{
	uiMATNbcolonne = 0;
	uiMATNbligne = 0;
	pMATElement = nullptr;
}

template <class MType> CMatrice<MType>::CMatrice(const CMatrice<MType>& MATarg)
{
	if (MATarg.uiMATNbcolonne == 0 || MATarg.uiMATNbligne == 0)
	{
		throw CException(EXC_DimensionInvalide); //lever une exception 
	}
	else
	{
		uiMATNbcolonne = MATarg.uiMATNbcolonne;
		uiMATNbligne = MATarg.uiMATNbligne;

		pMATElement = new MType*[MATarg.uiMATNbligne];
		for (unsigned int i = 0; i < MATarg.uiMATNbligne; ++i)
		{
			pMATElement[i] = new MType[MATarg.uiMATNbcolonne];
			for (unsigned int j = 0; j < MATarg.uiMATNbcolonne; ++j)
			{
				pMATElement[i][j] = MATarg.pMATElement[i][j];
			}
		}
	}
}

template <class MType> CMatrice<MType>::CMatrice(unsigned int lignes, unsigned  int colonnes) 
{
	if (lignes == 0 || colonnes == 0)
	{
		throw CException(EXC_DimensionInvalide); //lever une exception 
	}

	uiMATNbligne = lignes;
	uiMATNbcolonne = colonnes;
	pMATElement = NULL;


	if(uiMATNbligne > 0 && uiMATNbcolonne > 0)
	{

		pMATElement = new MType*[uiMATNbligne];
		if (pMATElement == nullptr) 
		{
			throw CException(EXC_AllocationMemoireEchouee);
		}
		for (unsigned int i = 0; i < uiMATNbligne; ++i)
		{
			pMATElement[i] = new MType[uiMATNbcolonne];
			for (unsigned int j = 0; j < uiMATNbcolonne; ++j)
				pMATElement[i][j] = 0;
		}
	}
}

template <class MType> CMatrice<MType>::~CMatrice()
{
	if (pMATElement != nullptr)
	{
		for (unsigned int i = 0; i < uiMATNbligne; ++i)
			delete[]pMATElement[i];
	}
	delete[]pMATElement;
}


template <class MType> unsigned int CMatrice<MType>::MATAvoirNbLignes() const {
	return uiMATNbligne;
}

template <class MType> unsigned int CMatrice<MType>::MATAvoirNbColonnes() const {
	return uiMATNbcolonne;
}

template <class MType> void CMatrice<MType>::MATModifierElement(unsigned int i, unsigned int j, MType valeur){
	if (i < uiMATNbligne && j < uiMATNbcolonne) {
		pMATElement[i][j] = valeur;
	}
	else
	{
		throw CException(EXC_ErreurHorsLimite);//exception horslimite
	}
		
}

template <class MType> MType CMatrice<MType>::MATObtenirElement(unsigned int i, unsigned int j) const {
	if (i > uiMATNbligne || j > uiMATNbcolonne) {
		throw CException(EXC_ErreurHorsLimite);//exception horslimite
	}
	return pMATElement[i-1][j-1];
}

template <class MType>  CMatrice<MType> CMatrice<MType>::operator*(const double c) const
{
	if (c == 0)
	{
		CMatrice<MType> MATResult(uiMATNbligne, uiMATNbcolonne);
		return MATResult;
	}
	else
	{
		CMatrice<MType> MATResult(uiMATNbligne, uiMATNbcolonne);
		for (unsigned int i = 0; i < uiMATNbligne; ++i)
		{
			for (unsigned int j = 0; j < uiMATNbcolonne; ++j)
			{
				*(*(MATResult.pMATElement + i) + j) = *(*(pMATElement + i) + j) * c;
			}
		}
	

		return MATResult;
	}
	
}


template <class MType>  CMatrice<MType> CMatrice<MType>::operator/(const double c)  const
{
	CMatrice<MType> MATResult(uiMATNbligne, uiMATNbcolonne);
	if (c == 0)
	{
		throw CException(EXC_DivisionParZero);//lever une exception
	}
	else
	{
		for (unsigned int i = 0; i < uiMATNbligne; ++i)
		{
			for (unsigned int j = 0; j < uiMATNbcolonne; ++j)
			{
				*(*(MATResult.pMATElement + i) + j) = *(*(pMATElement + i) + j) / c;
			}
		}
	}

	return MATResult;

}


template <class MType> void CMatrice<MType>::MATAfficherMatrice() const
{
	for (unsigned int i = 0; i < uiMATNbligne; ++i)
	{
		for (unsigned int j = 0; j < uiMATNbcolonne; ++j)
		{
			std::cout << pMATElement[i][j] << " ";
		}
		std::cout << std::endl;
	}
}


//2Partie
template <class MType> CMatrice<MType> CMatrice<MType>::operator+(const CMatrice& MATarg) const 
{
	// V�rifier si les matrices ont la m�me taille
	if (uiMATNbligne != MATarg.uiMATNbligne || uiMATNbcolonne != MATarg.uiMATNbcolonne) 
	{
		throw CException(EXC_TaillesMatricesNonIdentiques);// "Les matrices doivent avoir la m�me taille")
	}
	// Cr�er une nouvelle matrice pour stocker le r�sultat
	CMatrice MATResult(uiMATNbligne, uiMATNbcolonne);

	// Ajouter chaque �l�ment des deux matrices et stocker le r�sultat dans la nouvelle matrice
	for (unsigned int i = 0; i < uiMATNbligne; ++i) {
		for (unsigned int j = 0; j < uiMATNbcolonne; ++j) {
			MATResult.pMATElement[i][j] = pMATElement[i][j] + MATarg.pMATElement[i][j];
		}
	}
	return MATResult;
}


template <class MType> CMatrice<MType> CMatrice<MType>::operator-(const CMatrice& MATarg) const
{
	// V�rifier si les matrices ont la m�me taille
	if (uiMATNbligne != MATarg.uiMATNbligne || uiMATNbcolonne != MATarg.uiMATNbcolonne) 
	{
		throw CException(EXC_TaillesMatricesNonIdentiques);// "Les matrices doivent avoir la m�me taille"
	}
	// Cr�er une nouvelle matrice pour stocker le r�sultat
	CMatrice MATResult(uiMATNbligne, uiMATNbcolonne);

	// Ajouter chaque �l�ment des deux matrices et stocker le r�sultat dans la nouvelle matrice
	for (unsigned int i = 0; i < uiMATNbligne; ++i) {
		for (unsigned int j = 0; j < uiMATNbcolonne; ++j) {
			MATResult.pMATElement[i][j] = pMATElement[i][j] - MATarg.pMATElement[i][j];
		}
	}
	return MATResult;
}


template <class MType> CMatrice<MType> CMatrice<MType>::operator*(const CMatrice& MATarg) const
{
	if (uiMATNbcolonne != MATarg.uiMATNbligne) 
	{
		throw CException(EXC_ErreurConditionTaillePourMultiplication);//"Dimensions incompatibles pour le produit de matrices"
	}

	// Cr�er une nouvelle matrice pour stocker le r�sultat
	CMatrice MATResult(uiMATNbligne, MATarg.uiMATNbcolonne);

	// Effectuer le produit matriciel
	for (unsigned int i = 0; i < uiMATNbligne; i++) {
		for (unsigned int j = 0; j < MATarg.uiMATNbcolonne; j++) {
			double somme = 0.0;
			for (unsigned int k = 0; k < uiMATNbcolonne; k++) {
				somme += pMATElement[i][k] * MATarg.pMATElement[k][j];
			}
			MATResult.pMATElement[i][j] = somme;
		}
	}
	return MATResult;
}


template <class MType> CMatrice<MType>& CMatrice<MType>::operator=(const CMatrice<MType>& MATarg)
{
	// Lib�rer la m�moire allou�e pour les anciens �l�ments de la matrice
	for (unsigned int i = 0; i < uiMATNbligne; ++i)
	{
		delete[] pMATElement[i];
	}
	delete[] pMATElement;

	// Allouer de la m�moire pour les nouveaux �l�ments de la matrice
	uiMATNbligne = MATarg.uiMATNbligne;
	uiMATNbcolonne = MATarg.uiMATNbcolonne;
	pMATElement = new MType * [uiMATNbligne];
	for (unsigned int i = 0; i < uiMATNbligne; ++i)
	{
		pMATElement[i] = new MType[uiMATNbcolonne];
		for (unsigned int j = 0; j < uiMATNbcolonne; ++j)
		{
			pMATElement[i][j] = MATarg.pMATElement[i][j];
		}
	}
	return *this;
}


template <class MType> CMatrice<MType> CMatrice<MType>::MATTranspose() const {
	CMatrice MATResult(uiMATNbcolonne, uiMATNbligne);
	for (unsigned int i = 0; i < uiMATNbcolonne; i++) {
		for (unsigned int j = 0; j < uiMATNbligne; j++) {
			MATResult.pMATElement[i][j] = pMATElement[j][i];
		}
	}
	return MATResult;
}

template<class MType> MType **CMatrice<MType>::MATAvoirElement() const {
         return pMATElement;
    }


#endif