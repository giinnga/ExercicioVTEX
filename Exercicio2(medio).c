#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int quadrante (int xv, int yv) { // Descobrir para qual quadrante o vetor direcao aponta

	int q;
	if (yv>0) {
		if (xv>0)
			q = 1;
		else if (xv<0)
			q = 4;
		else
			q = 14;
	}
	else if (yv<0) {
		if (xv>0)
			q = 2;
		else if (xv<0)
			q = 3;
		else
			q = 23;
	}
	else {
		if (xv>0)
			q = 12;
		else if (xv<0)
			q = 34;
		else
			q = 0;
	}
	return q;
}

int equacao (int xv, int yv, int x, int y) { // Encontrar o C da equacao a*x + b*y + c = 0

	int xc, yc;
	xc = x + xv;
	yc = y + yv;

	return x * yc - y * xc;
}

int determinaTemplo (int xl, int yl, int x1, int x2, int y1, int y2, int xv, int yv, int q, int cl) { /* Verificar e se necessario trocar as coordenadas dos
																								pontos. Verificar tambem se o templo se
																								adequa ao quadrante e comparar o C da equacao
																								da espada ao C da equacao dos pontos do templo,
																								determinando se Link dever ir ou nao ao local*/

	int aux, c1, c2;
	if (q == 0){
		printf("Erro, vetor direcao (0,0)!\n");
		return 0;
	}
	else {
		if(q == 1) {
			if((y1<yl && y2<yl) || (x1<xl && x2<xl))
				return 0;
			if(x1<x2) {
				if(y1<y2) {
					aux = y2;
					y2 = y1;
					y1 = aux;
				}
			}
			else {
				if(y1>y2) {
					aux = y2;
					y2 = y1;
					y1 = aux;
				}
			}
		}
		else if (q == 2) {
			if((y1>yl && y2>yl) || (x1<xl && x2<xl))
				return 0;
			if(x1<x2) {
				if(y1>y2) {
					aux = y2;
					y2 = y1;
					y1 = aux;
				}
			}
			else {
				if(y1<y2) {
					aux = y2;
					y2 = y1;
					y1 = aux;
				}
			}
		}
		else if (q == 3) {
			if((y1>yl && y2>yl) || (x1>xl && x2>xl))
				return 0;
			if(x1<x2) {
				if(y1<y2) {
					aux = y2;
					y2 = y1;
					y1 = aux;
				}
			}
			else {
				if(y1>y2) {
					aux = y2;
					y2 = y1;
					y1 = aux;
				}
			}	
		}
		else if (q == 4) {
			if((y1<yl && y2<yl) || (x1>xl && x2>xl))
				return 0;
			if(x1<x2) {
				if(y1>y2) {
					aux = y2;
					y2 = y1;
					y1 = aux;
				}
			}
			else {
				if(y1<y2) {
					aux = y2;
					y2 = y1;
					y1 = aux;
				}
			}
		}
		else if (q == 12)
			if((y1>yl && y2>yl) || (y1<yl && y2<yl) || (x1<xl && x2<xl))
				return 0;	
			else
				return 1;
		else if (q == 23)
			if((x1>xl && x2>xl) || (x1<xl && x2<xl) || (y1>yl && y2>yl))
				return 0;
			else
				return 1;
		else if (q == 14)
			if((x1>xl && x2>xl) || (x1<xl && x2<xl) || (y1>yl && y2>yl))
				return 0;
			else
				return 1;
		else
			if((y1>yl && y2>yl) || (y1<yl && y2<yl) || (x1>xl && x2>xl))
				return 0;
			else
				return 1;
	}
	c1 = equacao(xv, yv, x1, y1);
	c2 = equacao(xv, yv, x2, y2);
	if (c1 > c2) {
		aux = c2;
		c2 = c1;
		c1 = aux;
	}
	if(cl <= c2 && cl >= c1)
		return 1;
	else
		return 0;
}

void imprime(char *templos[],int cada[],int todos){
	int i=0,j=0;
	while(todos>0){
		printf("%s",templos[i]);
		cada[j]--;
		i++;
		if(cada[j]==0){
			printf("\n");
			j++;
		}
		else
			printf(" ");
		todos--;
	}
	return;
}

void libera(char *templos[],int total){
	while(total>=0){
		free(templos[total]);
		total--;
	}
	return;
}

int main (void) {
	int n,xl,yl,xv,yv,x1,x2,y1,y2,q,cl,r,i=0,aux=0,total=0;
	char templo[21], *templos[100];
	int t[100];

	printf("Digite o numero de templos existentes: ");
	scanf(" %d",&n);
	while(n!=0){
		printf("Digite a coordenada X do Link: ");
		scanf(" %d",&xl);
		printf("Digite a coordenada Y do Link: ");
		scanf(" %d",&yl);
		printf("Digite o vetor direcao da espada de Link: ");
		scanf(" %d",&xv);
		printf("Agora o Y do vetor: ");
		scanf(" %d",&yv);
		cl = equacao(xv,yv,xl,yl);
		q = quadrante(xv,yv);
		while(n>0) {
			printf("Digite o nome do templo: ");
			scanf(" %s",templo);
			printf("Digite a coordenada x do primeiro ponto do templo: ");
			scanf(" %d",&x1);
			printf("Digite a coordenada y do primeiro ponto do templo: ");
			scanf(" %d",&y1);
			printf("Digite a coordenada x do segundo ponto do templo: ");
			scanf(" %d",&x2);
			printf("Digite a coordenada y do segundo ponto do templo: ");
			scanf(" %d",&y2);
			r = determinaTemplo(xl, yl, x1, x2, y1, y2, xv, yv, q, cl);
			if(r==1){
				templos[i] = (char *)malloc(21*sizeof(char)+1);
				strcpy(templos[i],templo);
				i++;
				total+=1;
			}
			n--;
		}
		t[aux] = i;
		aux++;
		printf("Digite o numero de templos existentes: ");
		scanf(" %d",&n);
	}
	imprime(templos,t,&total);
	libera(templos,&total);
	return 0;
}
