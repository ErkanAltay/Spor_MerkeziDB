// degiskenler.h
#ifndef DEGISKENLER_H
#define DEGISKENLER_H

#include <stdio.h>
#include <windows.h>
#include <string.h>

// Bu projeye 3.12.2022 tarihinde baslanmistir - Erkan ALTAY
// V2 02.01.2024 tarihinde yapilmaya baslanmistir - Erkan ALTAY

FILE *fpr, *fpw;
//Yapısal degiskenler
int bulunan_kayit_sayisi = 0;
char secimuye;
char secimurun;
int red;
int gun, ay;
int  yil=2024;
int bulundu = 0; // uyenin bulunup bulunmadığını kontrol etmek için bir 0 1 sistemi
char girilenID[10];
char girilenSifre[10];
const char dogruID[] = "5807";
const char dogruSifre[] = "9865";
int secim1;
int secim2;
int secilen;
int satisMiktari;
// uye degiskenleri

int mevcutuyenumarasi;
char mevcutuyeadi[50];
char mevcutuyesoyadi[50];
int mevcutgun, mevcutay, mevcutyil;
int mevcutaidat;
int uyeno;
int tuyeno;
char uyeadi[20];
char tuyeadi[50];
char uyesoyadi[20];
char tuyesoyadi[20];
char aranan_uye_adi[50];
int aidat;
int taidat;
// urun degiskenleri
int urunno;
int turunno;
char urunadi[40];
char turunadi[40];
int stok;
int tstok;
int mevcutstok;
char mevcuturunadi[40];
int mevcuturunno;
#endif // DEGISKENLER_H