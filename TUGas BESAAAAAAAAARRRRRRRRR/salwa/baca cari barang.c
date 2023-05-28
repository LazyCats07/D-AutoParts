#include <stdio.h>
int main(){
FILE *f_dm;

int i=1;
struct brg{
    char ktgr[50], brg[50], harga[20], jenis[40];
} data;


f_dm = fopen("Data Barang.dat", "rb");
while(fread(&data,sizeof(data),1,f_dm)==1){
	
printf("%i. Nama barang\t\t: %s\n",i++,data.brg);
printf("   Kategori\t\t: %s\n",data.ktgr);
printf("   Jenis\t\t: %s\n", data.jenis);
printf("   Harga\t\t: %s\n", data.harga);
}
fclose(f_dm);
return 0;
}