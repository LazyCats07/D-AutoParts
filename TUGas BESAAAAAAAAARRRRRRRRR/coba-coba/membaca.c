#include <stdio.h>


struct pembeli{
	char id[100],pwd[100],nama[100], alamat[1000], tlp[50];	
}pmb[500];

int main(){
FILE *registrasi;

int n=1, i;

registrasi = fopen("registrasi.dat", "rb");
while(fread(&pmb,sizeof(pmb),1,registrasi)==1){
	for(int i=0; i<=n-1; i++){
		printf("%i.Nama : %s\n",i++,pmb[i].nama);
	}
}
fclose(registrasi);
return 0;
}
