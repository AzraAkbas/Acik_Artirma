#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {//Katýlýmcýlarýn adý,soyadý,yaptýðý teklif ve ödemesini içeren yapý.
    char ad[100];
    double teklif;
    double odeme;
} TeklifSahibi;

int main() {
    double baslangicFiyati = 100;
    TeklifSahibi* enYuksekTeklifSahibi;// Katýlýmcý bilgilerini tutan dinamik dizi.
    double teklif;
    int katilimciSayisi;
    int i;
    int kazananIndex = 0;

    printf("~~ Acik artirma basliyor ~~\n");
    printf("Baslangic fiyati: %lf $\n", baslangicFiyati);

    printf("Katilimci sayisini giriniz: ");
    scanf("%d", &katilimciSayisi);

    if (katilimciSayisi <= 0) {
        printf("Gecersiz katilimci sayisi girildi.\n");
        return 1;
    }
	// Katýlýmcý sayýsýna göre bellekten yer ayýran kýsým.
    enYuksekTeklifSahibi = (TeklifSahibi*)malloc(katilimciSayisi * sizeof(TeklifSahibi));
	// Her bir katýlýmcýnýn bilgileri kullanýcýdan alan kýsým.
    for (i = 0; i < katilimciSayisi; ++i) {
        printf("%d. katilimcinin ismini giriniz: ", i + 1);
        scanf("%s", enYuksekTeklifSahibi[i].ad);
        enYuksekTeklifSahibi[i].teklif = baslangicFiyati;
        enYuksekTeklifSahibi[i].odeme = 0;
    }
	double enYuksekTeklif = baslangicFiyati;  // En yüksek teklifin baþlangýç deðeri.
	// Açýk artýrma döngüsü
    while (1) {
        printf("Teklif yapmak isteyen katilimci numarasini giriniz (Cikmak icin 0'a basiniz): ");
        scanf("%d", &i);

        if (i == 0) {// Eðer kullanýcý 0'a basarsa, açýk artýrma sona eriyor.
            printf("Acik artirma sona erdi.\n");
			while (getchar() != '\n');

			// En yüksek teklifi yapan katýlýmcýyý bulma iþlemi.
            for (i = 1; i < katilimciSayisi; ++i) {
                if (enYuksekTeklifSahibi[i].teklif > enYuksekTeklifSahibi[kazananIndex].teklif) {
                    kazananIndex = i;
                }
            }
			//Programýn sonundaki kazanan katýlýmcý bilgilerini ve ödenecek tutarý ekrana yazdýran kýsým.
            printf("En yuksek teklif: %lf$ (%s)\n", enYuksekTeklifSahibi[kazananIndex].teklif, enYuksekTeklifSahibi[kazananIndex].ad);

            double kazananOdeme = enYuksekTeklifSahibi[kazananIndex].teklif;
            printf("%s, Odemeniz gereken toplam tutar: %lf$\n", enYuksekTeklifSahibi[kazananIndex].ad, kazananOdeme + baslangicFiyati);

            free(enYuksekTeklifSahibi);// Bellekten ayrýlan alan temizleyen ve sonlandýran kýsým.

            return 0;
        }
		// Kullanýcýnýn girdiði katýlýmcý numarasýnýn geçerli olup olmadýðýný kontrol eden kýsým.	
        if (i >= 1 && i <= katilimciSayisi) {
            printf("%d. %s, Teklifinizi giriniz (cikmak icin 0'a basiniz):$", i, enYuksekTeklifSahibi[i - 1].ad);
            scanf("%lf", &teklif);
			//Eðer kullanýcý 0'a basarsa programý sona erdiren kýsým.
            if (teklif == 0) {
                printf("Acik artirma sona erdi.\n");
                continue;
            }
			// Yeni teklif en yüksek tekliften büyükse en yüksek teklif güncelleniyor.
            if (teklif > enYuksekTeklif) {
                enYuksekTeklif = teklif;
                printf("Yeni en yuksek teklif!:%lf$ (%s)\n", enYuksekTeklif, enYuksekTeklifSahibi[i - 1].ad);
            } else {
                printf("Daha yuksek bir teklif vermelisiniz.\n");
            }
			// Katýlýmcýnýn teklifi güncelleyen kýsým.
            enYuksekTeklifSahibi[i - 1].teklif = teklif;
            
        } else { // Geçersiz bir katýlýmcý numarasý girildiyse kullanýcýyý uyaran kýsým.
            printf("Gecersiz katilimci numarasi. Lutfen tekrar deneyin.\n");
        }
        
    }

    return 0;
}
