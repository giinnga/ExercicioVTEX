#include <stdio.h>
#include <math.h>

int arredonda (float x) {

	float i;
	i = x - floor(x);
	if (i >= 0.5)
		return ceil(x);
	else
		return floor(x);
}

int calculoDistancia (float comprado, float maximo) { // Fórmula adquirida após o modelar matematicamente a questão

	return arredonda((float)(comprado / maximo) * 2 ) + 1;
}

int entrega (int quantidade, int distancia) {

	return quantidade - distancia;
}

int calculoDeposito (int distancia,int maximo, int total) {

	if(total <= maximo){
		return total - distancia;
	}
	else {
		return maximo - 2*distancia;
	}
}

int teste (int total, int distancia, int hectometro, int maximo, int deposito) { /* Função recursiva caso seja necessário calcular mais
																					de uma vez a distância */

	if (hectometro >= total)
		return 0;

	distancia = calculoDistancia(total,maximo);
		
	while (total > 0) {
		deposito = deposito + calculoDeposito(distancia,maximo,total);
		if (total > maximo)
			total = total - maximo;
		else
			total = 0;
	}	
	if (deposito <= maximo && hectometro - distancia < deposito)
		return entrega(deposito,hectometro - distancia);
	
	else
		return teste(deposito,distancia,hectometro-distancia,maximo,0);
}

int main (void) {

	int total, maximo, hectometro, final;
	printf("Digite o total de produtos comprados, a distancia em hectometros e o maximo carregado pelo carrinho em ordem!\n");
	scanf("%d %d %d",&total,&hectometro,&maximo);
	if(total < 10 || maximo > 100000000)
		return 0;
	final = teste(total,0,hectometro,maximo,0);
	if (final == 0)
		printf("impossivel\n");
	else
		printf("%d",final);
	return 0;
}