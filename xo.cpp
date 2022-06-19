#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

bool pobeda(int xo[3][3])
{
	if(xo[0][0]==xo[0][1] && xo[0][0]==xo[0][2])
		{
			return true;
		}
	else if(xo[0][0]==xo[1][0] && xo[0][0]==xo[2][0])
	{
		return true;
	}
	else if(xo[0][0]==xo[1][1] && xo[0][0]==xo[2][2])
		{
			return true;
		}
	else if(xo[0][1]==xo[1][1] && xo[0][1]==xo[2][1])
	{
		return true;
	}
	else if(xo[0][2]==xo[1][2] && xo[0][2]==xo[2][2])
	{
		return true;
	}
	else if(xo[0][2]==xo[1][1] && xo[0][2]==xo[2][0])
	{
		return true;
	}
	else if(xo[1][0]==xo[1][1] && xo[1][0]==xo[1][2])
	{
		return true;
	}	
	else if(xo[2][0]==xo[2][1] && xo[2][0]==xo[2][2])
	{
		return true;
	}
	else
	{
		return false;
	}
}


void stampaj(int xo[3][3])
{
	int i,j;
	printf("  A  B  C");
	for(i=0;i<3;i++)
	{
		printf("\n");
		printf("%d ",i+1);
		for(j=0;j<3;j++)
		{
			if(xo[i][j]==1)
			{
				printf("X  ");
			}
			else if(xo[i][j]==2)
			{
				printf("O  ");
			}
			else
			{
				printf("   ");
			}
		}
	}
}

void stampaj2(int xo[4][4])
{
	int i,j;
	printf("  A  B  C");
	for(i=0;i<4;i++)
	{
		printf("\n");
		if(i==3)
		{
			printf("  ");
		}
		else
		{
			printf("%d ",i+1);
		}
		
		for(j=0;j<4;j++)
		{
			if(xo[i][j]==1)
			{
				printf("X  ");
			}
			else if(xo[i][j]==2)
			{
				printf("O  ");
			}
			else
			{
				printf("   ");
			}
		}
	}
}


int unosk()
{
	int kol;
	char k;
	unos:
	printf("\nUnesite kolonu: ");
	scanf(" %c",&k);
	if(k=='A' || k=='a')
	{
		kol=1;
	}
	else if(k=='B' || k=='b')
	{
		kol=2;
	}
	else if(k=='C' || k=='c')
	{
		kol=3;
	}
	else
	{
		printf("Pogresan unos! Probajte ponovo.\n");
		goto unos;
	}
	return kol;
}

int unosv()
{
	int vr;
	unos:
	printf("Unesite vrstu: ");
	scanf("%d",&vr);
	if(vr<1 && vr>3)
	{
		printf("Pogresan unos! Probajte ponovo.\n");
		goto unos;
	}
	return vr;
}

void dva_igraca()
{
	int xo[3][3]={{-1,-2,-3},{-4,-5,-6},{-7,-8,-9}};
	int vr,kol,i,j;
	int br=0;
	char prvi[30],drugi[30];
	printf("Dva igraca\n");
	stampaj(xo);
	printf("\nUnesite ime prvog igraca: ");
	scanf("%s",&prvi);
	printf("Unesite ime drugog igraca: ");
	scanf("%s",&drugi);
	while(1)
	{
		unos1p:
		kol=unosk();
		vr=unosv();
		if(xo[vr-1][kol-1]>0)
		{
			printf("Polje je vec zauzeto! Probajte ponovo.\n");
			goto unos1p;
		}
		br=br+1;
		xo[vr-1][kol-1]=1;
		system("cls");
		stampaj(xo);
		if(pobeda(xo))
		{
			printf("\nPobedio je %s!\n",prvi);
			break;
		}
		if(br==9)
		{
			printf("\n\nNERESENO!\n");
			return;
		}
		uno2p:
		kol=unosk();
		vr=unosv();
		if(xo[vr-1][kol-1]>0)
		{
			printf("Polje je vec zauzeto! Probajte ponovo.\n");
			goto uno2p;
		}
		xo[vr-1][kol-1]=2;
		br=br+1;
		system("cls");
		stampaj(xo);
		if(pobeda(xo))
		{
			printf("\nPobedio je %s!\n",drugi);
			break;
		}
		if(br==9)
		{
			printf("\n\nNERESENO!\n");
			return;
		}
	}
	
}

void kompjuter_easy()
{
	int xo[3][3]={{-1,-2,-3},{-4,-5,-6},{-7,-8,-9}};
	int vr,kol,i,j;
	int br=0;
	char prvi[30];
	printf("Protiv kompjutera (LAKO)\n");
	stampaj(xo);
	printf("\nUnesite ime igraca: ");
	scanf("%s",&prvi);
	while(1)
	{
		unos1p:
		kol=unosk();
		vr=unosv();
		if(xo[vr-1][kol-1]>0)
		{
			printf("Polje je vec zauzeto! Probajte ponovo.\n");
			goto unos1p;
		}
		br=br+1;
		xo[vr-1][kol-1]=1;
		system("cls");
		stampaj(xo);
		if(pobeda(xo))
		{
			printf("\nPobedio je %s!\n",prvi);
			break;
		}
		if(br==9)
		{
			printf("\nNERESENO!\n");
			return;
		}
		srand(time(0));
		unosvr:
		kol=rand()%3;
		vr=rand()%3;
		if(xo[vr][kol]>0)
		{
			goto unosvr;
		}
		xo[vr][kol]=2;
		br=br+1;
		system("cls");
		stampaj(xo);
		if(pobeda(xo))
		{
			printf("\nPobedio je kompjuter.\n");
			break;
		}
		if(br==9)
		{
			printf("\nNERESENO!\n");
			return;
		}
	}
		
}

void kompjuter_hard()
{
	int xo2[4][4]={{-1,-2,-3,-4},{-5,-6,-7,-8},{-9,-10,-11,-12},{-13,-14,-15,-16}};
	int vr,kol,i,j;
	char prvi[30];
	printf("Protiv kompjutera (TESKO)\n");
	stampaj2(xo2);
	printf("\nUnesite ime igraca: ");
	scanf("%s",&prvi);
	xo2[1][1]=2;
	system("cls");
	stampaj2(xo2);
	unos1p:
	kol=unosk();
	vr=unosv();
	if(kol>3 || vr>3)
	{
		printf("\nPogresan unos!\n");
		goto unos1p;
	}
	if(xo2[vr-1][kol-1]>0)
	{
		printf("Polje je vec zauzeto! Probajte ponovo.\n");
		goto unos1p;
	}
	xo2[vr-1][kol-1]=1;
	system("cls");
	stampaj2(xo2);
	if(xo2[2][1]==1)
	{
		xo2[1][2]=2;
	}
	else
	{
		xo2[2][1]=2;
	}
	system("cls");
	stampaj2(xo2);
	unoskol2:
	kol=unosk();
	vr=unosv();
	if(kol>3 || vr>3)
	{
		printf("\nPogresan unos!\n");
		goto unos1p;
	}
	if(xo2[vr-1][kol-1]>0)
	{
		printf("Polje je vec zauzeto! Probajte ponovo.\n");
		goto unoskol2;
	}
	xo2[vr-1][kol-1]=1;
	system("cls");
	stampaj2(xo2);
	if(xo2[1][2]==2)
	{
		xo2[1][3]=2;
	}
	else
	{
		xo2[3][1]=2;
	}
	system("cls");
	stampaj2(xo2);
	printf("\nPobedio je KOMPJUTER :)");
}

void uvod()
{
	printf(" .----------------.  .----------------. \n");
	printf("| .--------------. || .--------------. |\n");
	printf("| |  ____  ____  | || |     ____     | |\n");
	printf("| | |_  _||_  _| | || |   .'    `.   | |\n");
	printf("| |   \\ \\  / /   | || |  /  .--.  \\  | |\n");
	printf("| |    > `' <    | || |  | |    | |  | |\n");
	printf("| |  _/ /'`\\ \\_  | || |  \\  `--'  /  | |\n");
	printf("| | |____||____| | || |   `.____.'   | |\n");
	printf("| |              | || |              | |\n");
	printf("| '--------------' || '--------------' |\n");
	printf(" '----------------'  '----------------' \n");
	printf("\n");
	printf("Sofija Veljkovic 1/4\n\n");
}

void delay(float number_of_seconds)
{
    int milli_seconds = 1000 * number_of_seconds;
  
    // Storing start time
    clock_t start_time = clock();
  
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}

int main()
{
	int i,j,n;
	uvod();
	delay(2.5);
	pocetak:
	printf("Vrsta igre:\n");
	printf("1 - dva igraca\n");
	printf("2 - protiv kompjutera (LAKO)\n");
	printf("3 - protiv kompjutera (TESKO)\n");
	scanf("%d",&n);
	system("cls");
	if(n==1)
	{
		dva_igraca();
	}
	else if(n==2)
	{
		kompjuter_easy();
	}
	else if(n==3)
	{
		kompjuter_hard();
	}
	else
	{
		printf("Pogresan izbor! Probajte ponovo.\n");
		delay(1);
		goto pocetak;
	}
	
	return 0;
}
