#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//Login
void menuLogin();

//Dealer
void menuLoginDealer();
void menuDealer();
//void displayDataCustomer();
//void hapusDataCustomer();
//
//void menuDataBarang();
//void kategoriBarang();
//void tambahBarang();
//void hapusBarang();
//void EditMenu();

//Customer
void menuRegistrasiCustomer();
void menuLoginCustomer();
void menuCustomer();
void opsiPembayaran();
void COD();
//void Invoice(char voucher[50]);
//void DaftarPesanan();

//struct
struct pembeli{
	char id[100],pwd[100],nama[100], alamat[1000], tlp[50];	
}pmb[500];


char nama[50], alamat[50], tlp[50], ID[50] , password[50];
int n=1,l1, m1, D1, c1, t1, y1;
char username[50];
int status = 0, salah = 0;
int i=0;

int main(){
	printf("========================");
	printf("\n===== D'Auto Parts =====\n");
	printf("========================\n");
	printf("     Menu Utama\n");
	printf("     ----------\n");
	printf("1. Login\n");
	printf("2. Registrasi\n");
	printf("Masukkan nomor Pilihan :\n");
	scanf("%d", &m1);
	
	switch(m1){
	case 1:
		system("cls");
		menuLogin();
		break; 
	case 2:
		system("cls");
		menuRegistrasiCustomer();
		break; 
	
	default : 
	printf("\n# Tidak ada di pilihan #\n");
	printf("# Pilih Angka 1-2 #\n");
		system("pause");
		system("cls");
		main();
		break;
	}	
	
}


///////////////////////Fungsi
void menuRegistrasiCustomer(){
	
	FILE *registrasi;
	getchar();
	registrasi = fopen("registrasi.dat", "ab");
	printf("====Registrasi====\n");
	for (int i=0;i<=n-1;i++){
	printf("Nama : ");
	gets(pmb[i].nama);
	printf("Alamat : ");
	gets(pmb[i].alamat);
	printf("No. Telepon : ");
	gets(pmb[i].tlp);
	printf("ID : ");
	gets(pmb[i].id);
	printf("Password : ");
	gets(pmb[i].pwd);
	fflush(stdin);
	fwrite(&pmb,sizeof(pmb),1,registrasi);
	}
	
	fclose(registrasi);
	system("pause");
	system("cls");	
	main();
}

void menuLogin(){
	
	printf("===Menu Login===\n");
	printf("1. Login Dealer\n");
	printf("2. Login Customer\n");
	printf("3. Kembali\n");
	printf("Masukkan nomor Pilihan :\n");
	scanf("%d", &l1);
	switch(l1){
	case 1:
		system("cls");
		menuLoginDealer();
		break; 
	case 2:
		system("cls");
		menuLoginCustomer();
		break; 
	
	case 3:
		system("cls");
		main();
		break;
	
	default : 
	printf("\n# Tidak ada di pilihan #\n");
	printf("# Pilih Angka 1-3 #\n");
		system("pause");
		system("cls");
		menuLogin();
		break;
	}	
	
}

void menuLoginDealer(){
	
	FILE *registrasi;
	getchar();
	registrasi = fopen("registrasi.dat", "ab");
	printf("=== LOGIN DEALER ===\n");
	printf("Username : ");
	gets(username);
	printf("Password : ");
	gets(password);
	
		if(strcmp(username,"Dealer")==0 && strcmp(password,"12345678")==0){
			for (int i=0;i<=n-1;i++){
				status=0;
				salah=0;
				printf("Akses diterima. Selamat Datang Abang/Kakak Dealer Ganteng/Cantik\n");
				system("pause");
				system("cls");
				menuDealer();
				break;
				}
			}else{
				printf("Username/Password Salah\n");
				salah++;
				system("pause");
				system("cls");
				if(salah==3){
					status=0;
					salah=0;
					printf(">>Mohon Maaf Batas Login Telah Habis<<\n");
					system("pause");
					system("cls");
					main();
				}
			}
			status++;
			}


void menuLoginCustomer(){
		
	int i=0;
	getchar();
	while(status<3){	
	FILE *registrasi;
	registrasi = fopen("registrasi.dat", "rb");
	printf("==== LOGIN COSTUMER ====\n");
	printf("ID : ");
	gets(ID);
	printf("Password : ");
	gets(password);
	while(fread(&pmb,sizeof(pmb),1,registrasi)==1 ){
		if( strcmp(ID,pmb[i].id)==0 && strcmp(password,pmb[i].pwd)==0){
			status=0;
			salah=0;
			printf("Akses diterima. Selamat Datang %s\n", pmb[i].nama);
			system("pause");
			system("cls");
			menuCustomer();
			break;
			}		
		}fclose(registrasi);
		
		if (strcmp(ID,pmb[i].id)!=0 && strcmp(password,pmb[i].pwd)!=0){
			printf("Username/Password Salah\n");
			salah++;
			system("pause");
			system("cls");
			if(salah==3){
				status=0;
				salah=0;
				printf(">>Mohon Maaf Batas Login Telah Habis<<\n");
				system("pause");
				system("cls");
				main();
				}
		}status++;
	}			
}

void menuDealer(){
	
	printf("=== Menu Dealer ===\n");
	printf("1. Data Customer\n");
	printf("2. Data Barang\n");
	printf("3. Log Out\n");
	printf("Masukkan nomor Pilihan :\n");
	scanf("%d", &D1);
	switch(D1){
	case 1:
		system("cls");
		//menuDataCustomer();
		break; 
	case 2:
		system("cls");
		//menuDataBarang();
		break; 
	
	case 3:
		system("cls");
		main();
		break;
	
	default : 
	printf("\n# Tidak ada di pilihan #\n");
	printf("# Pilih Angka 1-3 #\n");
		system("pause");
		system("cls");
		menuDealer();
		break;
	}
}

void menuCustomer(){
	printf("=== Menu Customer ===\n");
	printf("1. Pembelian Barang\n");
	printf("2. Browse\n");
	printf("3. Pencarian barang sesuai kategori\n");
	printf("4. Log Out\n");
	printf("Masukkan nomor Pilihan :\n");
	scanf("%d", &y1);
	switch(y1){
	case 1:
		system("cls");
		//void pembelianBarang();
		break; 
	case 2:
		system("cls");
		//void browse();
		break; 
	
	case 3:
		system("cls");
		//menuPencarianKtgr();
		break;
	
	case 4:
		system("cls");
		main();
		break;
	
	default : 
	printf("\n# Tidak ada di pilihan #\n");
	printf("# Pilih Angka 1-4 #\n");
	menuCustomer();
	}
}

//void opsiPembayaran(){
//	printf("=== Opsi Pembayaran ===\n");
//	printf("1. COD\n");
//	printf("2. Kembali\n");
//	printf("Masukkan nomor Pilihan :\n");
//	scanf("%d", &t1);
//	switch(t1){
//	case 1:
//		system("cls");
//		void COD();
//		break; 
//		
//	case 2:
//		system("cls");
//		menuCustomer();
//		break;
//	
//	default : 
//	printf("\n# Tidak ada di pilihan #\n");
//	printf("# Pilih Angka 1-2 #\n");
//	}
//}

//void COD(){
//	printf("\n=============INVOICE COD=============\n");
//	printf("Nama	: %s\n", username);
//	printf("Nama Pesanan : %s\n", pes.menu);
//	printf("Total Harga : %s\n", pes.harga);
//	printf("Kode Voucher: %s\n", voucher);
//	printf("\n=================================\n");
//}

