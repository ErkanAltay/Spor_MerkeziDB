#ifndef UYESIL_H
#define UYESIL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "degiskenler.h"

// Uye islemleri
#include "uyeekle.h"
#include "uyeguncelle.h"
#include "uyelistele.h"
#include "tarihgir.h"

// Urun islemleri
#include "urunekle.h"
#include "urunsil.h"
#include "urunguncelle.h"
#include "urunlistele.h"

// Uyeyi silen fonksiyon
void uyesil() 
{
    printf("-Uye Kaydi Silme-\n");
    printf("----------------\n\n");

    // Geçici dosyayı yazma modunda aç
    FILE *fpw = fopen("tmp.txt", "w");

    // Kayıtlı üyelerin bulunduğu dosyayı okuma modunda aç
    FILE *fpr = fopen("kayit.txt", "r");

    // Dosya açma kontrolü
    if (fpr == NULL || fpw == NULL) 
	{
        printf("Dosya acilirken hata olustu.\n");
        exit(1);
    }

    // Silinecek üye numarasını kullanıcıdan al
    printf("Silmek istediginiz Uye No giriniz ");
    scanf("%d", &secilen);

    // Üye bulundu mu kontrolü için 
    bool bulundu = false;

    // Dosyayı satır satır oku
    while (fscanf(fpr, "%d %s %s %02d %02d %d %d\n", &uyeno, &uyeadi, &uyesoyadi, &gun, &ay, &yil, &aidat) != EOF) 
	{
        // Silinecek üyenin numarasıyla eşleşmiyorsa, geçici dosyaya yaz
        if (uyeno != secilen) 
		{
            fprintf(fpw, "%d %s %s %02d %02d %d %d\n", uyeno, uyeadi, uyesoyadi, gun, ay, yil, aidat);
        } 
		else 
		{
            bulundu = true; // Üye numarası bulundu
        }
    }

    // Dosyaları kapat
    fclose(fpr);
    fclose(fpw);

    // Eğer üye bulunduysa, eski dosyayı silip geçici dosyayı yeni dosya olarak adlandır
    if (bulundu) 
	{
        printf("%d = NO lu uye Kaydi silinmistir",secilen);
        remove("kayit.txt");
        rename("tmp.txt", "kayit.txt");
    } 
	else 
	{
        printf("%d = NO lu uye Kaydi bulunamamistir", secilen);
        remove("tmp.txt");
    }
}

#endif
