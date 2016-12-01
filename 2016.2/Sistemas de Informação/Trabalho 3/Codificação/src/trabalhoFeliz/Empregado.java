package trabalhoFeliz;

import java.util.Scanner;

import bancoDados.tabelas.Funcionario;
import principal.Formatacao;

/**
 * Classe responsável pela implementação de um Empregado
 * na empresa TrabalhoFeliz
 * @author	Rodrigo Guimarães
 * @version	1.0
 * @since	29/11/2016
 */
public class Empregado {
	public static Funcionario preencherDados (){
		Funcionario func = new Funcionario();
		Scanner entrada = new Scanner (System.in);
		
		
		System.out.println("1. Nome completo:");
			func.setNome(Formatacao.nome(entrada.nextLine()));
			
		System.out.println("2. CPF (somente os números):");
			func.setCpf(Formatacao.cpf(entrada.nextLine()));
			
		System.out.println("3. Data de Nascimento (aaaa-mm-dd, ou só os números nessa sequência):");
			func.setDataNasc(Formatacao.data(entrada.nextLine()));
			
		System.out.println("4. Telefone:");
			func.setTelefone(entrada.nextLine());
			
		System.out.println("5. E-mail:");
			func.setEmail(entrada.nextLine());
			
		System.out.println("6. Profissão, escolha uma opção:");
			System.out.println("\t1 - Professor presencial;");
			System.out.println("\t2 - Professor online;");
			System.out.println("\t3 - Equipe limpeza;");
			System.out.println("\t4 - Equipe alimentação;");
			System.out.println("\t5 - Equipe áudio-visual.");
			System.out.println("Digite a escolha:");
				func.setCodProf(Integer.parseInt(entrada.nextLine()));
			
		
			
		entrada.close();
		
		return func;
	}

	
	
	


}
