#ifndef TARIHGIR_h
#define TARIHGIR_h
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "degiskenler.h"

//Uye islemleri
#include "uyeekle.h"
#include "uyesil.h"
#include "uyeguncelle.h"
#include "uyelistele.h"

//Urun islerimleri
#include "urunekle.h"
#include "urunsil.h"
#include "urunguncelle.h"
#include "urunlistele.h"

void tarihgir() 
{
    scanf("%d %d %d", &gun, &ay, &yil);
    printf("Girilen tarih: %02d/%02d/%d\n", gun, ay, yil);
}
// satis bildir
#endif