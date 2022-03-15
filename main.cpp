/*
File Name		: main.h
Description		: 
Author			: 1. Garly Nugraha - 211511037
				  2. Jeremia Edwin Hamonangan - 211511039
Date			: 10/09/2022
*/

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "linkedlist.h"

int main() {	
	infotype anggota;
	ElmtListkota data_kota[5];
	address cari, P;
	int i;
	char again;
	char nama[15], nama2[15];
	
	for(i = 0; i < 5; i++) {
		printf("\nInput Kota: ");
		scanf("%s", &data_kota[i].nama_kota);
	}

	for(i = 0; i < 5; i++) {
		printf("Kota %s ",data_kota[i].nama_kota);
		CreateList(&data_kota[i].penduduk);
		
		do{
			printf("\nMasukkan nama penduduk: ");
			scanf("%s", &nama);
			InsVFirst(&data_kota[i].penduduk, nama);
			printf("Masukkan Lagi? (Y/N)");
			again = getche();
		}while(again == 'Y' || again == 'y');
		
		printf("\nPenduduk pada kota %s : ",  data_kota[i].nama_kota);
		PrintInfo(data_kota[i].penduduk);
		printf("\n");
	}
	
	for(i = 0; i < 5; i++) {
		printf("\nMenambahkan node baru dengan insert first pada kota %s: ", data_kota[i].nama_kota);	
		scanf("%s", &nama);
		InsVFirst(&data_kota[i].penduduk, nama);
		printf("\nKota %s : ",data_kota[i].nama_kota);
		PrintInfo(data_kota[i].penduduk);
	}

	for(i = 0; i < 5; i++) {
		printf("\nMenambahkan node baru dengan insert last pada kota %s: ", data_kota[i].nama_kota);	
		scanf("%s", &nama);
		InsVLast(&data_kota[i].penduduk, nama);
		printf("\nKota %s : ",data_kota[i].nama_kota);
		PrintInfo(data_kota[i].penduduk);
	}
	
	for(i = 0; i < 5; i++) {
		printf("\nMenambahkan node baru dengan insert after pada kota %s: ", data_kota[i].nama_kota);
		printf("\nMasukkan nama penduduk sebelum node baru: ");
		scanf("%s", &nama2);
		cari = Search(data_kota[i].penduduk, nama2);
		printf("\nMasukkan nama penduduk: ");
		scanf("%s", &nama);
		P = Alokasi(nama);
		InsertAfter(&data_kota[i].penduduk, P, cari);
		PrintInfo(data_kota[i].penduduk);
	}

	for(i = 0; i < 5; i++) {
		printf("\Delete node dengan delete first pada kota %s: \n", data_kota[i].nama_kota);
		DelVFirst(&data_kota[i].penduduk, &anggota);
		printf("Kota %s : ",data_kota[i].nama_kota);
		PrintInfo(data_kota[i].penduduk);
	}
	
	for(i = 0; i < 5; i++) {
		printf("\Delete node dengan delete last pada kota %s: \n", data_kota[i].nama_kota);	
		DelVLast(&data_kota[i].penduduk, &anggota);
		printf("Kota %s : ",data_kota[i].nama_kota);
		PrintInfo(data_kota[i].penduduk);
	}
	
	printf("|==================================================|\n");
	printf("|                        HASIL                     |\n");
	printf("|==================================================|\n");
	
	for(i = 0; i < 5; i++) {
		printf("Kota %s : ",data_kota[i].nama_kota);
		PrintInfo(data_kota[i].penduduk);
	}

	return 0;
}
