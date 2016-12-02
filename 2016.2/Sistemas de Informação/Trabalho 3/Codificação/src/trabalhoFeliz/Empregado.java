package trabalhoFeliz;

import java.util.LinkedList;
import java.util.Scanner;

import bancoDados.manipulacao.ProfissaoM;
import bancoDados.tabelas.Funcionario;
import bancoDados.tabelas.Profissao;
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
	
	public static Funcionario preencherDados (){
		Funcionario func = new Funcionario();
		
		preencherNome(func);
		
		preeencherCpf(func);
		
		preencherData(func, "Nascimento");
		
		preencherTelefone (func);
		
		preencherEmail(func);
		
		preencherProfissao(func);
		
		preencerValeTransporte(func);
		
		return func;
	}

	
	
	
	/**
	 * Requisitar o preenchimento do nome do funcionário; deve-se tentar
	 * enquanto for um nome inválido
	 * @param func Funcionário a ter o nome atribuído
	 */
	public static void preencherNome (Funcionario func){
		Scanner entrada = new Scanner (System.in);
		
		do{
			System.out.println("* Nome completo (sem acentuação):");
			String linha = entrada.nextLine();
			
			if (Autentificacao.isNome(linha)){
				func.setNome(linha);
				break;
				
			}else	System.out.println(Erro.nome());
			
		}while (true);
		
		entrada.close();
	}
	
	/**
	 * Requisitar o preenchimento do CPF do funcionário; deve-se tentar
	 * enquanto for um CPF inválido
	 * @param func Funcionário a ter o nome atribuído
	 */
	public static void preeencherCpf (Funcionario func){
		Scanner entrada = new Scanner (System.in);
		do{
			System.out.println("* CPF (somente os números):");
			String linha = entrada.nextLine();
			
			if (Autentificacao.isCpf(linha)){
				func.setCpf(Autentificacao.cpf(linha));
				break;
				
			}else	System.out.println(Erro.cpf());				
				
		}while(true);
		
		entrada.close();
	}

	/**
	 * Requisitar o preenchimento da data do funcionário; deve-se tentar
	 * enquanto for uma data inválida
	 * @param func Funcionário a ter o nome atribuído
	 * @param tipo Tipo da data que está sendo requisitada, podendo ser 
	 * de nascimento ou de admissão
	 */
	public static void preencherData (Funcionario func, String tipo){
		Scanner entrada = new Scanner (System.in);
		
		do{
			System.out.println("* Data de " + tipo + " (aaaa-mm-dd, só os números [0-9] nessa sequência):");
			String linha = Autentificacao.data(entrada.nextLine());
			
			if (Autentificacao.isData(linha)){
				if (tipo.equals("Nascimento"))
					func.setDataNasc(linha);
				else
					func.setDataAdm(linha);
				
				break;
				
			}else	System.out.println(Erro.data(tipo));				
				
		}while(true);
		
		entrada.close();
	}

	/**
	 * Requisitar o preenchimento do telefone do funcionário; deve-se tentar
	 * enquanto for um telefone inválido
	 * @param func Funcionário a ter o telefone atribuído
	 */
	public static void preencherTelefone (Funcionario func){
		Scanner entrada = new Scanner (System.in);
		
		do{
			System.out.println("* Telefone (com o DDD, somente os números):");
			String linha = entrada.nextLine();
			
			if (Autentificacao.isTelefone(linha)){
				func.setTelefone(Autentificacao.telefone(linha));
				break;
				
			}else	System.out.println(Erro.telefone());
				
		}while(true);
		
		entrada.close();
	}

	/**
	 * Requisitar o preenchimento do e-mail do funcionário; deve-se tentar
	 * enquanto for um e-mail inválido
	 * @param func Funcionário a ter o e-mail atribuído
	 */
	public static void preencherEmail (Funcionario func){
		Scanner entrada = new Scanner (System.in);
		
		do{
			System.out.println("* E-mail (exemplo@exemplo.com):");
			String linha = entrada.nextLine();
			
			if (Autentificacao.isEmail(linha)){
				func.setEmail(linha);
				break;
			
			}else	System.out.println(Erro.email());
			
		}while(true);
		
		entrada.close();
	}

	/**
	 * Requisitar o preenchimento da profissão do funcionário; deve-se tentar
	 * enquanto for uma profissão inválida
	 * @param func Funcionário a ter a profissão atribuída
	 */
	public static void preencherProfissao (Funcionario func){
		Scanner entrada = new Scanner (System.in);
		LinkedList<Profissao> profissoes = ProfissaoM.lerCompleto();
		LinkedList<Integer> codigos = new LinkedList<Integer>();
		int maior = 0;
		
		System.out.println("* Profissão, escolha uma opção:");
		
		for (int pos = 0; pos < profissoes.size(); pos++){
			Profissao prof = profissoes.get(pos);
			
			System.out.print("\t" + prof.getCodigo() + " - " + prof.getDescricao());
			codigos.add(prof.getCodigo());
			
			if (pos != profissoes.size() - 1)
				System.out.println(";");
			else
				System.out.println(".");
			
			if (prof.getCodigo() > maior)
				maior = prof.getCodigo();
		}
			
		do{
			System.out.println("Digite a escolha:");
			
			try{
				int linha = Integer.parseInt(entrada.nextLine());
				
				if (codigos.contains(linha)){
					func.setCodProf(linha);
					func.setCodProfInss(profissoes.get(codigos.indexOf(linha)).getInss_codigo());
					func.setCodProfIrrf(profissoes.get(codigos.indexOf(linha)).getIrrf_codigo());
					break;
					
				}else System.out.println(Erro.profissaoOuVale("Profissão", false));
			}catch (NumberFormatException e){
				System.out.println(Erro.profissaoOuVale("Profissão", true));
			}
			
		}while (true);
		
		entrada.close();
	}

	/**
	 * Requisitar o preenchimento da quantidade de vale-transporte do
	 * funcionário; deve-se tentar
	 * enquanto for uma quantidade inválida
	 * @param func Funcionário a ter a quantidade atribuída
	 */
	public static void preencerValeTransporte (Funcionario func){
		Scanner entrada = new Scanner (System.in);
		
		System.out.println("* Vale transporte:");
		System.out.println("\tSe não houver interesse, digite 0;");
		System.out.println("\tCaso contrário, digite a quantidade.");
		
		do{
			System.out.println("Digite a sua escolha:");
			
			try{
				int linha = Integer.parseInt(entrada.nextLine());
				
				if (linha >= 0){
					func.setQntValeTransp(linha);
					break;
					
				}else System.out.println(Erro.profissaoOuVale("Quantidade de vale-transporte", false));
			}catch (NumberFormatException e){
				System.out.println(Erro.profissaoOuVale("Quantidade de vale-transporte", true));
			}
			
		}while (true);
		
		entrada.close();
	}
}

