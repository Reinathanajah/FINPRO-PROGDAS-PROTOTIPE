#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct ABC { 
float AkumulasiKgSayurA;
float AkumulasiKgSayurB;
float AkumulasiKgSayurC;
float AkumulasiBuahSayurA;
float AkumulasiBuahSayurB;
float AkumulasiBuahSayurC;
float AkumulasiKgBerasA;
float AkumulasiKgBerasB;
float AkumulasiKgBerasC;
float AkumulasiKrgBerasA;
float AkumulasiKrgBerasB;
float AkumulasiKrgBerasC;
float AkumulasiKgDagingA;
float AkumulasiKgDagingB;
float AkumulasiKgDagingC;
float AkumulasiKgSnackA;
float AkumulasiKgSnackB;
float AkumulasiKgSnackC;
float AkumulasiPcsSnackA;
float AkumulasiPcsSnackB;    
float AkumulasiPcsSnackC;
float AkumulasiKgSupleA;
float AkumulasiKgSupleB;       
float AkumulasiKgSupleC;
float AkumulasiSctSupleA;
float AkumulasiSctSupleB;
float AkumulasiSctSupleC;
}; 
struct sisa { 
float SisaBerasA; 
float SisaBerasB;   
float SisaBerasC; 
float SisaSnackA;
float SisaSnackB;
float SisaSnackC;
float SisaDagingA;
float SisaDagingB;
float SisaDagingC;
float SisaSupleA;
float SisaSupleB;
float SisaSupleC;
float SisaSayurA; 
float SisaSayurB; 
float SisaSayurC; 
};

struct ABCOrang { 
 int orangA; 
 int orangB;
 int orangC;
};

struct Namabarang { 
    char namaberas[50]; 
    char namasnack [50]; 
    char namasuple [50];
    char namahewan [50]; 
    char namasayur [50];
};

struct BerasBahanbaku  { 
    float jumlahKgberas; 
    int jumlahBuahberas; 
};
 struct Makananringan  { 
    float jumlahKgsnack; 
    int jumlahBuahsnack; 
};
 struct SuplemenObat  { 
    float jumlahKgsuple; 
    int jumlahBuahsuple; 
};

 struct OlahanHewan  { 
    float jumlahKgdaging; 
};

struct SayurdanBuah  { 
    float jumlahKgsayur; 
    int jumlahBuahsayur; 
};
 
enum bentukdonasi{Beras_dan_bahan_baku,Makanan_Ringan,Suplemen,Olahan_hewan,Sayur_dan_buah};
enum benua{BenuaAmerika,BenuaAsia,BenuaAustralia,BenuaAfrika,BenuaEropa,BenuaOseania};
struct KodeTeleponBenua{
    char nama[50];
    int kodetelepon; 
};

struct Donasi{ 
    enum bentukdonasi barang;
    struct BerasBahanbaku beras; 
    struct Makananringan snack; 
    struct SuplemenObat suple; 
    struct OlahanHewan daging;
    struct SayurdanBuah sayur;
    struct Namabarang ItemName;
    struct ABC Bagi; 
    struct sisa Sisa;

};

typedef struct {
    char nama[50];
    float populasi_juta;         
    float kelaparan_juta;        
    float persentase_kelaparan;  
} NegaraAfrika;

 NegaraAfrika data[15] = {
        {"Nigeria", 237.5, 31.8, 13.4},
        {"Rep. Dem. Kongo", 112.8, 23.4, 20.7},
        {"Ethiopia", 135.5, 15.8, 11.7},
        {"Sudan", 51.7, 25.6, 49.5},
        {"Afrika Selatan", 64.7, 7.1, 11.0},
        {"Somalia", 15.9, 4.3, 27.0},
        {"Chad", 27.6, 4.7, 17.0},
        {"Madagaskar", 30.3, 1.5, 5.0},
        {"Mozambik", 33.0, 3.3, 10.0},
        {"Zimbabwe", 15.0, 3.0, 20.0},
        {"Burkina Faso", 21.0, 2.7, 12.9},
        {"Rep. Afrika Tengah", 6.6, 2.3, 34.8},
        {"Mali", 21.7, 2.6, 12.0},
        {"Malawi", 20.0, 4.4, 22.0},
        {"Niger", 25.3, 4.3, 17.0}
    };
     


struct Donatur {
    char nama[50];
    int umur;   
    enum benua Benuaasal;
    char negaraasal[50];
    char nomorkependudukan[20];
    int kodetelepon;
    struct Donasi Brgdonasi;
    struct ABCOrang org;
};

struct KodeTeleponBenua *Mengkopidaftar(struct KodeTeleponBenua *Benuaasalkamu, int jumlah) {
    struct KodeTeleponBenua *Negarakamu = malloc(jumlah * sizeof(struct KodeTeleponBenua));
    if (Negarakamu == NULL) {
        printf("Allocation Failed\n");
        exit(1);
    }
    memcpy(Negarakamu, Benuaasalkamu, jumlah * sizeof(struct KodeTeleponBenua));
    return Negarakamu;
}

int validasiNegara(char *InputNegara,struct KodeTeleponBenua *daftar,int jumlahnegara,char *negaraHasil, int *Outputan) 
{
    char Inputan[50];
    printf("\n%s", InputNegara);
    fgets(Inputan, sizeof(Inputan), stdin);
   Inputan[strcspn(Inputan, "\n")] = '\0';

    for (int j = 0; j < jumlahnegara; j++) {
        if (strcmp(daftar[j].nama, Inputan) == 0) {
            printf("Negara Valid\n");
            strcpy(negaraHasil, Inputan);
            *Outputan = daftar[j].kodetelepon;
            return 1;
        }
    }

    return 0; 
}

void mosthunger(NegaraAfrika *data, int *Tertinggi1, int *Tertinggi2, int *Tertinggi3) {
    *Tertinggi1 = 0;
    *Tertinggi2 = 1;
    *Tertinggi3 = 2;


    if (data[*Tertinggi1].kelaparan_juta < data[*Tertinggi2].kelaparan_juta) {
        int temp = *Tertinggi1; *Tertinggi1 = *Tertinggi2; *Tertinggi2 = temp;
    }
    if (data[*Tertinggi2].kelaparan_juta < data[*Tertinggi3].kelaparan_juta) {
        int temp = *Tertinggi2; *Tertinggi2 = *Tertinggi3; *Tertinggi3 = temp;
    }
    if (data[*Tertinggi1].kelaparan_juta < data[*Tertinggi2].kelaparan_juta) {
        int temp = *Tertinggi1; *Tertinggi1 = *Tertinggi2; *Tertinggi2 = temp;
    }

    
    for (int i = 3; i < 15; i++) {
        if (data[i].kelaparan_juta > data[*Tertinggi1].kelaparan_juta) {
            *Tertinggi3 = *Tertinggi2;
            *Tertinggi2 = *Tertinggi1;
            *Tertinggi1 = i;
        } else if (data[i].kelaparan_juta > data[*Tertinggi2].kelaparan_juta) {
            *Tertinggi3 = *Tertinggi2;
            *Tertinggi2 = i;
        } else if (data[i].kelaparan_juta > data[*Tertinggi3].kelaparan_juta) {
            *Tertinggi3 = i;
        }
    }
    int T1, T2, T3;


  
}

void inisialisasiABC(struct ABC *data) {
    memset(data, 0, sizeof(struct ABC));
}


void inisialisasiSisa(struct sisa *data) {
    memset(data, 0, sizeof(struct sisa));
}


int main() {
 
    int CekAsia=45,CekEropa=45,CekAfrika=55,CekAmerika=40,CekAustralia=1,CekOseania=15;
    
     NegaraAfrika data[15] = {
        {"Nigeria", 237.5, 31.8, 13.4},
        {"Rep. Dem. Kongo", 112.8, 23.4, 20.7},
        {"Ethiopia", 135.5, 15.8, 11.7},
        {"Sudan", 51.7, 25.6, 49.5},
        {"Afrika Selatan", 64.7, 7.1, 11.0},
        {"Somalia", 15.9, 4.3, 27.0},
        {"Chad", 27.6, 4.7, 17.0},
        {"Madagaskar", 30.3, 1.5, 5.0},
        {"Mozambik", 33.0, 3.3, 10.0},
        {"Zimbabwe", 15.0, 3.0, 20.0},
        {"Burkina Faso", 21.0, 2.7, 12.9},
        {"Rep. Afrika Tengah", 6.6, 2.3, 34.8},
        {"Mali", 21.7, 2.6, 12.0},
        {"Malawi", 20.0, 4.4, 22.0},
        {"Niger", 25.3, 4.3, 17.0}
    };
    
   
  
struct KodeTeleponBenua asia[50] = {
    {"Afghanistan",93},{"Armenia",374},{"Azerbaijan",994},{"Bahrain",973},{"Bangladesh",880},{"Bhutan",975},{"Brunei", 673},{"Cambodia",855},{"China", 86},{"Cyprus", 357},{"Georgia", 995},{"India", 91},{"Indonesia", 62},{"Iran", 98},{"Iraq", 964},{"Israel", 972},{"Japan", 81},{"Jordan", 962},{"Kazakhstan", 7},{"Kuwait", 965},{"Kyrgyzstan", 996},{"Laos", 856},{"Lebanon", 961},{"Malaysia", 60},{"Maldives", 960},{"Mongolia", 976},{"Myanmar (Burma)", 95},{"Nepal", 977},{"North Korea", 850},{"Oman", 968},{"Pakistan", 92},{"Palestine", 970},{"Philippines", 63},{"Qatar", 974},{"Saudi Arabia", 966},{"Singapore", 65},{"South Korea",82},{"Sri Lanka",94},{"Syria",963},{"Tajikistan",992},{"Thailand",66},{"Timor-Leste",670},{"Turkey",90},{"Turkmenistan",993},{"United Arab Emirates",971},{"Uzbekistan",998},{"Vietnam",84}
};

struct KodeTeleponBenua *Asia = Mengkopidaftar(asia, CekAsia);

struct KodeTeleponBenua eropa[45] = {
    {"Albania", 355}, {"Andorra", 376}, {"Austria", 43}, {"Belarus", 375},
    {"Belgium", 32}, {"Bosnia and Herzegovina", 387}, {"Bulgaria", 359}, {"Croatia", 385},
    {"Czech Republic", 420}, {"Denmark", 45}, {"Estonia", 372}, {"Finland", 358},
    {"France", 33}, {"Germany", 49}, {"Greece", 30}, {"Hungary", 36},
    {"Iceland", 354}, {"Ireland", 353}, {"Italy", 39}, {"Kosovo", 383},  // if applicable
    {"Latvia", 371}, {"Liechtenstein", 423}, {"Lithuania", 370}, {"Luxembourg", 352},
    {"Malta", 356}, {"Moldova", 373}, {"Monaco", 377}, {"Montenegro", 382},
    {"Netherlands", 31}, {"North Macedonia", 389}, {"Norway", 47}, {"Poland", 48},
    {"Portugal", 351}, {"Romania", 40}, {"Russia", 7}, {"San Marino", 378},
    {"Serbia", 381}, {"Slovakia", 421}, {"Slovenia", 386}, {"Spain", 34},
    {"Sweden", 46}, {"Switzerland", 41}, {"Ukraine", 380}, {"United Kingdom", 44},
    {"Vatican City", 379}
};
struct KodeTeleponBenua *Eropa = Mengkopidaftar(eropa, CekEropa);

struct KodeTeleponBenua afrika[55] = {
    {"Algeria", 213}, {"Angola", 244}, {"Benin", 229}, {"Botswana", 267},
    {"Burkina Faso", 226}, {"Burundi", 257}, {"Cabo Verde", 238}, {"Cameroon", 237},
    {"Central African Republic", 236}, {"Chad", 235}, {"Comoros", 269}, {"Congo (Congo-Brazzaville)", 242},
    {"Democratic Republic of the Congo", 243}, {"Djibouti", 253}, {"Egypt", 20}, {"Equatorial Guinea", 240},
    {"Eritrea", 291}, {"Eswatini", 268}, {"Ethiopia", 251}, {"Gabon", 241},
    {"Gambia", 220}, {"Ghana", 233}, {"Guinea", 224}, {"Guinea-Bissau", 245},
    {"Ivory Coast", 225}, {"Kenya", 254}, {"Lesotho", 266}, {"Liberia", 231},
    {"Libya", 218}, {"Madagascar", 261}, {"Malawi", 265}, {"Mali", 223},
    {"Mauritania", 222}, {"Mauritius", 230}, {"Morocco", 212}, {"Mozambique", 258},
    {"Namibia", 264}, {"Niger", 227}, {"Nigeria", 234}, {"Rwanda", 250},
    {"Sao Tome and Principe", 239}, {"Senegal", 221}, {"Seychelles", 248}, {"Sierra Leone", 232},
    {"Somalia", 252}, {"South Africa", 27}, {"South Sudan", 211}, {"Sudan", 249},
    {"Tanzania", 255}, {"Togo", 228}, {"Tunisia", 216}, {"Uganda", 256},
    {"Zambia", 260}, {"Zimbabwe", 263}
};

struct KodeTeleponBenua *Afrika = Mengkopidaftar(afrika, CekAfrika);


struct KodeTeleponBenua amerika[40] = {
    {"Antigua and Barbuda", 1}, {"Argentina", 54}, {"Bahamas", 1}, {"Barbados", 1},
    {"Belize", 501}, {"Bolivia", 591}, {"Brazil", 55}, {"Canada", 1},
    {"Chile", 56}, {"Colombia", 57}, {"Costa Rica", 506}, {"Cuba", 53},
    {"Dominica", 1}, {"Dominican Republic", 1}, {"Ecuador", 593}, {"El Salvador", 503},
    {"Grenada", 1}, {"Guatemala", 502}, {"Guyana", 592}, {"Haiti", 509},
    {"Honduras", 504}, {"Jamaica", 1}, {"Mexico", 52}, {"Nicaragua", 505},
    {"Panama", 507}, {"Paraguay", 595}, {"Peru", 51}, {"Saint Kitts and Nevis", 1},
    {"Saint Lucia", 1}, {"Saint Vincent and the Grenadines", 1}, {"Suriname", 597}, {"Trinidad and Tobago", 1},
    {"United States", 1}, {"Uruguay", 598}, {"Venezuela", 58}
};

struct KodeTeleponBenua *Amerika = Mengkopidaftar(amerika, CekAmerika);

struct KodeTeleponBenua australia[1] = {
    {"Australia", 61}
};
   

struct KodeTeleponBenua *Australia = Mengkopidaftar(australia, CekAustralia);

struct KodeTeleponBenua oseania[13] = {
    {"Fiji", 679}, {"Kiribati", 686}, {"Marshall Islands", 692}, {"Micronesia", 691},
    {"Nauru", 674}, {"New Zealand", 64}, {"Palau", 680}, {"Papua New Guinea", 675},
    {"Samoa", 685}, {"Solomon Islands", 677}, {"Tonga", 676}, {"Tuvalu", 688},
    {"Vanuatu", 678}
};
struct KodeTeleponBenua *Oceania = Mengkopidaftar(oseania, CekOseania);

int Donaturloop=0;    
printf("=====ZERO HUNGER FOR AFRICA=====\n"); 
printf("Jumlah Donatur(Sebutkan jumlah Individu yang ingin mendonasikan):  ");
scanf("%d",&Donaturloop);
getchar(); 

struct Donatur *donatur = malloc(Donaturloop * sizeof(struct Donatur));


for (int i=0;i<Donaturloop;i++) {
    
donatur[i].Brgdonasi.beras.jumlahKgberas = 0;
donatur[i].Brgdonasi.beras.jumlahBuahberas = 0;
donatur[i].Brgdonasi.snack.jumlahKgsnack = 0;
donatur[i].Brgdonasi.snack.jumlahBuahsnack = 0;
donatur[i].Brgdonasi.suple.jumlahKgsuple = 0;
donatur[i].Brgdonasi.suple.jumlahBuahsuple = 0;
donatur[i].Brgdonasi.daging.jumlahKgdaging = 0;
donatur[i].Brgdonasi.sayur.jumlahKgsayur = 0;
donatur[i].Brgdonasi.sayur.jumlahBuahsayur = 0;

printf("\n----------------------------------\n");
printf("Kamu adalah Donatur ke -%d \n",i+1);

int namavalid=0;
do {
    printf("\n");
    printf("Nama:"); 
    fgets(donatur[i].nama, sizeof(donatur[i].nama), stdin);
   if (strchr(donatur[i].nama, '\n') == NULL) {
                printf("Maksimal 50 karakter\n");
                
                while (getchar() != '\n');
            } 
    else { donatur[i].nama[strcspn(donatur[i].nama, "\n")] = '\0';
    namavalid+=1;
    }
    } while(namavalid!=1);
    
int umurvalid=0;  
do {
printf("\n");
printf("Umur:"); 
scanf("%d",&donatur[i].umur);
while(getchar() != '\n');

if(donatur[i].umur<17&&donatur[i].umur>0){ 
    printf("Maaf , anda belum cukup umur untuk donasi");
    continue;
}
else if(donatur[i].umur>=17){umurvalid+=1; }
else {
    printf("Masukkan umur yang valid");
}
}while(umurvalid!=1); 

printf("\n");
printf("Benua asal\n[0]Amerika \n[1]Asia \n[2]Australia \n[3]Afrika \n[4]Eropa \n[5]Oseania \nPilihan: "); 
scanf("%d",&donatur[i].Benuaasal); 
while(getchar() != '\n');


switch(donatur[i].Benuaasal){ 
  
   case BenuaAmerika:
        while (validasiNegara("Negara asal (Masukkan dalam bahasa Inggris): ", Amerika, CekAmerika, donatur[i].negaraasal, &donatur[i].kodetelepon)!=1) {
            printf("Negara tidak ditemukan di daftar Amerika. Silakan coba lagi.\n"); 
        }
        break;

  case BenuaAsia:
     while (validasiNegara("Negara asal (Masukkan dalam bahasa Inggris): ", Asia, CekAsia, donatur[i].negaraasal, &donatur[i].kodetelepon) != 1) {
            printf("Negara tidak ditemukan di daftar Asia. Silakan coba lagi.\n");
        }
        break;

    case BenuaAustralia:
        while (validasiNegara("Negara asal (Masukkan dalam bahasa Inggris): ", Australia, CekAustralia, donatur[i].negaraasal, &donatur[i].kodetelepon)!=1) {
            printf("Negara tidak ditemukan di daftar Australia. Silakan coba lagi\n");
        }
        break;

    case BenuaAfrika:
        while (validasiNegara("Negara asal (Masukkan dalam bahasa Inggris): ", Afrika, CekAfrika, donatur[i].negaraasal, &donatur[i].kodetelepon)!=1){
            printf("Negara tidak ditemukan di daftar Afrika. Silakan coba lagi\n");
        }
        break;

    case BenuaEropa:
        while (validasiNegara("Negara asal (Masukkan dalam bahasa Inggris): ", Eropa, CekEropa, donatur[i].negaraasal, &donatur[i].kodetelepon)!=1)
        {
            printf("Negara tidak ditemukan di daftar Eropa. Silakan coba lagi\n");
        }
        break;

    case BenuaOseania:
        while (validasiNegara("Negara asal (Masukkan dalam bahasa Inggris): ", Oceania, CekOseania, donatur[i].negaraasal, &donatur[i].kodetelepon)!=1)
        {
            printf("Negara tidak ditemukan di daftar Oseania. Silakan coba lagi\n");
        }
            
        break;
           

    default:
        printf("Pilihan benua tidak valid.\n");
        i--;
        break;
};
printf("\n");
int IDvalid=0;
do { 
    
printf("Nomor Kependudukan Donatur:    "); 
fgets(donatur[i].nomorkependudukan,sizeof(donatur[i].nomorkependudukan),stdin); 
   if (strchr(donatur[i].nomorkependudukan, '\n') == NULL) {
                printf("Maksimal 20 karakter\n");
                
                while (getchar() != '\n');
            } 
    else { donatur[i].nomorkependudukan[strcspn(donatur[i].nomorkependudukan, "\n")] = '\0';
    IDvalid+=1;
    }
    } while(IDvalid!=1);
    

donatur[i].nomorkependudukan[strcspn(donatur[i].nomorkependudukan, "\n")] = '\0';

printf("\n=====DONASI YANG INGIN DISUMBANGKAN=====\n"); 


  int Donatingloop=0;
do {
  
printf("Bahan-bahan yang ingin didonasikan:\n[0]Beras dan Bahan Baku \n[1]Makanan Ringan \n[2]Suplemen \n[3]Olahan Hewan \n[4]Sayur dan Buah \nPilihanmu: "); 
scanf("%d",&donatur[i].Brgdonasi.barang); 
switch(donatur[i].Brgdonasi.barang)
{
case Beras_dan_bahan_baku: 
while (getchar() != '\n') {
 
}
printf("\nNama/Jenis/Dekripsi pendek mengenai bahan baku yang ingin didonasikan:  "); 
fgets(donatur[i].Brgdonasi.ItemName.namaberas,sizeof(donatur[i].Brgdonasi.ItemName.namaberas),stdin); 
donatur[i].Brgdonasi.ItemName.namaberas[strcspn(donatur[i].Brgdonasi.ItemName.namaberas, "\n")] = '\0';


printf("\nJumlah %s yang ingin didonasikan (Dalam Kg; Apabila bentuknya dalam Buah , maka ketik saja 0: ",donatur[i].Brgdonasi.ItemName.namaberas); 


scanf("%d",&donatur[i].Brgdonasi.beras.jumlahKgberas);
while ((getchar()) != '\n'); 

printf("\nJumlah %s yang ingin didonasikan (Dalam Karung (5 Kilogram); Apabila bentuknya dalam Kg , maka ketik saja 0: ",donatur[i].Brgdonasi.ItemName.namaberas); 

scanf("%d",&donatur[i].Brgdonasi.beras.jumlahBuahberas);
while ((getchar()) != '\n'); 
   
break;

case Makanan_Ringan:
while (getchar() != '\n') {
 
}
printf("\nNama/Jenis/Dekripsi pendek mengenai makanan ringan yang ingin didonasikan:  "); 
fgets(donatur[i].Brgdonasi.ItemName.namasnack,sizeof(donatur[i].Brgdonasi.ItemName.namasnack),stdin); 
donatur[i].Brgdonasi.ItemName.namasnack[strcspn(donatur[i].Brgdonasi.ItemName.namasnack, "\n")] = '\0';

printf("\nJumlah %s yang ingin didonasikan (Dalam Kg; Apabila bentuknya dalam Buah , maka ketik saja 0: ",donatur[i].Brgdonasi.ItemName.namasnack); 

scanf("%d",&donatur[i].Brgdonasi.snack.jumlahKgsnack);
while ((getchar()) != '\n'); 

printf("\nJumlah %s yang ingin didonasikan (Dalam Pcs (70 Gram); Apabila bentuknya dalam Kg , maka ketik saja 0: ",donatur[i].Brgdonasi.ItemName.namasnack); 
scanf("%d",&donatur[i].Brgdonasi.snack.jumlahBuahsnack);
while ((getchar()) != '\n'); 

break;

case Suplemen: 
while (getchar() != '\n') {
 
}
printf("\nNama/Jenis/Dekripsi pendek mengenai suplemen yang ingin didonasikan:  "); 
fgets(donatur[i].Brgdonasi.ItemName.namasuple,sizeof(donatur[i].Brgdonasi.ItemName.namasuple),stdin); 
donatur[i].Brgdonasi.ItemName.namasuple[strcspn(donatur[i].Brgdonasi.ItemName.namasuple, "\n")] = '\0';
printf("\nJumlah %s yang ingin didonasikan (Dalam Kg; Apabila bentuknya dalam Buah , maka ketik saja 0: ",donatur[i].Brgdonasi.ItemName.namasuple); 

scanf("%d",&donatur[i].Brgdonasi.suple.jumlahKgsuple);
while ((getchar()) != '\n'); 

printf("\nJumlah %s yang ingin didonasikan (Dalam Sachet (40 Gram); Apabila bentuknya dalam Kg , maka ketik saja 0: ",donatur[i].Brgdonasi.ItemName.namasuple); 
scanf("%d",&donatur[i].Brgdonasi.suple.jumlahBuahsuple);
while ((getchar()) != '\n'); 
   
break;

case Olahan_hewan: 
while (getchar() != '\n') {
 
}
printf("\nNama/Jenis/Dekripsi pendek mengenai makanan olahan hewan yang ingin didonasikan:  "); 
fgets(donatur[i].Brgdonasi.ItemName.namahewan,sizeof(donatur[i].Brgdonasi.ItemName.namahewan),stdin); 
donatur[i].Brgdonasi.ItemName.namahewan[strcspn(donatur[i].Brgdonasi.ItemName.namahewan, "\n")] = '\0';
printf("\nJumlah %s yang ingin didonasikan (Dalam Kg; Hanya dalam bentuk Kg: ",donatur[i].Brgdonasi.ItemName.namahewan); 

scanf("%d",&donatur[i].Brgdonasi.daging.jumlahKgdaging);
while ((getchar()) != '\n'); 

   
break;

case Sayur_dan_buah: 
while (getchar() != '\n') {
 
}
printf("\nNama/Jenis/Dekripsi pendek mengenai sayur atau buah yang ingin didonasikan:  "); 
fgets(donatur[i].Brgdonasi.ItemName.namasayur,sizeof(donatur[i].Brgdonasi.ItemName.namasayur),stdin); 
donatur[i].Brgdonasi.ItemName.namasayur[strcspn(donatur[i].Brgdonasi.ItemName.namasayur, "\n")] = '\0';

printf("\nJumlah %s yang ingin didonasikan (Dalam Kg; Apabila bentuknya dalam Buah , maka ketik saja 0: ",donatur[i].Brgdonasi.ItemName.namasayur); 

scanf("%d",&donatur[i].Brgdonasi.sayur.jumlahKgsayur);
while ((getchar()) != '\n'); 

printf("\nJumlah %s yang ingin didonasikan (Dalam Buah (150 Gram); Apabila bentuknya dalam Kg , maka ketik saja 0: ",donatur[i].Brgdonasi.ItemName.namasayur); 
scanf("%d",&donatur[i].Brgdonasi.sayur.jumlahBuahsayur);
while ((getchar()) != '\n'); 
break;

default:
        printf("Pilihan donasi tidak valid.\n");
        i--;
        break;

}

char DonaturChoice[6];
int Choicevalid=0;
do { 
    ;
printf("\nApakah ingin mendonasikan yang lain? (Ya/Tidak) *Ketik sesuai petunjuk: ");
fgets(DonaturChoice,sizeof(DonaturChoice),stdin);
DonaturChoice[strcspn(DonaturChoice, "\n")] = '\0';
getchar();

if(strcmp(DonaturChoice,"Ya")==0){
    Choicevalid+=1;
    
}
    else if(strcmp(DonaturChoice,"Tidak")==0){ 
        Donatingloop+=1;
         Choicevalid+=1;
    } 
    else {  printf("Masukan tidak valid. Ketik 'Ya' atau 'Tidak'.\n");
    }
    
}while(Choicevalid!=1);
 
  }while(Donatingloop!=1);
};

 float persentase_A = 0.45;
 float persentase_B = 0.35;
 float persentase_C = 0.20;
 
printf("\n====Ringkasan Donasi untuk program  ZERO HUNGER FOR AFRICA====\n"); 


for (int i=0;i<Donaturloop;i++)
{ 
printf("\nData Donatur %d:\n", i+1);
printf("Nama: %s\n", donatur[i].nama);
printf("Umur: %d\n", donatur[i].umur);
printf("Negara Asal: %s\n", donatur[i].negaraasal);
printf("Kode Telepon: +%d\n", donatur[i].kodetelepon);
printf("Nomor Kependudukan: %s\n", donatur[i].nomorkependudukan);
printf("Donasi: \n"); 
            if(donatur[i].Brgdonasi.ItemName.namaberas[0] !='\0') {
            printf("--------\n");
            printf("%s\n", donatur[i].Brgdonasi.ItemName.namaberas);
            if (donatur[i].Brgdonasi.beras.jumlahKgberas > 0) {
                printf("Jumlah (Kg): %d Kg\n", donatur[i].Brgdonasi.beras.jumlahKgberas); }
            if (donatur[i].Brgdonasi.beras.jumlahBuahberas > 0) {
                printf("Jumlah (Karung): %d Karung\n", donatur[i].Brgdonasi.beras.jumlahBuahberas); } 
            }
          

           if(donatur[i].Brgdonasi.ItemName.namasnack[0] !='\0') {
            printf("--------\n");
            printf("%s\n", donatur[i].Brgdonasi.ItemName.namasnack);
            if (donatur[i].Brgdonasi.snack.jumlahKgsnack > 0) {
                printf("Jumlah (Kg): %d Kg\n", donatur[i].Brgdonasi.snack.jumlahKgsnack); }
            if (donatur[i].Brgdonasi.snack.jumlahBuahsnack > 0) {
                printf("Jumlah (Pcs): %d Pcs\n", donatur[i].Brgdonasi.snack.jumlahBuahsnack); } 
           }
      

       
           if(donatur[i].Brgdonasi.ItemName.namasuple[0] !='\0') {
            printf("--------\n");
            printf("%s\n", donatur[i].Brgdonasi.ItemName.namasuple);
            if (donatur[i].Brgdonasi.suple.jumlahKgsuple > 0) {
                printf("Jumlah (Kg): %d Kg\n", donatur[i].Brgdonasi.suple.jumlahKgsuple);}
            if (donatur[i].Brgdonasi.suple.jumlahBuahsuple > 0) {
                printf("Jumlah (Sachet): %d Sachet \n", donatur[i].Brgdonasi.suple.jumlahBuahsuple); } 
           }
       

       
           if(donatur[i].Brgdonasi.ItemName.namahewan[0] !='\0') {
            printf("--------\n");
            printf("%s\n", donatur[i].Brgdonasi.ItemName.namahewan);
            if (donatur[i].Brgdonasi.daging.jumlahKgdaging > 0) {
                printf("Jumlah (Kg): %d Kg \n", donatur[i].Brgdonasi.daging.jumlahKgdaging); }
          
           }
           

       
           if(donatur[i].Brgdonasi.ItemName.namasayur[0] !='\0'){
            printf("--------\n");
            printf("%s\n", donatur[i].Brgdonasi.ItemName.namasayur);
            if (donatur[i].Brgdonasi.sayur.jumlahKgsayur > 0) {
                printf("Jumlah (Kg): %d Kg\n", donatur[i].Brgdonasi.sayur.jumlahKgsayur); }
            if (donatur[i].Brgdonasi.sayur.jumlahBuahsayur > 0) {
                printf("Jumlah (Buah): %d Buah\n", donatur[i].Brgdonasi.sayur.jumlahBuahsayur); } 
           }
     
printf("\n");
 char kodePengiriman[20] = "";  
 int LenID = strlen(donatur[i].nomorkependudukan); 
int digit1 = donatur[i].nomorkependudukan[LenID - 3] - '0';
int digit2 = donatur[i].nomorkependudukan[LenID - 2] - '0';
int digit3 = donatur[i].nomorkependudukan[LenID - 1] - '0';

int tigadigitID = digit1 * 100 + digit2 * 10 + digit3;

   

    strcpy(kodePengiriman, "2025");

    int LenNama = strlen(kodePengiriman);
    kodePengiriman[LenNama] = toupper(donatur[i].nama[0]);
    kodePengiriman[LenNama + 1] = '\0';

    char kodetelpPengiriman[5];
    sprintf(kodetelpPengiriman, "%d", donatur[i].kodetelepon);
    strcat(kodePengiriman, kodetelpPengiriman);

    
    char tigadigitIDPengiriman[4];
    sprintf(tigadigitIDPengiriman, "%03d", tigadigitID);
    strcat(kodePengiriman, tigadigitIDPengiriman);

    
    strcat(kodePengiriman, "0");

   
    char indeksPengiriman[5];
    sprintf(indeksPengiriman, "%d", i+1);
    strcat(kodePengiriman, indeksPengiriman);

printf("Kode Pengiriman donatur ke %d:%s \n",i+1,kodePengiriman);




}

 int Tertinggi1 = 0, Tertinggi2 = 1, Tertinggi3 = 2;
      
 mosthunger(data, &Tertinggi1, &Tertinggi2, &Tertinggi3); 
 printf("Donasi kamu akan disumbangkan ke negara: %s, %s, %s \n",data[Tertinggi1].nama,data[Tertinggi2].nama,data[Tertinggi3].nama);
 
 float wargalaper_A=data[Tertinggi1].kelaparan_juta*1000000;
 float wargalaper_B=data[Tertinggi2].kelaparan_juta*1000000;
 float wargalaper_C=data[Tertinggi2].kelaparan_juta*1000000;

for (int i=0;i<Donaturloop;i++) { 
donatur[i].org.orangA=0; 
donatur[i].org.orangB=0; 
donatur[i].org.orangC=0; 

donatur[i].Brgdonasi.Bagi.AkumulasiKgBerasA = donatur[i].Brgdonasi.beras.jumlahKgberas * persentase_A;
donatur[i].Brgdonasi.Bagi.AkumulasiKgBerasB = donatur[i].Brgdonasi.beras.jumlahKgberas * persentase_B;
donatur[i].Brgdonasi.Bagi.AkumulasiKgBerasC =  donatur[i].Brgdonasi.beras.jumlahKgberas * persentase_C;
   
donatur[i].Brgdonasi.Bagi.AkumulasiKrgBerasA = donatur[i].Brgdonasi.beras.jumlahBuahberas * persentase_A;
donatur[i].Brgdonasi.Bagi.AkumulasiKrgBerasB= donatur[i].Brgdonasi.beras.jumlahBuahberas* persentase_B;
donatur[i].Brgdonasi.Bagi.AkumulasiKrgBerasC =  donatur[i].Brgdonasi.beras.jumlahBuahberas* persentase_C;            
    if(donatur[i].Brgdonasi.ItemName.namaberas[0] !='\0') {
        
donatur[i].Brgdonasi.Bagi.AkumulasiKgBerasA  += donatur[i].Brgdonasi.Bagi.AkumulasiKrgBerasA*5;
int temp = (int)donatur[i].Brgdonasi.Bagi.AkumulasiKgBerasA ;  
donatur[i].org.orangA += temp;
donatur[i].Brgdonasi.Sisa.SisaBerasA += donatur[i].Brgdonasi.Bagi.AkumulasiKgBerasA  - temp;

if (donatur[i].Brgdonasi.Sisa.SisaBerasA >= 0.5) {
    donatur[i].org.orangA+= 1;
     
    }
wargalaper_A -= donatur[i].org.orangA;

donatur[i].Brgdonasi.Bagi.AkumulasiKgBerasB  += donatur[i].Brgdonasi.Bagi.AkumulasiKrgBerasB*5;
int temp2 = (int)donatur[i].Brgdonasi.Bagi.AkumulasiKgBerasB;   
donatur[i].org.orangB += temp2;
donatur[i].Brgdonasi.Sisa.SisaBerasB += donatur[i].Brgdonasi.Bagi.AkumulasiKgBerasB  - temp2;

if (donatur[i].Brgdonasi.Sisa.SisaBerasB >= 0.5) {
    donatur[i].org.orangB+= 1;
     
    }
wargalaper_B -= donatur[i].org.orangB;
    

int temp3= (int)donatur[i].Brgdonasi.Bagi.AkumulasiKgBerasC ; 
donatur[i].org.orangC+=temp3;
donatur[i].Brgdonasi.Sisa.SisaBerasC += donatur[i].Brgdonasi.Bagi.AkumulasiKgBerasC  - temp3;

if (donatur[i].Brgdonasi.Sisa.SisaBerasC >= 0.5) {
    donatur[i].org.orangC+= 1;
     
    }
wargalaper_C -= donatur[i].org.orangC;
  
    }

donatur[i].Brgdonasi.Bagi.AkumulasiKgSnackA = donatur[i].Brgdonasi.snack.jumlahKgsnack * persentase_A;
donatur[i].Brgdonasi.Bagi.AkumulasiKgSnackB = donatur[i].Brgdonasi.snack.jumlahKgsnack * persentase_B;
donatur[i].Brgdonasi.Bagi.AkumulasiKgSnackC = donatur[i].Brgdonasi.snack.jumlahKgsnack * persentase_C;

donatur[i].Brgdonasi.Bagi.AkumulasiPcsSnackA = donatur[i].Brgdonasi.snack.jumlahBuahsnack * persentase_A;
donatur[i].Brgdonasi.Bagi.AkumulasiPcsSnackB = donatur[i].Brgdonasi.snack.jumlahBuahsnack * persentase_B;
donatur[i].Brgdonasi.Bagi.AkumulasiPcsSnackC = donatur[i].Brgdonasi.snack.jumlahBuahsnack * persentase_C;

if (donatur[i].Brgdonasi.ItemName.namasnack[0] != '\0') {
    float snack_per_orang = 0.07;
    

    donatur[i].Brgdonasi.Bagi.AkumulasiKgSnackA += 0.07 * donatur[i].Brgdonasi.Bagi.AkumulasiPcsSnackA;
    donatur[i].Brgdonasi.Bagi.AkumulasiKgSnackB += 0.07 * donatur[i].Brgdonasi.Bagi.AkumulasiPcsSnackB;
    donatur[i].Brgdonasi.Bagi.AkumulasiKgSnackC += 0.07 * donatur[i].Brgdonasi.Bagi.AkumulasiPcsSnackC;
    
int temp1 = (int)(donatur[i].Brgdonasi.Bagi.AkumulasiKgSnackA / snack_per_orang);
 donatur[i].org.orangA += temp1;
donatur[i].Brgdonasi.Sisa.SisaSnackA += donatur[i].Brgdonasi.Bagi.AkumulasiKgSnackA - (temp1 * snack_per_orang);
if (donatur[i].Brgdonasi.Sisa.SisaSnackA >= snack_per_orang / 2) {
    donatur[i].org.orangA += 1;
}

int temp2 = (int)(donatur[i].Brgdonasi.Bagi.AkumulasiKgSnackB / snack_per_orang);
 donatur[i].org.orangB += temp2;
donatur[i].Brgdonasi.Sisa.SisaSnackB += donatur[i].Brgdonasi.Bagi.AkumulasiKgSnackB - (temp2 * snack_per_orang);
if (donatur[i].Brgdonasi.Sisa.SisaSnackB >= snack_per_orang / 2) {
    donatur[i].org.orangB += 1;
}


int temp3 = (int)(donatur[i].Brgdonasi.Bagi.AkumulasiKgSnackC / snack_per_orang);
 donatur[i].org.orangC += temp3;
donatur[i].Brgdonasi.Sisa.SisaSnackC += donatur[i].Brgdonasi.Bagi.AkumulasiKgSnackC - (temp3 * snack_per_orang);
if (donatur[i].Brgdonasi.Sisa.SisaSnackC >= snack_per_orang / 2) {
    donatur[i].org.orangC += 1;
 }
}

donatur[i].Brgdonasi.Bagi.AkumulasiKgSupleA = donatur[i].Brgdonasi.suple.jumlahKgsuple * persentase_A;
donatur[i].Brgdonasi.Bagi.AkumulasiKgSupleB = donatur[i].Brgdonasi.suple.jumlahKgsuple * persentase_B;
donatur[i].Brgdonasi.Bagi.AkumulasiKgSupleC = donatur[i].Brgdonasi.suple.jumlahKgsuple * persentase_C;

donatur[i].Brgdonasi.Bagi.AkumulasiSctSupleA = donatur[i].Brgdonasi.suple.jumlahBuahsuple * persentase_A;
donatur[i].Brgdonasi.Bagi.AkumulasiSctSupleB = donatur[i].Brgdonasi.suple.jumlahBuahsuple * persentase_B;
donatur[i].Brgdonasi.Bagi.AkumulasiSctSupleC = donatur[i].Brgdonasi.suple.jumlahBuahsuple * persentase_C;

if (donatur[i].Brgdonasi.ItemName.namasuple[0] != '\0') {
    float suple_per_orang = 0.04;

    donatur[i].Brgdonasi.Bagi.AkumulasiKgSupleA += 0.04 * donatur[i].Brgdonasi.Bagi.AkumulasiSctSupleA;
    donatur[i].Brgdonasi.Bagi.AkumulasiKgSupleB += 0.04 * donatur[i].Brgdonasi.Bagi.AkumulasiSctSupleB;
    donatur[i].Brgdonasi.Bagi.AkumulasiKgSupleC += 0.04 * donatur[i].Brgdonasi.Bagi.AkumulasiSctSupleC;
int temp1 = (int)(donatur[i].Brgdonasi.Bagi.AkumulasiKgSupleA / suple_per_orang);
    donatur[i].org.orangA += temp1;
    donatur[i].Brgdonasi.Sisa.SisaSupleA += donatur[i].Brgdonasi.Bagi.AkumulasiKgSupleA - (temp1* suple_per_orang);
    if (donatur[i].Brgdonasi.Sisa.SisaSupleA >= suple_per_orang / 2) {
        donatur[i].org.orangA += 1;
    }
int temp2 = (int)(donatur[i].Brgdonasi.Bagi.AkumulasiKgSupleB / suple_per_orang);
    donatur[i].org.orangB += temp2;
    donatur[i].Brgdonasi.Sisa.SisaSupleB += donatur[i].Brgdonasi.Bagi.AkumulasiKgSupleB - (temp2 * suple_per_orang);
    if (donatur[i].Brgdonasi.Sisa.SisaSupleB >= suple_per_orang / 2) {
        donatur[i].org.orangB += 1;
    }
int temp3 = (int)(donatur[i].Brgdonasi.Bagi.AkumulasiKgSupleC / suple_per_orang);
    donatur[i].org.orangC += temp3;
    donatur[i].Brgdonasi.Sisa.SisaSupleC += donatur[i].Brgdonasi.Bagi.AkumulasiKgSupleC - (temp3 * suple_per_orang);
    if (donatur[i].Brgdonasi.Sisa.SisaSupleC >= suple_per_orang / 2) {
        donatur[i].org.orangC += 1;
    }
}

donatur[i].Brgdonasi.Bagi.AkumulasiKgDagingA = donatur[i].Brgdonasi.daging.jumlahKgdaging * persentase_A;
donatur[i].Brgdonasi.Bagi.AkumulasiKgDagingB = donatur[i].Brgdonasi.daging.jumlahKgdaging * persentase_B;
donatur[i].Brgdonasi.Bagi.AkumulasiKgDagingC = donatur[i].Brgdonasi.daging.jumlahKgdaging * persentase_C;

if (donatur[i].Brgdonasi.ItemName.namahewan[0] != '\0') {
    float daging_per_orang = 0.4;

int temp1 = (int)(donatur[i].Brgdonasi.Bagi.AkumulasiKgDagingA / daging_per_orang);
    donatur[i].org.orangA += temp1;
    donatur[i].Brgdonasi.Sisa.SisaDagingA += donatur[i].Brgdonasi.Bagi.AkumulasiKgDagingA - (temp1 * daging_per_orang);
    if (donatur[i].Brgdonasi.Sisa.SisaDagingA >= daging_per_orang / 2) {
        donatur[i].org.orangA += 1;
    }
int temp2 = (int)(donatur[i].Brgdonasi.Bagi.AkumulasiKgDagingB / daging_per_orang);
    donatur[i].org.orangB += temp2;
    donatur[i].Brgdonasi.Sisa.SisaDagingB += donatur[i].Brgdonasi.Bagi.AkumulasiKgDagingB - (temp2 * daging_per_orang);
    if (donatur[i].Brgdonasi.Sisa.SisaDagingB >= daging_per_orang / 2) {
        donatur[i].org.orangB += 1;
    }
int temp3 = (int)(donatur[i].Brgdonasi.Bagi.AkumulasiKgDagingC / daging_per_orang);
    donatur[i].org.orangC += temp3;
    donatur[i].Brgdonasi.Sisa.SisaDagingC += donatur[i].Brgdonasi.Bagi.AkumulasiKgDagingC - (temp3 * daging_per_orang);
    if (donatur[i].Brgdonasi.Sisa.SisaDagingC >= daging_per_orang / 2) {
        donatur[i].org.orangC += 1;
    }
}

donatur[i].Brgdonasi.Bagi.AkumulasiKgSayurA = donatur[i].Brgdonasi.sayur.jumlahKgsayur * persentase_A;
donatur[i].Brgdonasi.Bagi.AkumulasiKgSayurB = donatur[i].Brgdonasi.sayur.jumlahKgsayur * persentase_B;
donatur[i].Brgdonasi.Bagi.AkumulasiKgSayurC = donatur[i].Brgdonasi.sayur.jumlahKgsayur * persentase_C;

donatur[i].Brgdonasi.Bagi.AkumulasiBuahSayurA = donatur[i].Brgdonasi.sayur.jumlahBuahsayur * persentase_A;
donatur[i].Brgdonasi.Bagi.AkumulasiBuahSayurB = donatur[i].Brgdonasi.sayur.jumlahBuahsayur * persentase_B;
donatur[i].Brgdonasi.Bagi.AkumulasiBuahSayurC = donatur[i].Brgdonasi.sayur.jumlahBuahsayur * persentase_C;

if (donatur[i].Brgdonasi.ItemName.namasayur[0] != '\0') {
    float sayur_per_orang = 0.15;

    donatur[i].Brgdonasi.Bagi.AkumulasiKgSayurA += 0.15 * donatur[i].Brgdonasi.Bagi.AkumulasiBuahSayurA;
    donatur[i].Brgdonasi.Bagi.AkumulasiKgSayurB += 0.15 * donatur[i].Brgdonasi.Bagi.AkumulasiBuahSayurB;
    donatur[i].Brgdonasi.Bagi.AkumulasiKgSayurC += 0.15 * donatur[i].Brgdonasi.Bagi.AkumulasiBuahSayurC;
int temp1 = (int)(donatur[i].Brgdonasi.Bagi.AkumulasiKgSayurA / sayur_per_orang);
    donatur[i].org.orangA += temp1; 
    donatur[i].Brgdonasi.Sisa.SisaSayurA += donatur[i].Brgdonasi.Bagi.AkumulasiKgSayurA - (temp1 * sayur_per_orang);
    if (donatur[i].Brgdonasi.Sisa.SisaSayurA >= sayur_per_orang / 2) {
        donatur[i].org.orangA += 1;
    }
int temp2 = (int)(donatur[i].Brgdonasi.Bagi.AkumulasiKgSayurB / sayur_per_orang);
    donatur[i].org.orangB += temp2;
    donatur[i].Brgdonasi.Sisa.SisaSayurB += donatur[i].Brgdonasi.Bagi.AkumulasiKgSayurB - (temp2 * sayur_per_orang);
    if (donatur[i].Brgdonasi.Sisa.SisaSayurB >= sayur_per_orang / 2) {
        donatur[i].org.orangB += 1;
    }
int temp3 = (int)(donatur[i].Brgdonasi.Bagi.AkumulasiKgSayurC / sayur_per_orang);
    donatur[i].org.orangC += temp3;
    donatur[i].Brgdonasi.Sisa.SisaSayurC += donatur[i].Brgdonasi.Bagi.AkumulasiKgSayurC - (donatur[i].org.orangC * sayur_per_orang);
    if (donatur[i].Brgdonasi.Sisa.SisaSayurC >= sayur_per_orang / 2) {
        donatur[i].org.orangC += 1;
    }
}

printf("Rincian donasi: \n"); 
printf("===============\n"); 
printf("Donasi ke %s \n",data[Tertinggi1].nama); 
if (donatur[i].Brgdonasi.ItemName.namaberas[0] != '\0') {
                printf("Jumlah (Kg) %s: %.2lf\n",donatur[i].Brgdonasi.ItemName.namaberas,donatur[i].Brgdonasi.Bagi.AkumulasiKgBerasA);
}
if (donatur[i].Brgdonasi.ItemName.namasnack[0] != '\0')  {
    
                printf("Jumlah (Kg) %s: %.2lf\n",donatur[i].Brgdonasi.ItemName.namasnack,donatur[i].Brgdonasi.Bagi.AkumulasiKgSnackA); 
}
if (donatur[i].Brgdonasi.ItemName.namasuple[0] != '\0') {
                printf("Jumlah (Kg) %s: %.2lf\n",donatur[i].Brgdonasi.ItemName.namasuple,donatur[i].Brgdonasi.Bagi.AkumulasiKgSupleA); 
}
if (donatur[i].Brgdonasi.ItemName.namahewan[0] != '\0') {

                printf("Jumlah (Kg) %s: %.2lf\n",donatur[i].Brgdonasi.ItemName.namahewan,donatur[i].Brgdonasi.Bagi.AkumulasiKgDagingA); 
}
if (donatur[i].Brgdonasi.ItemName.namasayur[0] != '\0') {

                printf("Jumlah (Kg) %s: %.2lf\n",donatur[i].Brgdonasi.ItemName.namasayur,donatur[i].Brgdonasi.Bagi.AkumulasiKgSayurA);
}

printf("\n");

printf("Donasi ke %s \n",data[Tertinggi2].nama); 
if (donatur[i].Brgdonasi.ItemName.namaberas[0] != '\0') {
                printf("Jumlah (Kg) %s: %.2lf\n",donatur[i].Brgdonasi.ItemName.namaberas,donatur[i].Brgdonasi.Bagi.AkumulasiKgBerasB);
}
if (donatur[i].Brgdonasi.ItemName.namasnack[0] != '\0')  {
    
                printf("Jumlah (Kg) %s: %.2lf\n",donatur[i].Brgdonasi.ItemName.namasnack,donatur[i].Brgdonasi.Bagi.AkumulasiKgSnackB); 
}
if (donatur[i].Brgdonasi.ItemName.namasuple[0] != '\0') {
                printf("Jumlah (Kg) %s: %.2lf\n",donatur[i].Brgdonasi.ItemName.namasuple,donatur[i].Brgdonasi.Bagi.AkumulasiKgSupleB); 
}
if (donatur[i].Brgdonasi.ItemName.namahewan[0] != '\0') {

                printf("Jumlah (Kg) %s: %.2lf\n",donatur[i].Brgdonasi.ItemName.namahewan,donatur[i].Brgdonasi.Bagi.AkumulasiKgDagingB); 
}
if (donatur[i].Brgdonasi.ItemName.namasayur[0] != '\0') {

                printf("Jumlah (Kg) %s: %.2lf\n",donatur[i].Brgdonasi.ItemName.namasayur,donatur[i].Brgdonasi.Bagi.AkumulasiKgSayurB);
}

printf("\n");

printf("Donasi ke %s \n",data[Tertinggi3].nama); 
if (donatur[i].Brgdonasi.ItemName.namaberas[0] != '\0') {
                printf("Jumlah (Kg) %s: %.2lf\n",donatur[i].Brgdonasi.ItemName.namaberas,donatur[i].Brgdonasi.Bagi.AkumulasiKgBerasC);
}
if (donatur[i].Brgdonasi.ItemName.namasnack[0] != '\0')  {
    
                printf("Jumlah (Kg) %s: %.2lf\n",donatur[i].Brgdonasi.ItemName.namasnack,donatur[i].Brgdonasi.Bagi.AkumulasiKgSnackC); 
}
if (donatur[i].Brgdonasi.ItemName.namasuple[0] != '\0') {
                printf("Jumlah (Kg) %s: %.2lf\n",donatur[i].Brgdonasi.ItemName.namasuple,donatur[i].Brgdonasi.Bagi.AkumulasiKgSupleC); 
}
if (donatur[i].Brgdonasi.ItemName.namahewan[0] != '\0') {

                printf("Jumlah (Kg) %s: %.2lf\n",donatur[i].Brgdonasi.ItemName.namahewan,donatur[i].Brgdonasi.Bagi.AkumulasiKgDagingC); 
}
if (donatur[i].Brgdonasi.ItemName.namasayur[0] != '\0') {

                printf("Jumlah (Kg) %s: %.2lf\n",donatur[i].Brgdonasi.ItemName.namasayur,donatur[i].Brgdonasi.Bagi.AkumulasiKgSayurC);
}

data[Tertinggi1].kelaparan_juta=wargalaper_A  / 1000000;
data[Tertinggi2].kelaparan_juta=wargalaper_B  / 1000000;
data[Tertinggi3].kelaparan_juta=wargalaper_C/ 1000000;

 mosthunger(data, &Tertinggi1, &Tertinggi2, &Tertinggi3); 
  
 } 


    
free(donatur);
free(Asia); 
free(Amerika); 
free(Oceania);
free(Eropa);
free(Afrika); 

    return 0; 
}
    

    

