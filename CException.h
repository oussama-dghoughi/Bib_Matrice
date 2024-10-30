#pragma once
#ifndef CEXCEPTION_H
#define CEXCEPTION_H 
#define ERREUR 0


class CException
{

private:
	unsigned int uiEXCErreur;

public:

/*************************************************************************
 ***** CException : constructeur par d�fault de la classe CException *****
 *****Entr�e : n�ant*****
 *****N�cessite : n�ant *****
 *****Sortie : n�ant *****
 *****Entra�ne : L'exception initialiser � ERREUR *****
 ************************************************************************/
	CException();



/**********************************************************************************************************************
 ***** CException : constructeur de confort de la classe CException permet d'identifier le type d�erreur rencontr�*****
 *****Entr�e : un entier uiErreur represente le type d'erreur   *****
 *****N�cessite : n�ant *****
 *****Sortie : n�ant *****
 *****Entra�ne :  la cr�ation d'un objet CException initialis� avec uiErreur *****
 *********************************************************************************************************************/
	CException(unsigned int uiErreur);
	


/******************************************************************************************
 ***** ~CException : Destructeur  de la classe CException permet de d�truire  un objet*****
 *****Entr�e : n�ant *****
 *****N�cessite : n�ant *****
 *****Sortie : n�ant *****
 *****Entra�ne : la destruction d'un objet CException  *****
 *****************************************************************************************/
	~CException();



/*************************************************************************
 ***** EXCLireErreur : m�thode pour lire l'erreur associ�e � l'objet *****
 *****Entr�e :n�ant  *****
 *****N�cessite : n�ant *****
 *****Sortie : l'erreur associ�e � l'objet *****
 *****Entra�ne : L'exception est retourn�e *****
 ************************************************************************/
	unsigned int EXCLireErreur();



/*********************************************************************************
 ***** EXCModifierErreur :  m�thode pour modifier l'erreur associ�e � l'objet*****
 *****Entr�e :La nouvelle valeur de l'exception  *****
 *****N�cessite : n�ant *****
 *****Sortie : n�ant *****
 *****Entra�ne : la modification de l'erreur associ�e � l'objet *****
 ********************************************************************************/
	void EXCModifierErreur(unsigned int uiParam);

};
#endif