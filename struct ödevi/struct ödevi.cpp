/****************************************************************************
**                                SAKARYA ÜNİVERSİTESİ
**					   BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**					    BİLİŞİM SİSTEMLERİ MÜHENDİSLİĞİ BÖLÜMÜ
**						    PROGRAMLAMAYA GİRİŞ DERSİ
**							  2017-2018 GÜZ DÖNEMİ
**
**							ÖDEV NUMARASI..........: 4
**							ÖĞRENCİ ADI............: Veysel Doğan / Muhammed Emin Güzel
**							ÖĞRENCİ NUMARASI.......: b171200041 / b171200013
**							DERSİN ALINDIĞI GRUP...: A
*****************************************************************************/

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

//yapılar:
struct struct1
{
	bool bellekyaziliyor = false;
	bool duzgunkapandi = false;
};

struct struct2
{
	string kelime, harfbellegi;
	char harf;
};

struct struct3
{
	int secim;
	int i = 0;
	int sayac = 0;
};


int main()
{
	setlocale(LC_ALL, "Turkish");
	//Menü ekranının sürekli dönmesi için.
	do {
		system("CLS");

		struct1 truefalse;
		struct2 metinharf;
		struct3 diger;

		//Kullanıcıdan değer alma
		cout << "..:: String İşlemleri ::..\n";
		cout << "İşlem yapılacak stringi giriniz:";
		cin >> metinharf.kelime;
		cout << "İstenilen harf:";
		cin >> metinharf.harf;
		cout << "1-Ara Metni Tersten Yaz" << endl << "2-Ara Metni Tekrarlı Yaz" << endl << "Seçiminiz: ";
		cin >> diger.secim;



		for (int i = 0; metinharf.kelime[i] != '\0'; i++)
		{
			//Eğer bellek yazılıyorsa
			if (truefalse.bellekyaziliyor)
			{
				//ve 'harf' geldiyse
				if (metinharf.harf == metinharf.kelime[i])
				{
					//Tüm islemler en son düzgün olarak erçekleştiyse, satir 51 deki koşulun sağlanması için duzgunKapandı doğrulanır.
					truefalse.duzgunkapandi = true;
					break;
				}
				else
				{
					metinharf.harfbellegi += metinharf.kelime[i];
				}
			}
			//Eğer bellek yazılmıyorsa
			else
			{
				//ve 'harf' geldiyse
				if (metinharf.harf == metinharf.kelime[i])
				{
					//bellek yazdırma koşulunu doğruladık.
					truefalse.bellekyaziliyor = true;
				}
			}
		}

		//harfbellegi nin kaç harfli olduğunu bulalım:


		while (metinharf.harfbellegi[diger.i] != '\0')
		{
			diger.sayac++;
			diger.i++;
		}

		//duzgunKapandı doğrulandıysa islemler gerçekleşir.
		if (truefalse.duzgunkapandi)
		{
			switch (diger.secim)//seçimi kontrol ediyoruz
			{
			case 1: //1 ise
					//harfbellegi harf sayısı kaç ise ondan başlar ve 0 dan büyük eşitken birer birer azalar, böylece metin tersten yazılmış olur.
				for (diger.i = diger.sayac; diger.i >= 0; diger.i--)
				{
					cout << metinharf.harfbellegi[diger.i];
				}
				cout << endl;
				break;

			case 2:
				//i 0 dan başlar dörde eşit olana kadar artar bu arada harfbellegini yazdırır, böylelikle 5 kere yazdırmış oluruz. 
				for (diger.i = 0; diger.i < 5; diger.i++)
				{
					cout << metinharf.harfbellegi << endl;
				}
				break;

			default:
				cout << "Geçersiz Seçim Yaptınız";
				break;
			}
		}
		//eğer truefalse.duzgunkapandi yanlışsa ve doğrulanmazsa hata mesajını verir.
		else {
			cout << "Cümle içerisinde aranan harf bulunamadı." << endl;
		}
		system("PAUSE");
	} while (true);
	return 0;
}

