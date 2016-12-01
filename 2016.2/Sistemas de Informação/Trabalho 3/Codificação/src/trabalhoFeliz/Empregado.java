package trabalhoFeliz;

import java.util.Scanner;

import bancoDados.tabelas.Funcionario;
import utilitario.Autentificacao;
import utilitario.Erro;

/**
 * Classe responsável pela implementação de um Empregado
 * na empresa TrabalhoFeliz
 * @author	Rodrigo Guimarães
 * @version	1.0
 * @since	29/11/2016
 */
public class Empregado {
	private static Scanner entrada = new Scanner (System.in);
	
	public static Funcionario preencherDados (){
		Funcionario func = new Funcionario();
		
		preencherNome(func);
		
		preeencherCpf(func);
		
		preencherData(func, "Nascimento");
			
			
		System.out.println("3. Data de Nascimento (aaaa-mm-dd, ou só os números nessa sequência):");
			func.setDataNasc(Autentificacao.data(entrada.nextLine()));
			
		System.out.println("4. Telefone:");
			func.setTelefone(entrada.nextLine());
		
		do{
			System.out.println("5. E-mail:");
			
			if (Autentificacao.isEmail(entrada.nextLine())){
				func.setEmail(entrada.nextLine());
				break;
			
			}else{
				System.out.println("Erro: E-mail inválido, digite novamente.");
			}
		}while(true);
			
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

	
	
	
	/**
	 * Requisitar o preenchimento do nome do funcionário; deve-se tentar
	 * enquanto for um nome inválido
	 * @param func Funcionário a ter o nome atribuído
	 */
	private static void preencherNome (Funcionario func){
		do{
			System.out.println("* Nome completo (sem acentuação):");
			String linha = entrada.nextLine();
			
			if (Autentificacao.isNome(linha)){
				func.setNome(linha);
				break;
				
			}else
				System.out.println(Erro.nome());
		}while (true);
	}
	
	/**
	 * Requisitar o preenchimento do CPF do funcionário; deve-se tentar
	 * enquanto for um CPF inválido
	 * @param func Funcionário a ter o nome atribuído
	 */
	private static void preeencherCpf (Funcionario func){
		do{
			System.out.println("* CPF (somente os números):");
			String linha = entrada.nextLine();
			
			if (Autentificacao.isCpf(linha)){
				func.setCpf(Autentificacao.cpf(linha));
				break;
				
			}else
				System.out.println(Erro.cpf());
				
				
		}while(true);
	}

	private static void preencherData (Funcionario func, String tipo){
		do{
			System.out.println("* Data de " + tipo + " (aaaa-mm-dd, só os números nessa sequência):");
			String linha = Autentificacao.data(entrada.nextLine());
			
			if (Autentificacao.isCpf(linha)){
				func.setCpf(Autentificacao.cpf(linha));
				break;
				
			}else
				System.out.println(Erro.cpf());
				
				
		}while(true);
	}
}
