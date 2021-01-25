#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void	All(int tab[],int N,int P,int M)
{
	int i=0;
	int DeplPssibilities[10] = {0,1,2,3,4,5,6,7,8,9};
    int Pos = P;
    int cnt = 0;
	int indice = 0;
	int x = 0;
	FILE *F;
	F = fopen("Result.txt","w");
	for(i=0;i<M;i++)
	{
		if(tab[i]>=0)
		{
			if(tab[i]+Pos<=9)
				{
					Pos = DeplPssibilities[Pos+tab[i]];
					fprintf(F,"%d\n",Pos);
				}
			else
				{
					Pos = DeplPssibilities[(Pos+tab[i])%9-1];
					fprintf(F,"%d\n",Pos);	
				}	
		}
		else
		{
			if(tab[i]+Pos>=0)
				{
					Pos = DeplPssibilities[Pos+tab[i]];
					fprintf(F,"%d\n",Pos);
				}
			else{
				x = 10 + ((Pos+tab[i])%9);
				Pos = DeplPssibilities[x];
				fprintf(F,"%d\n",Pos);
			}
		}
	}
	fclose(F);
	
}
void	Programme()
{
	FILE *F;
	int tab[50];
	int cnt = 0;
	F = fopen("Combinaisons.txt","r");
	int com=0,N=0,P=0,M=0;
	rewind(F);
	fscanf(F,"%d %d %d",&N,&P,&M);
	printf("%d %d %d",N,P,M);
	while (fscanf(F, "%d", &com) != EOF && cnt < M)
		{
			tab[cnt] = com;
			cnt++;
		}	
	fclose(F);
	All(tab,N,P,M);
	printf("\nCheck the file to see the combinaison\n");
}
int main(int argc, char *argv[]) {
	Programme();
	return 0;
}
