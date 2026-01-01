#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ogr_ekle(char *name, int yas, int numara, int gecisnotu);
void ogr_listele1();
void ogr_listele2();
void ogr_sil();
struct Ogrenci* ogr_ara(int secim);
void temizle();

struct Ogrenci{
    char name[50];
    int yas;
    int numara;
    int gecisnotu;

    struct Ogrenci *next;
    struct Ogrenci *prev;
};

struct Ogrenci *baslangic=NULL;
struct Ogrenci *bitis=NULL;

void ogr_ekle(char *name,int yas,int numara,int gecisnotu){

    struct Ogrenci *yeni=(struct Ogrenci*)malloc(sizeof(struct Ogrenci));

    strcpy(yeni->name,name);
    yeni->yas=yas;
    yeni->numara=numara;
    yeni->gecisnotu=gecisnotu;
    yeni->prev=NULL;
    yeni->next=NULL;

    if(baslangic==NULL)
    {
        baslangic=yeni;
        bitis=yeni;
    }
    else{
        bitis->next=yeni;
        yeni->prev=bitis;
        bitis=yeni;
    }

    printf("Ogrenci listeye eklendi.\n");
}

void ogr_listele1(){
    if(baslangic==NULL)
    {
        printf("Listede kimse yok.\n");
        return;
    }

    struct Ogrenci *temp=baslangic;
    int sira=1;
    printf("\n--- Bastan Sona Liste ---\n");
    while(temp!=NULL)
    {
        printf("Sira %d | Isim: %s | Yas: %d | Numara: %d | Gecis Notu: %d\n",
               sira,temp->name,temp->yas,temp->numara,temp->gecisnotu);
        temp=temp->next;
        sira++;
    }
    printf("--------------------------\n");
}

void ogr_listele2(){
    if(baslangic==NULL)
    {
        printf("Listede kimse yok.\n");
        return;
    }

    struct Ogrenci *temp=bitis;
    int sira=0;

    struct Ogrenci *say=baslangic;
    while(say!=NULL){ sira++; say=say->next; }

    printf("\n--- Sondan Basa Liste ---\n");
    while(temp!=NULL)
    {
        printf("Sira %d | Isim: %s | Yas: %d | Numara: %d | Gecis Notu: %d\n",
               sira,temp->name,temp->yas,temp->numara,temp->gecisnotu);
        temp=temp->prev;
        sira--;
    }
    printf("--------------------------\n");
}

void ogr_sil(){
    if(baslangic==NULL)
    {
        printf("Silinecek kimse yok.\n");
        return;
    }

    struct Ogrenci *sil = ogr_ara(0);

    if(sil==NULL)
    {
        printf("Ogrenci bulunamadi.\n");
        return;
    }

    if(baslangic==bitis)
    {
        baslangic=NULL;
        bitis=NULL;
    }
    else if(sil==baslangic)
    {
        baslangic=baslangic->next;
        baslangic->prev=NULL;
    }
    else if(sil==bitis)
    {
        bitis=bitis->prev;
        bitis->next=NULL;
    }
    else
    {
        sil->prev->next=sil->next;
        sil->next->prev=sil->prev;
    }

    printf("%d numarali ogrenci silindi. Isim: %s, Yas: %d\n",
           sil->numara, sil->name, sil->yas);
    free(sil);
}

struct Ogrenci *ogr_ara(int secim){
    if(baslangic==NULL){
        printf("Aranacak ogrenci yok.\n");
        return NULL;
    }

    int aranacaknum;
    printf("Islem yapilacak ogrencinin numarasini giriniz: ");
    scanf("%d",&aranacaknum);

    struct Ogrenci *ara=baslangic;
    while(ara!=NULL){
        if(ara->numara==aranacaknum){
            if(secim==5){
                printf("Isim: %s | Yas: %d | Numara: %d | Gecis Notu: %d\n",
                       ara->name,ara->yas,ara->numara,ara->gecisnotu);
            }
            return ara;
        }
        ara=ara->next;
    }
    return NULL;
}

void temizle(){
    if(baslangic==NULL){
        printf("Temizlenecek bir sey yok.\n");
        return;
    }

    struct Ogrenci *temp=baslangic;
    while(temp!=NULL)
    {
        struct Ogrenci *temp2=temp;
        temp=temp->next;
        free(temp2);
    }
    baslangic=NULL;
    bitis=NULL;
    printf("Bellek basariyla temizlendi.\n");
}

int main(){
    char name[50];
    int yas,numara,gecisnotu;
    int secim;

    do{
        printf("\n--- MENU ---\n");
        printf("1 - Ogrenci Ekle\n2 - Listele (Bastan)\n3 - Listele (Sondan)\n4 - Ogrenci Sil\n5 - Ogrenci Ara\n6 - Listeyi Bosalt ve Cik\nSecim: ");
        scanf("%d",&secim);

        switch(secim){
        case 1:
            printf("Isim: ");
            getchar();
            fgets(name,sizeof(name),stdin);
            name[strcspn(name, "\n")] = '\0';
            printf("Yas: "); scanf("%d",&yas);
            printf("Numara: "); scanf("%d",&numara);
            printf("Gecis Notu: "); scanf("%d",&gecisnotu);
            ogr_ekle(name,yas,numara,gecisnotu);
            break;
        case 2: ogr_listele1(); break;
        case 3: ogr_listele2(); break;
        case 4: ogr_sil(); break;
        case 5: ogr_ara(secim); break;
        case 6: temizle(); printf("Programdan cikiliyor...\n"); break;
        default: printf("Hatali tuslama!\n"); break;
        }

    }while(secim!=6);

    return 0;
}
