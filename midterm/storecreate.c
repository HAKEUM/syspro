#include <stdio.h>
#include <stdlib.h>
#include "db.dat"

int main(int argc,char* argv[]) {
	struct product rec;
	FILE *fp;

	fp = fopen(argv[1], "wb");
	printf("%-4s %-15s %-9s %-13s %-5s\n","id","name","category","expired date","stock");
	while(scanf("%d %s %s %d %d",&rec.id, rec.name, rec.category, &rec.expired_date, &rec.stock)==5)
		fwrite(&rec, sizeof(rec),1,fp);

	fclose(fp);
	exit(0);
}
