#include <stdio.h>

int quadrante (int xv, int yv) {

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

	return x * yc - y * xc;
}

int testeQ (int xl, int yl, int x1, int x2, int y1, int y2, int xv, int yv, int q, int cl) { // Verificar e se necessario trocar as coordenadas dos pontos

	int aux, c1, c2;
	if (q == 0){
		printf("Erro, vetor direcao (0,0)!\n");
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

	int n, xl, yl, cl, xv, yv, x1, y1, x2, y2, q, i;
	char templos[10];
	printf("Digite o número de templos existentes: ");
	scanf("%d",&n);
	printf("Digite as coordenadas do Link (x,y): ");
	scanf("%d %d",&xl,&yl);
	printf("Digite o vetor direcao da espada de Link (x,y): ");
	scanf("%d %d",&xv,&yv);
	while(n>0) {
		printf("Digite o nome do templo: ");
		scanf("%s",&templos);
		scanf("%d %d",&x1, &y1);
		scanf("%d %d",&x2, &y2);
		n--;
	}
	cl = equacao(xv,yv,xl,yl);
	q = quadrante(xv,yv);
	i = testeQ(xl, yl, x1, x2, y1, y2, xv, yv, q, cl);
	printf("%d",i);
	return 0;

}




































