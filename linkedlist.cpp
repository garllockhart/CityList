/*
File Name		: linkedlist.cpp
Description		: 
Author			: 1. Garly Nugraha - 211511037
				  2. Jeremia Edwin Hamonangan - 211511039
Date			: 10/09/2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include "linkedlist.h"
#include "boolean.h"

boolean ListEmpty(List L)
{

	return (First(L) == Nil);
}

void CreateList(List *L)
{
	First(*L) = Nil;
}

address Alokasi(infotype X)
{
	address P = (address)malloc(sizeof(ElmtList));
	
	if (P != Nil)
	{
		strcpy(Info(P), X);
		Next(P) = Nil;
	}
	
	return P;
}

void Dealokasi(address *P)
{
	Next(*P) = Nil;
	free(*P);
}

address Search(List L, infotype X)
{
	address P = First(L);
	boolean found = false;
  
	while ((P != Nil) && (!found))
	{
		if (strcmp(Info(P),X)==0) {
			found = true;
		} else {
			P = Next(P);
		}
	}
	
	return P;
}

address SearchPrec(List L, infotype X)
{
	address Prec;
	address P;

	if (Next(P) == Nil) {
		Prec = Nil;
	} else {
		P = First(L);
		
		while ((Next(P) != Nil) && (Info(P) != X))
		{
			Prec = P;
			P = Next(P);
		}

		if (Info(P) == X)
		{
			return Prec;
		} else {
			return Nil;
		}
	}
}

void InsVFirst(List *L, infotype X)
{
	address P = Alokasi(X);
	if (P != Nil)
	{
		InsertFirst(&(*L), P);
	}
}

void InsVLast(List *L, infotype X)
{
	address P = Alokasi(X);
	
	if (P != Nil) {
		InsertLast(&(*L), P);
	}
}

void DelVFirst(List *L, infotype *X)
{
	address P;

	DelFirst(&(*L), &P);
	strcpy(*X,Info(P));
	Dealokasi(&P);
}

void DelVLast(List *L, infotype *X)
{
	address P;
	DelLast(&(*L), &P);
	strcpy(*X,Info(P));
	Dealokasi(&P);
}

void InsertFirst(List *L, address P)
{
	Next(P) = First(*L);
	First(*L) = P;
}

void InsertAfter(List *L, address P, address Prec)
{
	Next(P) = Next(Prec);
	Next(Prec) = P;
}

void InsertLast(List *L, address P)
{
	address Last;
	
	if (ListEmpty(*L)) {
		InsertFirst(&(*L), P);
	} else {
		Last = First(*L);
		
		while (Next(Last) != Nil)
		{
			Last = Next(Last);
		}

		Next(Last) = P;
	}
}

void DelFirst(List *L, address *P)
{
	*P = First(*L);
	First(*L) = Next(First(*L));
	Next(*P) = Nil;
}

void DelP (List *L, infotype X){
	address P;
	address Prec;
  	infotype Y;

  	P = First(*L);

  	if (Info(P) == X) {
    	DelVFirst(L, &Y);
  	} else {
    	Prec = P;
		P = Next(P);

    	while (P != Nil) {
      		if (Info(P) == X){
        		Next(Prec) = Next(P);
        		P = Nil;
      		} else {
        		Prec = P;
        		P = Next(P);
      		}
    	}
  	}
}

void DelLast(List *L, address *P)
{
	address Last, PrecLast;

	Last = First(*L);

	if (Next(Last) == Nil) {
		DelFirst(&(*L), &(Last));
	} else {
		PrecLast = Nil;
		
		while (Next(Last) != Nil)
		{
			PrecLast = Last;
			Last = Next(Last);
		}
		
		*P = Last;
		Next(PrecLast) = Nil;
	}
}

void DelAfter(List *L, address *Pdel, address Prec)
{
	*Pdel = Next(Prec);
	Next(Prec) = Next(*Pdel);
}

void PrintInfo(List L)
{
	int i;
	address P = First(L);
	
	if (P == Nil) {
		printf("List Kosong !\n");
	} else {
		printf("[ ");
		
		do
		{
			printf("%s ", Info(P));
			P = Next(P);
			i++;
		} while (P != Nil);
		
		printf("]");
	}
	
	printf("\n");
}

