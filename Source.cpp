#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include<string.h>

typedef struct {
	char bucatar[20];
	int id;
	char title[20];
	unsigned char rating[4];
} BUCATAR;



void Modificare()
{
	FILE* f, * fp;
	BUCATAR x;
	int i = 0;
	char numen[20], nume[20];
	printf("Introdu numele artistului caruia ii alternezi rating-ul pe Zona 1: ");
	gets_s(nume);
	gets_s(nume);
	sprintf_s(numen, "Bucatari.txt", nume);
	f = fopen(numen, "r");

	if (f == NULL)
		printf("Nu exista.");
	else
	{
		fp = fopen("Modificat.txt", "w");
		fprintf(fp, "\n Id. %-19s %-19s %-19s", "Bucatar", "Titlu", "Rating");
		fread(&x, sizeof(BUCATAR), 1, f);
		while (!feof(f))
		{
			i++;
			printf("Modifica rating-ul in: ");
			scanf_s("%hhu", &x.rating[1]);
			
			fprintf(fp, "\n%4d %-19s %-19s %-7hhu %-7hhu", x.id, x.bucatar, x.title, x.rating[0], x.rating[1]);
			fseek(f, 0, 1);
			fread(&x, sizeof(BUCATAR), 1, f);
		}

		fclose(fp);
		fclose(f);
	}
	if (i != 0)
		printf("S-a modificat!");


}




int main()
{
	FILE* f;
	BUCATAR x;
	int trueval = 0, i;
	f = fopen("Bucatari.txt", "w");
	if (f == NULL)
	{
		printf("Nu exista acest fisier.");
	}
	else
	{
		while (trueval == 0)
		{
			printf("ID: ");
			scanf_s("%d", &x.id);

			printf("Titlu: ");
			gets_s(x.title);
			gets_s(x.title);

			printf("Nume: ");
			gets_s(x.bucatar);

			printf("Te rog completeaza rating-ul pentru zonele aferente: \n");
			printf("Zona 0: ");
			for (i = 0; i < 1; i++)
			{
				scanf_s("%hhu", &x.rating[i]);
				fflush(stdin);
			}
			printf("Zona 1: ");
			for (i = 0; i < 1; i++)
			{
				scanf_s("%hhu", &x.rating[i]);
				fflush(stdin);
			}
			fwrite(&x, sizeof(BUCATAR), 1, f);

			printf("Apasa 0 pentru a continua SAU 1 pentru a iesi: ");
			scanf_s("%d", &trueval);

		}
		fclose(f);
	}

	Modificare();

	return 0;
}
