#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int unosk()
{
	int kol;
	char k;
	unos:
	printf("\nUnesite kolonu: ");
	scanf(" %c",&k);
	if(k=='A')
	{
		kol=1;
	}
	else if(k=='B')
	{
		kol=2;
	}
	else if(k=='C')
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
	while(1>0)
	{
		unoskol:
		kol=unosk();
		vr=unosv();
		if(xo[vr-1][kol-1]>0)
		{
			printf("Polje je vec zauzeto! Probajte ponovo.\n");
			goto unoskol;
		}
		br=br+1;
		xo[vr-1][kol-1]=1;
		system("cls");
		stampaj(xo);
		if(pobeda(xo))
		{
			printf("\nPobedio je %s! %s je looser :(\n",prvi,drugi);
			break;
		}
		if(br==9)
		{
			printf("\nNERESENO!\n");
			return;
		}
		unosvr:
		kol=unosk();
		vr=unosv();
		if(xo[vr-1][kol-1]>0)
		{
			printf("Polje je vec zauzeto! Probajte ponovo.\n");
			goto unosvr;
		}
		xo[vr-1][kol-1]=2;
		br=br+1;
		system("cls");
		stampaj(xo);
		if(pobeda(xo))
		{
			printf("\nPobedio je %s! %s je looser :(\n",drugi,prvi);
			break;
		}
		if(br==9)
		{
			printf("\nNERESENO!\n");
			return;
		}
	}
	
}

void kompjuter_easy()
{
	printf("EZ");
}

void kompjuter_hard()
{
	printf("GG WP");
}


int main()
{
	int i,j,n;
	//int xo[3][3]={{-1,-2,-3},{-4,-5,-6},{-7,-8,-9}};
	pocetak:
	printf("Vrsta igre:\n");
	printf("1 - dva igraca\n");
	printf("2 - protiv kompjutera (LAKO)\n");
	printf("3 - protiv kompjutera (TESKO)\n");
	scanf("%d",&n);
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
		goto pocetak;
	}
	/*stampaj(xo);
	
	pobeda(xo);
	scanf("%d",&i);
	system("cls");*/
	return 0;
}
