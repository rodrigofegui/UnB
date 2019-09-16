void recebe_notas (float*notas, int n, int *apr){
int i;

	for(i=0; i<n; i++){
		if (*(notas+i) >= 6.0)
			*(apr+i)=1;
		else
			*(apr+i)=0;	
	}
}

void conta_notas (int *apr , int n, float *apro, float *repro){
int i, qntapro=0, qntrepro=0;

	for(i=0; i<n; i++){
		if(*(apr+i)==1)
			qntapro++;
		else
			qntrepro++;
	}

	*apro = qntapro;
	*repro = qntrepro;
}

int porcentagem_aprovados (float numrepro, float numapro, float *papro, float *prepro){
	
	*papro = (numapro / (numapro+numrepro)) * 100.0;
	*prepro = (numrepro / (numapro+numrepro)) * 100.0;
	
	if(*papro > 50.0)
		return 1;
	return 0;
}
