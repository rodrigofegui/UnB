package gui.terminal;

import java.util.Scanner;

import bancoDados.tabelas.Disciplina;
import bancoDados.tabelas.Funcionario;
import bancoDados.tabelas.INSS;
import bancoDados.tabelas.IRRF;
import bancoDados.tabelas.Profissao;
import gui.Mensagem;
import principal.Principal;
import trabalhoFeliz.DeptRH;

/**
 * Classe responsável pela implementação de uma interface de comunicação, via terminal
 * @author	Rodrigo Guimarães
 * @version	1.0
 * @since	01/12/2016
 */
public class Textual{
	public static final String TITULO = "TrabalhoFeliz";
	
	/**
	 * Construção do Textual, por maneira default
	 */
	public Textual() {
		int escolha = 0;
		
		do{
			escolha = Mensagem.questionaOpcoes(Principal.entradaDados, JanelasT.getJPrincipal());
			
			ctrlOpJPrincipal(Principal.entradaDados, escolha);
		}while (escolha != 0);
	}
		
	
	
	/**
	 * Controle das opções da janela principal
	 * @param entradaDados Entrada de dados via terminal
	 * @param escolha Escolha efetivada na janela principal
	 */
	private static void ctrlOpJPrincipal (Scanner entradaDados, int escolha){
		switch (escolha){
			case 1:
				operarEditar (entradaDados);
				break;
			case 2:
				operarSimular (entradaDados);
				break;
			case 3:
				JanelasT.getJHelp(entradaDados);
				break;
		}
	}
	
	/**
	 * Controle das opções da janela "Editar"
	 * @param entradaDados Entrada de dados via terminal
	 * @param escolha Escolha efetivada na janela
	 */
	private static void ctrlOpJEditar (Scanner entradaDados, int escolha){
		switch (escolha){
			case 1:
				operarEditarInserir (entradaDados);
				break;
			case 2:
				operarEditarAtualizar (entradaDados);
				break;
			case 3:
				operarEditarVisualizar (entradaDados);
				break;
			case 4:
				operarEditarDeletar (entradaDados);
				break;
		}
	}
	
	/**
	 * Controle das opções da janela "Editar/Inserir"
	 * @param entradaDados Entrada de dados via terminal
	 * @param escolha Escolha efetivada na janela
	 */
	private static void ctrlOpJEditarDescobramento (Scanner entradaDados, int escolha, int opcao){
		switch (escolha){
			case 1:
				Disciplina.gerenciarEdicao(entradaDados, opcao);
				break;
			case 2:
				INSS.gerenciarEdicao(entradaDados, opcao);
				break;
			case 3:
				IRRF.gerenciarEdicao(entradaDados, opcao);
				break;
			case 4:
				Profissao.gerenciarEdicao(entradaDados, opcao);
				break;
			case 5:
				Funcionario.gerenciarEdicao(entradaDados, opcao);
				break;
		}
	}

	/**
	 * Controle das opções da janela "Simular"
	 * @param entradaDados Entrada de dados via terminal
	 * @param escolha Escolha efetivada na janela
	 */
	private static void ctrlOpJSimular (Scanner entradaDados, int escolha){
		if (escolha > 0){
				System.out.println();
				DeptRH deptRH = new DeptRH();
				deptRH.simular(entradaDados, escolha);
		}
	}
	
	
	/**
	 * Operação de editar
	 * @param entradaDados Entrada de dados via terminal
	 */
	private static void operarEditar (Scanner entradaDados){
		int escolha = 0;
		
		do{
			escolha = Mensagem.questionaOpcoes(entradaDados, JanelasT.getJEditar());
			
			ctrlOpJEditar(entradaDados, escolha);
		}while (escolha != 0);
	}
			
	/**
	 * Operação de inserir
	 * @param entradaDados Entrada de dados via terminal
	 */
	private static void operarEditarInserir (Scanner entradaDados){
		int escolha = 0;
		
		do{
			escolha = Mensagem.questionaOpcoes(entradaDados, JanelasT.getJEditarInserir());
			
			ctrlOpJEditarDescobramento(entradaDados, escolha, 1);
		}while (escolha != 0);
	}
		
	/**
	 * Operação de atualizar
	 * @param entradaDados Entrada de dados via terminal
	 */
	private static void operarEditarAtualizar (Scanner entradaDados){
		int escolha = 0;
		
		do{
			escolha = Mensagem.questionaOpcoes(entradaDados, JanelasT.getJEditarAtualizar());
			
			ctrlOpJEditarDescobramento(entradaDados, escolha, 2);
		}while (escolha != 0);
	}
		
	/**
	 * Operação de visualizar
	 * @param entradaDados Entrada de dados via terminal
	 */
	private static void operarEditarVisualizar (Scanner entradaDados){
		int escolha = 0;
		
		do{
			escolha = Mensagem.questionaOpcoes(entradaDados, JanelasT.getJEditarVisualizar());
			
			ctrlOpJEditarDescobramento(entradaDados, escolha, 3);
		}while (escolha != 0);
	}
		
	/**
	 * Operação de deletar
	 * @param entradaDados Entrada de dados via terminal
	 */
	private static void operarEditarDeletar (Scanner entradaDados){
		int escolha = 0;
		
		do{
			escolha = Mensagem.questionaOpcoes(entradaDados, JanelasT.getJEditarDeletar());
			
			ctrlOpJEditarDescobramento(entradaDados, escolha, 4);
		}while (escolha != 0);
	}
	
	/**
	 * Operação de simular
	 * @param entradaDados Entrada de dados via terminal
	 */
	private static void operarSimular (Scanner entradaDados){
		int escolha = 0;
		
		do{
			escolha = Mensagem.questionaOpcoes(entradaDados, JanelasT.getJSimular());
			
			ctrlOpJSimular(entradaDados, escolha);
		}while (escolha != 0);
	}
	
	

	
	/**
	 * Limpeza da tela do terminal
	 */
	public static void limpaTela (){
		final String ANSI_CLS = "\u001b[2J";
        final String ANSI_HOME = "\u001b[H";
        System.out.print(ANSI_CLS + ANSI_HOME);
        System.out.flush();
	}
	
	/**
	 * Aguardar o acionar de alguma tecla
	 * @param entradaDados Entrada de dados via terminal
	 */
	public static void aguardeTecla (Scanner entradaDados){
		System.out.println(Mensagem.acionarTecla());
		entradaDados.nextLine();
	}
}
