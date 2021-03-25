#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Dugum{
     int kackez;
     char veri[100];
     struct Dugum *sonraki;

};
    struct Dugum *ilk=NULL;
    struct Dugum *son=NULL;





    void BasaEkle(char * veriler,int XXX)
{
    struct Dugum *yeni = (struct Dugum*) malloc(sizeof(struct Dugum));
strcpy(yeni->veri,veriler);
            yeni->kackez=XXX;

    if(ilk==NULL)
    {
        ilk=yeni;
        son=yeni;
        son->sonraki=NULL;
    }
    else
    {
        yeni->sonraki=ilk;
        ilk=yeni;
    }
}
    void Araya_Ekle(char* veriler,int kac,int max,int min){
        struct Dugum *yeni=(struct Dugum *)malloc(sizeof(struct Dugum));
        int i,j,sayac=0;
        struct Dugum *yeni_liste=ilk;
        for(i=0;yeni_liste!=NULL;i++){

                if(yeni_liste->kackez==kac){
                    sayac=1;
                    yeni->sonraki=yeni_liste->sonraki;
                    yeni_liste->sonraki=yeni;
                    strcpy(yeni->veri,veriler);
                    yeni->kackez=kac;
                    break;
                }
                else if(yeni_liste->kackez>kac && yeni_liste->sonraki->kackez<kac){
                    sayac=1;
                    yeni->sonraki=yeni_liste->sonraki;
                    yeni_liste->sonraki=yeni;
                    strcpy(yeni->veri,veriler);
                    yeni->kackez=kac;
                    break;

                }

                yeni_liste=yeni_liste->sonraki;

            if(sayac==1)
                break;
        }





    }




    void Sona_Ekle(char* veriler,int xx){
            struct Dugum *yeni=(struct Dugum *)malloc(sizeof(struct Dugum));
            yeni->kackez=xx;
            if(ilk==NULL){
                ilk=yeni;
                son=yeni;
                strcpy(yeni->veri,veriler);
                son->sonraki=NULL;
            }
            else{
                son->sonraki=yeni;
                son=yeni;
            strcpy(yeni->veri, veriler);
                son->sonraki=NULL;
            }
}

void Listele(){
    int sayac=0;
struct Dugum *liste=ilk;
        while(liste!=NULL){
                sayac ++;
printf("%d.%s    :  %d\n",sayac,liste->veri,liste->kackez);
 liste=liste->sonraki;
        }
}
 int listedevarmi(char* kelime){
     struct Dugum *liste3=ilk;
     while(liste3!=NULL){
        if(strcmp(kelime,liste3->veri)==0){
            return 1;
        }
        liste3=liste3->sonraki;
     }
     return 0;
 }


int main()
{int XXX=0;
int sayacc=0;
int deneme=0;
    FILE *dosya=fopen("Veriler.txt","r");
long double temp=ftell(dosya);
     struct Dugum *liste2=ilk;

    fseek(dosya,0,SEEK_END);

     int max=-1000;
     int min=1000;
      long double tutbakim=ftell(dosya);
    for(int j=0;!feof(dosya);j++){
    if(deneme==0)
       fseek(dosya,temp,SEEK_SET);
deneme++;
            if(ftell(dosya)==tutbakim){
                break;
            }
    char *veriler=(char*)malloc(sizeof(liste2->veri));
        int x=0;
        fscanf(dosya,"%s",veriler);
     long double uzunluk=ftell(dosya);
     rewind(dosya);

struct Dugum * xxxx;
for(int i=0;!feof(dosya);i++){

        char *veriler2=(char*)malloc(sizeof(xxxx->veri));


fscanf(dosya,"%s",veriler2);


if(strcmp(veriler2,veriler)==0){
XXX++;
}
}
if(listedevarmi(veriler)==0){
if(max<=XXX){
BasaEkle(veriler,XXX);
max=XXX;
}
else if(min>=XXX){
    Sona_Ekle(veriler,XXX);
    min=XXX;
}
  if (min<XXX && max>XXX) {
        Araya_Ekle(veriler,XXX,max,min);

}

}

fseek(dosya,uzunluk,SEEK_SET);
XXX=0;

    }
    fclose(dosya);


    printf("\n\n-------------------------------------------\n");
    Listele();
}
