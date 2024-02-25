#ifndef UYEBUL_H
#define UYEBUL_H

#include <stdio.h>
#include <string.h>
#include "uyeara.h"
#include "degiskenler.h"


void uyebul(const char* aranan_adi) {
    FILE *fpr = fopen("kayit.txt", "r");

    if (fpr == NULL) 
    {
        printf("Dosya acilirken hata olustu.\n");
        return;
    }
    
    // Dosyadan üye bilgilerini oku ve ekrana yazdır
    while (fscanf(fpr, "%d %s %s %d %d %d %d", &uyeno, uyeadi, uyesoyadi, &gun, &ay, &yil, &aidat) != EOF) 
    {
        if (strcmp(aranan_adi, uyeadi) == 0) {
            printf("%d | %s | %s | %d/%d/%d | %d\n", uyeno, uyeadi, uyesoyadi, gun, ay, yil, aidat);
            bulunan_kayit_sayisi++;
        }
    }

    fclose(fpr);

    // Bulunan kayıt sayısına göre mesaj yazdır
    if (bulunan_kayit_sayisi == 0) 
        printf("Aranan uye adina ait kayit bulunamadi.\n");
}

#endif