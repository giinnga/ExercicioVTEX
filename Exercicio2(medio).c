#include <stdio.h>

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

	int xb, yb;
	xb = x + xv;
	yb = y + yv;

	return x * yb - y * xb;
}

int testeQ (int xl, int yl, int x1, int x2, int y1, int y2, int xv, int yv, int q, int cl) { // Verificar e se necessario trocar as coordenadas dos pontos

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

int main(void) {

	int n, xl, yl, cl, xv, yv, q, i=0, r, j=0;
	int x1[100], x2[100], y1[100], y2[100], c[100];
	char *templos[100];
	printf("Digite o número de templos existentes: ");
	scanf("%d",&n);
	printf("Digite a coordenada X do Link: ");
	scanf("%d",&xl);
	printf("Digite a coordenada Y do Link: ");
	scanf("%d",&yl);
	printf("Digite o vetor direcao da espada de Link: ");
	scanf("%d",&xv);
	printf("Agora o Y do vetor: ");
	scanf("%d",&yv);

	cl = equacao(xv,yv,xl,yl);
	q = quadrante(xv,yv);

	while(n > 0) {
		printf("Digite o nome do templo: ");
		scanf("%s",templos[i]);
		printf("Digite a coordenada x do primeiro ponto do templo: ");
		scanf("%d",&x1[i]);
		printf("Digite a coordenada y do primeiro ponto do templo: ");
		scanf("%d",&y1[i]);
		printf("Digite a coordenada x do segundo ponto do templo: ");
		scanf("%d",&x2[i]);
		printf("Digite a coordenada y do segundo ponto do templo: ");
		scanf("%d",&y2[i]);
		r = testeQ(xl, yl, x1[i], x2[i], y1[i], y2[i], xv, yv, q, cl);
		if(r == 1) {
			c[j] = i;
			j++;
		}
		i++;
		n--;
	}

	i=0;
	while (j>0) {
		printf("%s\n",templos[c[i]]);
        j--;
        i++;
	}
	return 0;
}

