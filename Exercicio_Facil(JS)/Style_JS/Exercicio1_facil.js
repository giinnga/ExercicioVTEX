function variaveis (form) {
    var total = form.total.value;
    var hectometro = form.hectometro.value;
    var maximo = form.maximo.value;
    var entrega = rotina(total,0,hectometro,maximo,0)
    if(entrega == 0){
		console.log("Impossivel!");
		document.getElementById("entrega").innerHTML = "Impossivel!";
	}
	else{
		console.log("Entrega: " + entrega);
		if(entrega == 1)
			document.getElementById("entrega").innerHTML = entrega + " entregue.";
		else
    		document.getElementById("entrega").innerHTML = entrega + " entregues.";
    }
}

function calculoDistancia (total, maximo){
	return Math.round(total/maximo*2) + 1;
}

function entrega (total, distancia){
	return total - distancia;
}

function calculoDeposito (distancia, maximo, total){
	if(total<=maximo)
		return total - distancia;
	else
		return maximo - 2*distancia;
}

function rotina(total, distancia, hectometro, maximo, deposito) {
	if(parseInt(hectometro,10)>=parseInt(total,10))
		return 0;

	var distancia = calculoDistancia(total, maximo);

	while(total>0){
		var deposito = deposito + calculoDeposito(distancia,maximo,total);
		if(total>maximo)
			total = total - maximo;
		else
			total = 0;
	}
	if(deposito <= maximo && hectometro - distancia < deposito)
		return entrega(deposito,hectometro - distancia);
	else
		return rotina(deposito,distancia,hectometro,maximo,0);
}