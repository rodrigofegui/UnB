package bancoDados.tabelas;

import java.util.LinkedList;
import java.util.Scanner;

import bancoDados.manipulacao.DisciplinaM;
import gui.Mensagem;
import gui.terminal.JanelasT;
import gui.terminal.Textual;

/**
 * Classe responsável pela implementação da tabela homônima do Banco de Dados 
 * @author	Rodrigo Guimarães
 * @version	1.0
 * @since	29/11/2016
 */
public class Disciplina {
	private int codigo;
	private String descricao;

	
	
	/**
	 * Construção do Disciplina, por maneira default
	 */
	public Disciplina(){
		setCodigo(-1);
		
		setDescricao("");
	}
	
	
	
	/**
	 * Valor atribuído ao código da Disciplina
	 * @return O código da disciplina
	 */
	public int getCodigo() {
		return codigo;
	}
	
	/**
	 * Atribuir valor ao código da Disciplina
	 * @param codigo O código a ser atribuído
	 */
	public void setCodigo(int codigo) {
		this.codigo = codigo;
	}
	
	/**
	 * Valor atribuído à descrição da Disciplina
	 * @return A descricao da Disciplina
	 */
	public String getDescricao() {
		return descricao;
	}
	
	/**
	 * Atribuir valor à descrição da Disciplina
	 * @param descricao A descricao a ser atribuída
	 */
	public void setDescricao(String descricao) {
		this.descricao = descricao;
	}
		
	
	
	/**
	 * Inserção das Disciplinas default que devem constar no BD
	 */
	public static void povoar (){
		DisciplinaM.inserir("Matematica");
		DisciplinaM.inserir("Portugues");
		DisciplinaM.inserir("Geografia");
		DisciplinaM.inserir("Historia");
		DisciplinaM.inserir("Biologia");
		DisciplinaM.inserir("Fisica");
	}

	/**
	 * Representação inteligível ao usuário
	 * @return Representação formatada
	 */
	public String toString (){
		String toString = "" + getCodigo() + " - " + getDescricao();
		
		return toString;
	}

	
	
	/**
	 * Gerenciamento da Edição da tabela Disciplina no BD
	 * @param entradaDados Entrada de dados via terminal
	 * @param opcao Opção de edição, sendo:
	 * <h1> 1 - Inserir;
	 * <h1> 2 - Atualizar;
	 * <h1> 3 - Visualizar;
	 * <h1> 4 - Deletar;
	 */
	public static void gerenciarEdicao (Scanner entradaDados, int opcao){
		switch (opcao){
			case 1:
				gerenciarInserir(entradaDados);
				break;
			case 2:
				gerenciarAtualizar (entradaDados);
				break;
			case 3:
				gerenciarVisualizar(entradaDados, true);
				break;
			case 4:
				gerenciarDeletar(entradaDados);
				break;
		}
		
		Textual.aguardeTecla(entradaDados);
	}
	
	/**
	 * Gerenciamento das opção de inserir uma nova Disciplina
	 * @param entradaDados Entrada de dados via terminal
	 */
	private static void gerenciarInserir (Scanner entradaDados){
		Disciplina disc = new Disciplina();
		String operacao = "Inserir Disciplina";
		
		JanelasT.getJEditarInserirTabela("Discplina");
		
		disc = coletarInfo(entradaDados, false);
		
		System.out.println(Mensagem.aguarde(operacao));
		
		DisciplinaM.inserir(disc);
		
		System.out.println(Mensagem.sucesso(operacao));
	}
	
	/**
	 * Gerenciamento das opção de atualizar uma Disciplina
	 * @param entradaDados Entrada de dados via terminal
	 */
	private static void gerenciarAtualizar (Scanner entradaDados){
		Disciplina disc = new Disciplina();
		String operacao = "Atualizar Disciplina";
		
		ctrlVisualizar(entradaDados, true);
		
		System.out.println(Mensagem.atualizar(false));
		
		disc = coletarInfo(entradaDados, true);
		
		System.out.println(Mensagem.aguarde(operacao));
		
		DisciplinaM.atualizar(disc);
		
		System.out.println(Mensagem.sucesso(operacao));
	}
	
	/**
	 * Gerenciamento das opção de visualizar as disciplinas existentes
	 * @param entradaDados Entrada de dados via terminal
	 * @param isFull Verificando se a exibição desta opção é completa ou não.
	 * Sendo true, incluirá o título na janela; caso contrário, não
	 */
	private static void gerenciarVisualizar (Scanner entradaDados, boolean isFull){
		if (isFull)
			JanelasT.getJEditarVisualizarTabela("Discplina");
		
		LinkedList<Disciplina> disciplinas = DisciplinaM.lerCompleto();
		Disciplina disc;
		
		System.out.println("Código - Descrição");
		for (int pos = 0; pos < disciplinas.size(); pos++){
			disc = disciplinas.get(pos);
			
			System.out.println(disc.toString());
		}
	}
	
	/**
	 * Gerenciamento das opção de exclusão uma Disciplina
	 * @param entradaDados Entrada de dados via terminal
	 */
	private static void gerenciarDeletar (Scanner entradaDados){
		Disciplina disc = new Disciplina();
		String operacao = "Deletar Disciplina";
		
		ctrlVisualizar(entradaDados, false);
		
		System.out.println(Mensagem.deletar(false));
		
		disc.setCodigo(Mensagem.preencherCodigo(entradaDados));
		
		System.out.println(Mensagem.aguarde(operacao));
		
		DisciplinaM.deletar(disc);
		
		System.out.println(Mensagem.sucesso(operacao));
	}
	
	/**
	 * Controle de visualização de dados fora da janela principal
	 * @param entradaDados Entrada de dados via terminal
	 * @param isAtualizar Verificação qual a origem do pedido.
	 * Sendo true, está contido na janela de atualização; caso contrário, na de exclusão
	 */
	private static void ctrlVisualizar (Scanner entradaDados, boolean isAtualizar){
		int escolha = 0;
		
		if (isAtualizar)
			escolha = Mensagem.questionaOpcoes(entradaDados, JanelasT.getJEditarAtualizarTabela("Disciplina"));
		else
			escolha = Mensagem.questionaOpcoes(entradaDados, JanelasT.getJEditarDeletarTabela("Disciplina"));
		
		if (escolha == 1)
			gerenciarVisualizar(entradaDados, false);
	}
	
	/**
	 * Aquisição das informações cruciais, via terminal
	 * @param entradaDados Entrada de dados via terminal
	 * @param codigoTambem Verificação se a aquisição do código é necessária
	 * @return Disciplina com as informações colidas
	 */
	private static Disciplina coletarInfo (Scanner entradaDados, boolean codigoTambem){
		Disciplina disc = new Disciplina();
		
		if (codigoTambem)
			disc.setCodigo(Mensagem.preencherCodigo(entradaDados));
		
		disc.setDescricao(Mensagem.preencherNome(entradaDados));
		
		return disc;
	}
}
