#include <stdio.h>
#include <stdlib.h>

// Respon�vel: Rodrigo F. Guimar�es
// Turma: E
// Calcule a m�dia aritm�tica das 3 notas de um aluno e mostre, al�m do valor da m�dia,
// uma mensagem de "Aprovado",caso a m�dia seja igual ou superior a 5, ou a mensagem "reprovado", caso contr�rio.

int main ()
{
	float n1, n2, n3, nf;
	
	printf("Ola!\nVamos ver seu desempenho na materia de I.A.L.,\npara isso, e preciso que digite a nota da primeira prova:\n");
		scanf("%f", &n1);
	printf("\nMuito bem! Agora, digite a nota da segunda prova:\n");
		scanf("%f", &n2);
	printf("\nMuito bem! Falta pouco... Finalmente, digite a nota da terceira prova:\n");
		scanf("%f", &n3);
		
nf = (n1 + n2 + n3)/3;

	if (nf < 5)
		printf("\nAconteceu algo terrivel... Infelizmente com a nota final de %.2f pts, ficou\nREPROVADO na disciplina de I.A.L.\nTente semestre que vem! Boa sorte!\n\n", nf);
	else
		printf("\nQue surpresa agrad�vel... Com a nota final de %.2f pts, foi APROVADO na\ndisciplina de I.A.L.\nContinue com seu curso. Parabens!\n\n", nf);
	
	getchar();
	return 0;
}
