package gui.terminal;

import java.util.LinkedList;
import java.util.Scanner;

import gui.Mensagem;

/**
 * Classe responsável pela janelas de comunicação, via terminal
 * @author	Rodrigo Guimarães
 * @version	1.0
 * @since	03/12/2016
 */
public abstract class JanelasT {
	/**
	 * Janela principal da aplicação
	 * @return Quantidade de opções disponíveis na janela
	 */
	public static int getJPrincipal (){
		Textual.limpaTela();
		
		System.out.println(Mensagem.tituloJanela());
		
		LinkedList<Object> opcoes = opJPrincipal();
		System.out.println(opcoes.get(1));
		
		return (int) opcoes.get(0);
	}
	
	/**
	 * Janela das edições da aplicação
	 * @return Quantidade de opções disponíveis na janela
	 */
	public static int getJEditar (){
		Textual.limpaTela();
		
		System.out.println(Mensagem.tituloJanela("Editar"));
		
		LinkedList<Object> opcoes = opJEditar();
		System.out.println(opcoes.get(1));
		
		return (int) opcoes.get(0);
	}
	
	/**
	 * Janela da simulação da aplicação
	 * @return Quantidade de opções disponíveis na janela
	 */
	public static int getJSimular (){
		Textual.limpaTela();
		
		System.out.println(Mensagem.tituloJanela("Simular"));
		
		System.out.println(Mensagem.simular());
		
		LinkedList<Object> opcoes = opJSimular();
		System.out.println(opcoes.get(1));
		
		return (int) opcoes.get(0);
	}
	
	/**
	 * Janela das explicações da aplicação
	 * @param entradaDados Entrada de dados via terminal
	 */
	public static void getJHelp(Scanner entradaDados){
		Textual.limpaTela();
		
		System.out.println(Mensagem.tituloJanela("Help"));
		
		System.out.println("Editar 	- São dispostas as opções de inserir/atualizar/");
		System.out.println("        visualizar/deletar sobre algumas tabelas");
		System.out.println("Simular	- Representa a simulação do sistema como um todo.");
		System.out.println("        Realizando o gerenciamento das holerites, para um");
		System.out.println("        período de tempo específico.");
		
		Textual.aguardeTecla(entradaDados);
	}
	
	
	/**
	 * Janela das inserções da aplicação
	 * @return Quantidade de opções disponíveis na janela
	 */
	public static int getJEditarInserir (){
		Textual.limpaTela();
		
		System.out.println(Mensagem.tituloJanela("Editar/Inserir"));
		
		LinkedList<Object> opcoes = opTabelas();
		System.out.println(opcoes.get(1));
		
		return (int) opcoes.get(0);
	}
	
	/**
	 * Janela das atualizações da aplicação
	 * @return Quantidade de opções disponíveis na janela
	 */
	public static int getJEditarAtualizar (){
		Textual.limpaTela();
		
		System.out.println(Mensagem.tituloJanela("Editar/Atualizar"));
		
		LinkedList<Object> opcoes = opTabelas();
		System.out.println(opcoes.get(1));
		
		return (int) opcoes.get(0);
	}
	
	/**
	 * Janela de visualização da aplicação
	 * @return Quantidade de opções disponíveis na janela
	 */
	public static int getJEditarVisualizar (){
		Textual.limpaTela();
		
		System.out.println(Mensagem.tituloJanela("Editar/Visualizar"));
		
		LinkedList<Object> opcoes = opTabelas();
		System.out.println(opcoes.get(1));
		
		return (int) opcoes.get(0);
	}
	
	/**
	 * Janela das exclusões da aplicação
	 * @return Quantidade de opções disponíveis na janela
	 */
	public static int getJEditarDeletar (){
		Textual.limpaTela();
		
		System.out.println(Mensagem.tituloJanela("Editar/Deletar"));
		
		LinkedList<Object> opcoes = opTabelas();
		System.out.println(opcoes.get(1));
		
		return (int) opcoes.get(0);
	}
	
	
	
	/**
	 * Janela de inserção numa tabela fim
	 * @param nomeTB Descrição da tabela que a inserção está sendo operada
	 */
	public static void getJEditarInserirTabela (String nomeTB){
		Textual.limpaTela();
		
		System.out.println(Mensagem.tituloJanela("Editar/Inserir/" + nomeTB));
		
		System.out.println(Mensagem.inserir());
	}
	
	/**
	 * Janela de atualizar numa tabela fim
	 * @param nomeTB Descrição da tabela que a inserção está sendo operada
	 * @return Quantidade de opções disponíveis na janela
	 */
	public static int getJEditarAtualizarTabela (String nomeTB){
		Textual.limpaTela();
		
		System.out.println(Mensagem.tituloJanela("Editar/Atualizar/" + nomeTB));
		
		System.out.println(Mensagem.atualizar(true));
		
		LinkedList<Object> opcoes = opVisualizar();
		System.out.println(opcoes.get(1));
		
		return (int) opcoes.get(0);
	}
	
	/**
	 * Janela de visualização numa tabela fim
	 * @param nomeTB Descrição da tabela que a inserção está sendo operada
	 */
	public static void getJEditarVisualizarTabela (String nomeTB){
		Textual.limpaTela();
		
		System.out.println(Mensagem.tituloJanela("Editar/Visualizar/" + nomeTB));
		
		System.out.println(Mensagem.visualizar());
	}
	
	/**
	 * Janela de exclusão numa tabela fim
	 * @param nomeTB Descrição da tabela que a inserção está sendo operada
	 * @return Quantidade de opções disponíveis na janela
	 */
	public static int getJEditarDeletarTabela (String nomeTB){
		Textual.limpaTela();
		
		System.out.println(Mensagem.tituloJanela("Editar/Deletar/" + nomeTB));
		
		System.out.println(Mensagem.deletar(true));
		
		LinkedList<Object> opcoes = opVisualizar();
		System.out.println(opcoes.get(1));
		
		return (int) opcoes.get(0);
	}
	
	
	
	
	/**
	 * Opções de operações disponíveis na janela Principal
	 * @return Opções disponíveis
	 */
	public static LinkedList<Object> opJPrincipal (){
		LinkedList<Object> retorno = new LinkedList<Object> ();
		String opcoes = "1 - Editar\n"
					+	"2 - Simular\n"
					+	"3 - Help\n"
					+	"0 - Sair\n";
		
		retorno.add(4);
		retorno.add(opcoes);
				
		return retorno;
	}
	
	/**
	 * Opções de operações disponíveis na janela "Editar"
	 * @return Opções disponíveis
	 */
	public static LinkedList<Object> opJEditar (){
		LinkedList<Object> retorno = new LinkedList<Object> ();
		String opcoes = "1 - Inserir\n"
					+	"2 - Atualizar\n"
					+	"3 - Visualizar\n"
					+	"4 - Deletar\n"
					+	"0 - Voltar\n";
		
		retorno.add(5);
		retorno.add(opcoes);
				
		return retorno;
	}
	
	/**
	 * Opções de operações disponíveis na janela "Simular
	 * @return Opções disponíveis
	 */
	public static LinkedList<Object> opJSimular (){
		LinkedList<Object> retorno = new LinkedList<Object> ();
		String opcoes = "0 - Voltar\n"
					+	"Inteiro positivo - Meses de simulação (aconselhado 13, até 999)\n";
		
		retorno.add(999);
		retorno.add(opcoes);
				
		return retorno;
	}
	
	/**
	 * Opções de tabelas disponíveis
	 * @return Opções disponíveis
	 */
	public static LinkedList<Object> opTabelas (){
		LinkedList<Object> retorno = new LinkedList<Object> ();
		String opcoes = "1 - Disciplina\n"
					+	"2 - INSS\n"
					+	"3 - IRRF\n"
					+	"4 - Profissao\n"
					+	"5 - Funcionario\n"
					+	"0 - Voltar\n";
		
		retorno.add(6);
		retorno.add(opcoes);
				
		return retorno;
	}
	
	/**
	 * Opções de visualização dos dados, fora da janela própria.
	 * Comum nas opções de atualização e exclusão de dados
	 * @return Opções disponíveis
	 */
	public static LinkedList<Object> opVisualizar (){
		LinkedList<Object> retorno = new LinkedList<Object> ();
		String opcoes = "0 - Já sei o código\n"
					+	"1 - Relembre-me\n";
		
		retorno.add(2);
		retorno.add(opcoes);
				
		return retorno;
	}
}
