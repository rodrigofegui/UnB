package gui;

import java.util.LinkedList;
import java.util.Scanner;

import bancoDados.manipulacao.ProfissaoM;
import bancoDados.tabelas.Funcionario;
import bancoDados.tabelas.Profissao;
import gui.terminal.Textual;
import utilitario.Autentificacao;
import utilitario.Erro;

public abstract class Mensagem {
	/**
	 * Desenvolvimento do título da Janela 
	 * @return Título desenvolvido
	 */
	public static String tituloJanela (){
		String titulo = "";
		
		titulo += preencherAsterisco(Textual.TITULO);
		titulo += "*  " + Textual.TITULO + "  *\n";
		titulo += preencherAsterisco(Textual.TITULO);
		
		return titulo;
	}
	
	/**
	 * Desenvolvimento do título da Janela 
	 * @param texto Texto a ser inserido no título da janela
	 * @return Título desenvolvido
	 */
	public static String tituloJanela (String texto){
		String titulo = "";
		String textoFinal = Textual.TITULO + "/" + texto;
		
		titulo += preencherAsterisco(textoFinal);
		titulo += "*  " + textoFinal + "  *\n";
		titulo += preencherAsterisco(textoFinal);
		
		return titulo;
	}
	
	/**
	 * Questiona o usuário quanto a escolha das opções apresentadas
	 * @param entradaDados Entrada de dados via terminal
	 * @param qntOpcoes Quanto de opções lineares oferecidas
	 * @return Escolha válida
	 */
	public static int questionaOpcoes (Scanner entradaDados, int qntOpcoes){
		System.out.println("Digite a sua escolha:");
		do{
			String resposta = entradaDados.nextLine();
			
			if (Autentificacao.isNumero(resposta, false)){
				int resp = Integer.parseInt(resposta);
				
				if (Autentificacao.isContido(resp, 0, qntOpcoes - 1))
					return resp;
				
				else
					System.out.println(Erro.escolha(false));
				
			}else System.out.println(Erro.escolha(true));
			
		}while (true);
	}
	
	
	
	/**
	 * Mensagem típica para inserção de novas informações
	 * @return Mensagem desenvolvida
	 */
	public static String inserir (){
		String mensagem = "Para o registrar é preciso saber:";
		
		return mensagem;
	}
	
	/**
	 * Mensagem típica para atualização de informações
	 * @param isPrimeiraVez Controle da mensagem a ser exibida
	 * @return Mensagem desenvolvida
	 */
	public static String atualizar (boolean isPrimeiraVez){
		String mensagem = "";
		
		if (isPrimeiraVez)
			mensagem = "Para o atualizar um registro é preciso saber, primeiramente, se há conhecimento do código";
		else
			mensagem = "Agora, para atualizar é preciso saber:";
			
		return mensagem;
	}
	
	/**
	 * Mensagem típica para exclusão de informações
	 * @param isPrimeiraVez Controle da mensagem a ser exibida
	 * @return Mensagem desenvolvida
	 */
	public static String deletar (boolean isPrimeiraVez){
		String mensagem = "";
		
		if (isPrimeiraVez)
			mensagem = "Para o deletar um registro é preciso saber, primeiramente, se há conhecimento do código";
		else
			mensagem = "Agora, para deletar é preciso saber:";
			
		return mensagem;
	}
	

	
	/**
	 * Mensagem típica para inserção de novas informações
	 * @return Mensagem desenvolvida
	 */
	public static String visualizar (){
		String mensagem = "A lista das instâncias existentes:";
		
		return mensagem;
	}
	
	
		
	/**
	 * Mensagem típica para aguarde
	 * @param operacao Operação que está sendo aguardada
	 * @return Mensagem desenvolvida
	 */
	public static String aguarde (String operacao){
		String mensagem = "\nPor enquanto, aguarde até o final da operação:\n"
						+ operacao;
		
		return mensagem;
	}
	
	/**
	 * Mensagem típica para sucesso numa operação
	 * @param operacao Operação que está sendo aguardada
	 * @return Mensagem desenvolvida
	 */
	public static String sucesso (String operacao){
		String mensagem = "\nA operação:\n"
						+ operacao + "\n"
						+ "Foi finalizada com sucesso!\n";
		
		return mensagem;
	}
	
	/**
	 * Mensagem para aguarde o acionar de uma tecla
	 * @return Mensagem desenvolvida
	 */
	public static String acionarTecla (){
		String mensagem = "\nPressione ENTER para continuar.";
		
		return mensagem;
	}
	
	/**
	 * Mensagem para inicio da simulação
	 * @return Mensagem desenvolvida
	 */
	public static String simular (){
		String mensagem = "\nPara a simulação, é preciso saber o período de vigência:";
		
		return mensagem;
	}

	
		
	/**
	 * Preenchimento de uma linha com asteriscos, conforme
	 * o tamanho de uma string
	 * @param texto String a ser considerada para o prenchimento
	 * @return Linha preenchida de asteriscos
	 */
	private static String preencherAsterisco (String texto){
		String titulo = "";
		
		for (int i = 0; i < texto.length() + 6; i++)
			titulo += "*";
		
		titulo += "\n";
		
		return titulo;
	}

	/**
	 * Requisitar o preenchimento de um valor; deve-se tentar
	 * enquanto for um valor inválido
	 * @param entradaDados Entrada de dados via terminal
	 * @return Valor válido
	 */
	public static float preencherLimite (Scanner entradaDados){
		System.out.println("* Limite Superior (apenas números 0-9, decimal separado por ponto):");
		
		return (float) Autentificacao.controleNumero(entradaDados, true);
	}
	
	/**
	 * Requisitar o preenchimento de um valor; deve-se tentar
	 * enquanto for um valor inválido
	 * @param entradaDados Entrada de dados via terminal
	 * @return Valor válido
	 */
	public static float preencherAliquota (Scanner entradaDados){
		System.out.println("* Alíquota (apenas números 0-9, decimal separado por ponto, entre 0 e 1):");
		
		return (float) Autentificacao.controleNumero(entradaDados, true, 0, 1);
	}
	
	/**
	 * Requisitar o preenchimento de um valor; deve-se tentar
	 * enquanto for um valor inválido
	 * @param entradaDados Entrada de dados via terminal
	 * @return Valor válido
	 */
	public static float preencherDesconto (Scanner entradaDados){
		System.out.println("* Desconto (apenas números 0-9, decimal separado por ponto):");
		
		return (float) Autentificacao.controleNumero(entradaDados, true);
	}
	
	/**
	 * Requisitar o preenchimento de um valor; deve-se tentar
	 * enquanto for um valor inválido
	 * @param entradaDados Entrada de dados via terminal
	 * @return Valor válido
	 */
	public static float preencherSalario (Scanner entradaDados){
		System.out.println("* Salario-base (apenas números 0-9, decimal separado por ponto):");
		
		return (float) Autentificacao.controleNumero(entradaDados, true);
	}
	
	/**
	 * Requisitar o preenchimento de um código; deve-se tentar
	 * enquanto for um código inválido
	 * @param entradaDados Entrada de dados via terminal
	 * @return Código válido
	 */
	public static int preencherCodigo (Scanner entradaDados){
		System.out.println("* Código (apenas números 0-9):");
		
		return (int) Autentificacao.controleNumero(entradaDados, false);
	}
	
	/**
	 * Requisitar o preenchimento da quantidade de vale-transporte;
	 * deve-se tentar enquanto for uma quantidade inválida
	 * @param entradaDados Entrada de dados via terminal
	 * @return Quantidade de vale transporte válida
	 */
	public static int preencerValeTransporte (Scanner entradaDados){
		System.out.println("* Vale transporte:");
		System.out.println("\t0 - Caso não queira;");
		System.out.println("\t1 - Caso queira.");
		System.out.println("Digite a sua escolha:");
		
		return (int) Autentificacao.controleNumero(entradaDados, false, 0, 2);
	}
	
	/**
	 * Requisitar o preenchimento de um nome; deve-se tentar
	 * enquanto for um nome inválido
	 * @param entradaDados Entrada de dados via terminal
	 * @return Nome válido
	 */
	public static String preencherNome (Scanner entradaDados){
		System.out.println("* Nome completo (alfabético, sem acentuação):");
		String linha;
		
		do{
			linha = entradaDados.nextLine();
						
			if (Autentificacao.isNome(linha)){
				return linha;
				
			}else	System.out.println(Erro.nome());
			
		}while (true);
	}
	
	
	/**
	 * Requisitar o preenchimento de um CPF; deve-se tentar
	 * enquanto for um CPF inválido
	 * @param entradaDados Entrada de dados via terminal
	 * @return CPF válido
	 */
	public static String preencheCpf (Scanner entradaDados){
		System.out.println("* CPF (somente os números e num total de 11):");
		String linha;
		
		do{
			linha = entradaDados.nextLine();
			
			//System.out.println("Linha -> " + linha);
			
			if (Autentificacao.isCpf(linha)){
				return Autentificacao.cpf(linha);
				
			}else	System.out.println(Erro.cpf());				
				
		}while(true);
	}

	/**
	 * Requisitar o preenchimento da data; deve-se tentar
	 * enquanto for uma data inválida
	 * @param entradaDados Entrada de dados via terminal
	 * @param tipo Tipo da data que está sendo requisitada, e.g.: ser 
	 * de nascimento ou de admissão
	 * @return Data válida
	 */
	public static String preencherData (Scanner entradaDados, String tipo){
		System.out.println("* Data de " + tipo + " (ddMMaaaa, só os números [0-9] nessa sequência):");
		String linha;
		
		do{
			linha = Autentificacao.data(entradaDados.nextLine());
			
			if (Autentificacao.isData(linha)){
				return linha;
				
			}else	System.out.println(Erro.data(tipo));				
				
		}while(true);
	}
	
	/**
	 * Requisitar o preenchimento do telefone; deve-se tentar
	 * enquanto for um telefone inválido
	 * @param entradaDados Entrada de dados via terminal
	 * @return Telefone válido
	 */
	public static String preencherTelefone (Scanner entradaDados){
		System.out.println("* Telefone (com o DDD, somente os números, num total de 12 digitos):");		
		String linha;
		
		do{
			linha = entradaDados.nextLine();
			
			if (Autentificacao.isTelefone(linha)){
				return Autentificacao.telefone(linha);
				
			}else	System.out.println(Erro.telefone());
				
		}while(true);
	}

	/**
	 * Requisitar o preenchimento do e-mail; deve-se tentar
	 * enquanto for um e-mail inválido
	 * @param entradaDados Entrada de dados via terminal
	 * @return E-mail válido
	 */
	public static String preencherEmail (Scanner entradaDados){
		System.out.println("* E-mail (exemplo@exemplo.com):");
		String linha;
		
		do{
			linha = entradaDados.nextLine();
			
			if (Autentificacao.isEmail(linha)){
				return linha;
			
			}else	System.out.println(Erro.email());
			
		}while(true);
	}
	
	/**
	 * Requisitar o preenchimento da profissão; deve-se tentar
	 * enquanto for um profissão inválida
	 * @param entradaDados Entrada de dados via terminal
	 * @param func Funcionário a ter a profissão atribuída
	 */
	public static void preencherProfissao (Scanner entradaDados, Funcionario func){
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
				int linha = Integer.parseInt(entradaDados.nextLine());
				
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
	}
	
}
