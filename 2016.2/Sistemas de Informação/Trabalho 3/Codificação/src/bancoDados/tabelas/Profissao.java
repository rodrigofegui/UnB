package bancoDados.tabelas;

import java.util.LinkedList;
import java.util.Scanner;

import bancoDados.manipulacao.INSSM;
import bancoDados.manipulacao.IRRFM;
import bancoDados.manipulacao.ProfissaoM;
import gui.Mensagem;
import gui.terminal.JanelasT;
import gui.terminal.Textual;
import utilitario.Erro;

/**
 * Classe responsável pela implementação da tabela homônima do Banco de Dados 
 * @author	Rodrigo Guimarães
 * @version	1.0
 * @since	28/11/2016
 */
public class Profissao {
	private int codigo;
	private String descricao;
	private float salarioBase;
	private int disciplina_codigo;
	private int inss_codigo;
	private int irrf_codigo;
	
	
	
	/**
	 * Construção do Profissao, por maneira default
	 */
	public Profissao (){
		setCodigo(-1);
		
		setDescricao("");
		
		setSalarioBase(0f);
		
		setDisciplina_codigo(1);
		
		setInss_codigo(1);
		
		setIrrf_codigo(1);
	}
	
	
	
	/**
	 * Valor atribuído ao código da tabela, identificador
	 * único
	 * @return Código do item
	 */
	public int getCodigo() {
		return codigo;
	}
	
	/**
	 * Atribui valor ao código da tabela
	 * @param codigo Valor a ser atribuído
	 */
	public void setCodigo(int codigo) {
		this.codigo = codigo;
	}
	
	/**
	 * Valor atribuído à descrição da tabela
	 * @return Descrição do item
	 */
	public String getDescricao() {
		return descricao;
	}
	
	/**
	 * Atribui valor à descrição da tabela
	 * @param descricao Valor a ser atribuído
	 */
	public void setDescricao(String descricao) {
		this.descricao = descricao;
	}
	
	/**
	 * Valor atribuído ao salário base da tabela
	 * @return Salário base
	 */
	public float getSalarioBase() {
		return salarioBase;
	}
	
	/**
	 * Atribui valor ao salário base da tabela
	 * @param salarioBase Valor a ser atribuído
	 */
	public void setSalarioBase(float salarioBase) {
		this.salarioBase = salarioBase;
	}

	/**
	 * Valor atribuído ao código da tabela Disciplina, para
	 * construção de referência
	 * @return Código da tabela Disciplina
	 */
	public int getDisciplina_codigo() {
		return disciplina_codigo;
	}
	
	/**
	 * Atribui valor ao código da tabela disciplina
	 * @param disciplina_codigo Valor a ser atribuído
	 */
	public void setDisciplina_codigo(int disciplina_codigo) {
		this.disciplina_codigo = disciplina_codigo;
	}

	/**
	 * Valor atribuído ao código da tabela INSS, para
	 * construção de referência
	 * @return Código da tabela INSS
	 */
	public int getInss_codigo() {
		return inss_codigo;
	}

	/**
	 * Atribui valor ao código da tabela INSS
	 * @param inss_codigo Valor a ser atribuído
	 */
	public void setInss_codigo(int inss_codigo) {
		this.inss_codigo = inss_codigo;
	}

	/**
	 * Valor atribuído ao código da tabela IRRF, para
	 * construção de referência
	 * @return Código da tabela IRRF
	 */
	public int getIrrf_codigo() {
		return irrf_codigo;
	}

	/**
	 * Atribui valor ao código da tabela IRRF
	 * @param irrf_codigo Valor a ser atribuído
	 */
	public void setIrrf_codigo(int irrf_codigo) {
		this.irrf_codigo = irrf_codigo;
	}
	
	
	
	/**
	 * Inserção das profissões default que devem constar no BD, com base no site
	 * <a href="http://www.pisosalarial.com.br/salarios/tabela-salarial/">
	 * Piso Salarial - Tabela Salarial 2016</a>.<br>
	 */
	public static void povoar (){
		Profissao profissao;
		
		profissao = new Profissao();
		profissao.setDescricao("Professor presencial");
		profissao.setSalarioBase(2764.78f);
		profissao.setInss_codigo(INSS.localizarCod(profissao.getSalarioBase()));
		profissao.setIrrf_codigo(IRRF.localizarCod(INSS.deduzirAliquota(profissao)));
		ProfissaoM.inserir(profissao);
		
		profissao = new Profissao();
		profissao.setDescricao("Professor online");
		profissao.setSalarioBase(2764.78f);
		profissao.setInss_codigo(INSS.localizarCod(profissao.getSalarioBase()));
		profissao.setIrrf_codigo(IRRF.localizarCod(INSS.deduzirAliquota(profissao)));
		ProfissaoM.inserir(profissao);
		
		profissao = new Profissao();
		profissao.setDescricao("Equipe limpeza");
		profissao.setSalarioBase(2242.57f);
		profissao.setInss_codigo(INSS.localizarCod(profissao.getSalarioBase()));
		profissao.setIrrf_codigo(IRRF.localizarCod(INSS.deduzirAliquota(profissao)));
		ProfissaoM.inserir(profissao);
		
		profissao = new Profissao();
		profissao.setDescricao("Equipe alimentacao");
		profissao.setSalarioBase(1620.10f);
		profissao.setInss_codigo(INSS.localizarCod(profissao.getSalarioBase()));
		profissao.setIrrf_codigo(IRRF.localizarCod(INSS.deduzirAliquota(profissao)));
		ProfissaoM.inserir(profissao);
		
		profissao = new Profissao();
		profissao.setDescricao("Equipe audioVisual");
		profissao.setSalarioBase(2100.00f);
		profissao.setInss_codigo(INSS.localizarCod(profissao.getSalarioBase()));
		profissao.setIrrf_codigo(IRRF.localizarCod(INSS.deduzirAliquota(profissao)));
		ProfissaoM.inserir(profissao);
	}
	
	/**
	 * Representação inteligível ao usuário
	 * @return Representação formatada
	 */
	public String toString (){
		String toString = "" + getCodigo() + " - "
						+ getSalarioBase() + " - " 
						+ getInss_codigo() + " - "
						+ getIrrf_codigo();
		
		return toString;
	}

	
	
	/**
	 * Gerenciamento da Edição da tabela Profissao no BD
	 * @param entradaDados Entrada de dados via terminal
	 * @param opcao Opção de edição, sendo:
	 * <h1> 1 - Inserir;
	 * <h1> 2 - Atualizar;
	 * <h1> 3 - Visualizar;
	 * <h1> 4 - Deletar;
	 */
	public static void gerenciarEdicao (Scanner entradaDados, int opcao){
		if (INSSM.isEmpty()){
			System.out.println(Erro.dependencia("INSS"));
		
		}else if (IRRFM.isEmpty()){
			System.out.println(Erro.dependencia("IRRF"));

		}else{
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
		}
		
		Textual.aguardeTecla(entradaDados);
	}
	
	/**
	 * Gerenciamento das opção de inserir uma nova Profissão
	 * @param entradaDados Entrada de dados via terminal
	 */
	private static void gerenciarInserir (Scanner entradaDados){
		Profissao prof = new Profissao();
		String operacao = "Inserir Profissao";
		
		JanelasT.getJEditarInserirTabela("Profissao");
		
		prof = coletarInfo(entradaDados, false);
		
		System.out.println(Mensagem.aguarde(operacao));
		
		ProfissaoM.inserir(prof);
		
		System.out.println(Mensagem.sucesso(operacao));
	}
	
	/**
	 * Gerenciamento das opção de atualizar uma profissao
	 * @param entradaDados Entrada de dados via terminal
	 */
	private static void gerenciarAtualizar (Scanner entradaDados){
		Profissao prof = new Profissao();
		String operacao = "Atualizar Profissao";
		
		ctrlVisualizar(entradaDados, true);
		
		System.out.println(Mensagem.atualizar(false));
		
		prof = coletarInfo(entradaDados, true);
		
		System.out.println(Mensagem.aguarde(operacao));
		
		ProfissaoM.atualizar(prof);
		
		System.out.println(Mensagem.sucesso(operacao));
	}
	
	/**
	 * Gerenciamento das opção de visualizar as profissões existentes
	 * @param entradaDados Entrada de dados via terminal
	 * @param isFull Verificando se a exibição desta opção é completa ou não.
	 * Sendo true, incluirá o título na janela; caso contrário, não
	 */
	private static void gerenciarVisualizar (Scanner entradaDados, boolean isFull){
		if (isFull)
			JanelasT.getJEditarVisualizarTabela("Profissao");
		
		LinkedList<Profissao> profissoes = ProfissaoM.lerCompleto();
		Profissao prof;
		
		System.out.println("Código - Descrição - Salário Base - Cod. INSS - Cod. IRRF");
		for (int pos = 0; pos < profissoes.size(); pos++){
			prof = profissoes.get(pos);
			
			System.out.println(prof.toString());
		}
	}
	
	/**
	 * Gerenciamento das opção de exclusão uma profissão
	 * @param entradaDados Entrada de dados via terminal
	 */
	private static void gerenciarDeletar (Scanner entradaDados){
		Profissao prof = new Profissao();
		String operacao = "Deletar Profissao";
		
		ctrlVisualizar(entradaDados, false);
		
		System.out.println(Mensagem.deletar(false));
		
		prof.setCodigo(Mensagem.preencherCodigo(entradaDados));
		
		System.out.println(Mensagem.aguarde(operacao));
		
		ProfissaoM.deletar(prof);
		
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
			escolha = Mensagem.questionaOpcoes(entradaDados, JanelasT.getJEditarAtualizarTabela("Profissao"));
		else
			escolha = Mensagem.questionaOpcoes(entradaDados, JanelasT.getJEditarDeletarTabela("Profissao"));
		
		if (escolha == 1)
			gerenciarVisualizar(entradaDados, false);
	}
	
	/**
	 * Aquisição das informações cruciais, via terminal
	 * @param entradaDados Entrada de dados via terminal
	 * @param codigoTambem Verificação se a aquisição do código é necessária
	 * @return Profissão com as informações colidas
	 */
	private static Profissao coletarInfo (Scanner entradaDados, boolean codigoTambem){
		Profissao prof = new Profissao();
		
		if (codigoTambem)
			prof.setCodigo(Mensagem.preencherCodigo(entradaDados));
		
		prof.setDescricao(Mensagem.preencherNome(entradaDados));
		prof.setSalarioBase(Mensagem.preencherSalario(entradaDados));
		prof.setInss_codigo(INSS.localizarCod(prof.getSalarioBase()));
		prof.setIrrf_codigo(IRRF.localizarCod(INSS.deduzirAliquota(prof)));
		
		return prof;
	}
}
