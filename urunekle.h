#ifndef URUNEKLE_H
#define URUNEKLE_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "degiskenler.h"

// Fonksiyon prototipleri
bool urunnovarmi(int urunno, FILE *dosya);
void urunekle();

// Ürün numarasının zaten var olup olmadığını kontrol eden fonksiyon
bool urunnovarmi(int urunno, FILE *dosya) 
{
    if (dosya == NULL) 
    {
        printf("Dosya acilirken hata olustu.\n");
        exit(1);
    }


    // Dosya işaretçisini başa al
    fseek(dosya, 0, SEEK_SET);

    // Dosyadan ürün bilgilerini oku ve ürün numarasını kontrol et
    while (fscanf(dosya, "%d %s %d", &mevcuturunno, mevcuturunadi, &mevcutstok) == 3) 
    {
        if (mevcuturunno == urunno) 
            return true; // Ürün numarası zaten var
    }

    // Dosya işaretçisini başa al, ürün numarasını bulamadıysak buraya kadar gelindiğinde başa alınmalı. yoksa son konumdan devam edip sürekli bulamiyor
    fseek(dosya, 0, SEEK_SET);
    return false; // Ürün numarası yok
}

// Yeni bir ürün ekleyen fonksiyon
void urunekle() 
{
    printf("----------------\n");
    printf("- Urun Ekleme -\n");
    printf("----------------\n\n");

    FILE *fpw = fopen("urunler.txt", "a");
    if (fpw == NULL) 
    {
        printf("Dosya acilirken hata olustu.\n");
        return;
    }

    printf("Urun No giriniz: ");
    scanf("%d", &turunno);
    if(turunno == 0) 
    {
        printf("Yanlis tuslama yaptiniz lütfen enter'a basiniz.\n"); // Karakter girmeye çalışırsa compiler 0 okur, 0 da istediğimiz bir numara değil
        while(getchar() != '\n'); // scanf'in buffer'ini boşaltır
        fclose(fpw);
        return;  
    }
    
    // Dosyayı okuma modunda tekrar aç
    FILE *fpr = fopen("urunler.txt", "r");
    if (fpr == NULL) 
    {
        printf("Dosya acilirken hata oluştu.\n");
        fclose(fpw);
        return;
    }

    if (urunnovarmi(turunno, fpr)) 
    { // Dosya işaretçisini de gönder
        printf("Hata: Urun numarasi zaten var. Lutfen yeni bir numara giriniz.\n");
        fclose(fpw);
        fclose(fpr);
        return;
    }

    fclose(fpr); // Dosyayı kapat

    printf("Urun adi giriniz: ");
    scanf("%s", turunadi);
    printf("Stok miktarini giriniz: ");
    scanf("%d", &tstok);

    fprintf(fpw, "%d %s %d\n", turunno, turunadi, tstok);
    fclose(fpw);
}

#endif
