#include <stdio.h>
#include "db.dat"

int main(int argc,char* argv[]) {
	struct product rec;
	FILE *fp;
	int i;
	if((fp = fopen(argv[1],"rb")) ==NULL) {
		fprintf(stderr,"Error Open File\n");
		return 1;
	}
	printf("--Goods query--\n");
	printf("0: list of all goods, 1: list of available goods ) ");
	scanf("%d",i);
	if (i == 0) {
		printf("%3s %15s %8s %12s %5s\n","id","name","category","expired date","stock");
		while(fread(&rec,sizeof(rec),1,fp)>0)
			if(rec.id !=0)
				printf("%3d %15s %8s %12d %5d\n",rec.id,rec.name,rec.category,rec.expired_date,rec.stock);
	}
	else if(i == 1) {
		printf("%3s %15s %8s %12s %5s\n","id","name","category","expired date","stock");
		while(fread(&rec,sizeof(rec,1,fp)>0)
				if((rec.stock != 0)&&(rec.id !=0))
					printf("%3d %15s %8s %12d %5d\n",rec.id,rec.name,rec.category,rec.expired_date,rec.stock);
					}
					fclose(fp);
					return 0;
					}
