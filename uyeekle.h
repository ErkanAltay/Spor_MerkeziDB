#ifndef UYEEKLE_H
#define UYEEKLE_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "degiskenler.h"

// Üye numarasının zaten var olup olmadığını kontrol eden fonksiyon
bool uyenovarmi(int uyeno, FILE *dosya) {
    if (dosya == NULL) 
    {
        printf("Dosya acilirken hata olustu.\n");
        exit(1);
    }

    // Dosya işaretçisini başa al
    fseek(dosya, 0, SEEK_SET);

    // Dosyadan üye bilgilerini oku ve üye numarasını kontrol et
    while (fscanf(dosya, "%d %s %s %d %d %d %d", &mevcutuyenumarasi, mevcutuyeadi, mevcutuyesoyadi, &mevcutgun, &mevcutay, &mevcutyil, &mevcutaidat) == 7) 
    {
        if (mevcutuyenumarasi == uyeno) 
        {
            fseek(dosya, 0, SEEK_SET); // Dosya işaretçisini başa al
            return true; // Üye numarası zaten var
        }
    }

    fseek(dosya, 0, SEEK_SET); // Dosya işaretçisini başa al
    return false; // Üye numarası yok
}

// Yeni bir üye ekleyen fonksiyon
void uyeekle() 
{
    printf("----------------\n");
    printf("- Uye Ekleme -\n");
    printf("----------------\n\n");

    FILE *fpw = fopen("kayit.txt", "a");
    if (fpw == NULL) 
    {
        printf("Dosya acilirken hata olustu.\n");
        return;
    }

    printf("Uye No giriniz: ");
    scanf("%d", &tuyeno);
    if (uyeno == 0 && tuyeno == 0) 
    {
        printf("Yanlis tuslama yaptiniz lutfen enter a basiniz\n");
        while (getchar() != '\n');
        return;
    }
    
    // Dosyayı okuma modunda tekrar aç
    FILE *fpr = fopen("kayit.txt", "r");
    if (fpr == NULL) 
    {
        printf("Dosya acilirken hata oluştu.\n");
        fclose(fpw);
        return;
    }

    if (uyenovarmi(tuyeno, fpr)) 
    { // Dosya işaretçisini de gönder
        printf("Hata: Uye numarasi zaten var. Lutfen yeni bir numara giriniz.\n");
        fclose(fpw);
        fclose(fpr);
        return;
    }

    fclose(fpr); // Dosyayı kapat

    printf("Uye adi giriniz: ");
    scanf("%s", tuyeadi);
    printf("Uye soyadini giriniz: ");
    scanf("%s", tuyesoyadi);
    printf("Uye Kayit tarihini giriniz (GG AA YY): ");
    scanf("%d %d %d", &gun, &ay, &yil);
    printf("Alinacak aidat miktarini giriniz: ");
    scanf("%d", &taidat);

    fprintf(fpw, "%d %s %s %d %d %d %d\n", tuyeno, tuyeadi, tuyesoyadi, gun, ay, yil, taidat);
    fclose(fpw);
    printf("kaydiniz olusturulmustur.");
}

#endif
