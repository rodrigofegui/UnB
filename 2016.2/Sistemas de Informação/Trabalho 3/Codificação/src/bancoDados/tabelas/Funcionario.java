package bancoDados.tabelas;

import java.util.LinkedList;
import java.util.Scanner;

import bancoDados.manipulacao.FuncionarioM;
import bancoDados.manipulacao.ProfissaoM;
import gui.Mensagem;
import gui.terminal.JanelasT;
import gui.terminal.Textual;
import utilitario.Erro;

/**
 * Classe responsável pela implementação da tabela homônima do Banco de Dados 
 * @author	Rodrigo Guimarães
 * @version	1.0
 * @since	29/11/2016
 */
public class Funcionario {
	private int matricula;
	private String cpf;
	private String nome;
	private String dataNasc;
	private boolean empregado;
	private String telefone;
	private String email;
	private String dataAdm;
	private int qntValeTransp;
	private int codProf;
	private int codProfInss;
	private int codProfIrrf;
	
	
	/**
	 * Construção do Funcionário, por maneira default
	 */
	public Funcionario (){
		setMatricula(-1);
		
		setCpf("000.000.000-00");
		
		setNome("Fulano");
		
		setDataNasc("00/00/0000");
		
		setEmpregado(true);
		
		setTelefone("000 0 0000 0000");
		
		setEmail("fulano@ciclano.com");
		
		setDataAdm("00/00/0000");
		
		setQntValeTransp(0);
		
		setCodProf(1);
		
		setCodProfInss(3);
		
		setCodProfIrrf(2);
	}
	
	
	
	/**
	 * Valor atribuído à matricula do Funcionário
	 * @return A matricula do Funcionário
	 */
	public int getMatricula() {
		return matricula;
	}
	
	/**
	 * Atribuir valor à matricula do Funcionário
	 * @param matricula A matricula a ser atribuída
	 */
	public void setMatricula(int matricula) {
		this.matricula = matricula;
	}
	
	/**
	 * Valor atribuído ao cpf do Funcionário
	 * @return O cpf do Funcionário
	 */
	public String getCpf() {
		return cpf;
	}
	
	/**
	 * Atribuir valor ao cpf do Funcionário
	 * @param cpf O cpf a ser atribuído
	 */
	public void setCpf(String cpf) {
		this.cpf = cpf;
	}
	
	/**
	 * Valor atribuído ao nome do Funcionário
	 * @return O nome do Funcionário
	 */
	public String getNome() {
		return nome;
	}
	
	/**
	 * Atribuir valor ao nome do Funcionário
	 * @param nome O nome a ser atribuído
	 */
	public void setNome(String nome) {
		this.nome = nome;
	}
	
	/**
	 * Valor atribuído à data de nascimento do Funcionário
	 * @return A data de nascimento do Funcionário
	 */
	public String getDataNasc() {
		return dataNasc;
	}
	
	/**
	 * Atribuir valor a data de nascimento do Funcionário
	 * @param dataNasc A data de nascimento a ser atribuída
	 */
	public void setDataNasc(String dataNasc) {
		this.dataNasc = dataNasc;
	}
	
	/**
	 * Valor atribuído à condicão de empregado
	 * @return True, se for empregado da empresa;
	 * false, caso contrário
	 */
	public boolean isEmpregado() {
		return empregado;
	}

	/**
	 * Atribuir valor à condição de empregado
	 * @param empregado A condição de empregado a ser atribuída
	 */
	public void setEmpregado(boolean empregado) {
		this.empregado = empregado;
	}



	/**
	 * Valor atribuído ao telefone do Funcionário
	 * @return O telefone do Funcionário
	 */
	public String getTelefone() {
		return telefone;
	}
	
	/**
	 * Atribuir valor ao telefone do Funcionário
	 * @param telefone O telefone a ser atribuído
	 */
	public void setTelefone(String telefone) {
		this.telefone = telefone;
	}
	
	/**
	 * Valor atribuído ao e-mail do Funcionário
	 * @return O email do Funcionário
	 */
	public String getEmail() {
		return email;
	}
	
	/**
	 * Atribuir valor ao e-mail do Funcionário
	 * @param email O email a ser atribuído
	 */
	public void setEmail(String email) {
		this.email = email;
	}
	
	/**
	 * Valor atribuído à data de admissão do Funcionário
	 * @return A data de admissão do Funcionário
	 */
	public String getDataAdm() {
		return dataAdm;
	}
	
	/**
	 * Atribuir valor à data de admissão do Funcionário
	 * @param dataAdm A data de admissão a ser atribuída
	 */
	public void setDataAdm(String dataAdm) {
		this.dataAdm = dataAdm;
	}
	
	/**
	 * Valor atribuído à quantidade de vale-transporte requisita
	 * por dia pelo Funcionário
	 * @return A quantidade vale-transporte diária requisitada
	 */
	public int getQntValeTransp() {
		return qntValeTransp;
	}
	
	/**
	 * Atribuir valor à quantidade de vale-transporte requisita
	 * por dia pelo Funcionário
	 * @param qntValeTransp A quantidade vale-transporte diária
	 * a ser atribuída
	 */
	public void setQntValeTransp(int qntValeTransp) {
		this.qntValeTransp = qntValeTransp;
	}
	
	/**
	 * Valor atribuído ao código da profissão do Funcionário
	 * @return O código da profissão do Funcionário
	 */
	public int getCodProf() {
		return codProf;
	}
	
	/**
	 * Atribuir valor ao código da profissão do Funcionário
	 * @param codProf O código da profissão a ser atribuído
	 */
	public void setCodProf(int codProf) {
		this.codProf = codProf;
	}
	
	/**
	 * Valor atribuído ao código da faixa do INSS associada à profissão do Funcionário
	 * @return O código da faixa do INSS associada à profissão do Funcionário
	 */
	public int getCodProfInss() {
		return codProfInss;
	}
	
	/**
	 * Atribuir valor ao código da faixa do INSS associada à profissão do Funcionário
	 * @param codProfInss O código da faixa do INSS associada à profissão do
	 * Funcionário a ser atribuído
	 */
	public void setCodProfInss(int codProfInss) {
		this.codProfInss = codProfInss;
	}
	
	/**
	 * Valor atribuído ao código da faixa do IRRF associada à profissão do Funcionário
	 * @return O código da faixa do IRRF associada à profissão do Funcionário
	 */
	public int getCodProfIrrf() {
		return codProfIrrf;
	}
	
	/**
	 * Atribuir valor ao código da faixa do IRRF associada à profissão do Funcionário
	 * @param codProfIrrf O código da faixa do IRRF associada à profissão do Funcionário a ser atribuído
	 */
	public void setCodProfIrrf(int codProfIrrf) {
		this.codProfIrrf = codProfIrrf;
	}
	
	
	
	/**
	 * Representação inteligível ao usuário
	 * @param isResumida Controle quanto a visualização dos dados, sendo
	 * resumido ou não
	 * @return Representação formatada
	 */
	public String toString (boolean isResumida){
		String toString = "" + getMatricula() + " - " 
						+ getNome() + " - ";
		
		if (!isResumida)
			toString   += getCpf() + " - "
						+ getDataNasc() + " - "
						+ isEmpregado() + " - "
						+ getTelefone() + " - "
						+ getEmail() + " - "
						+ getDataAdm() + " - "
						+ getQntValeTransp() + " - "
						+ getCodProf() + " - "
						+ getCodProfInss() + " - "
						+ getCodProfIrrf();
			
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
		if (ProfissaoM.isEmpty()){
			System.out.println(Erro.dependencia("Profissao"));
		
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
	 * Gerenciamento das opção de inserir um novo Funcionário
	 * @param entradaDados Entrada de dados via terminal
	 */
	private static void gerenciarInserir (Scanner entradaDados){
		Funcionario func = new Funcionario();
		String operacao = "Inserir Funcionario";
		
		JanelasT.getJEditarInserirTabela("Funcionario");
		
		func = coletarInfo(entradaDados, false);
		
		System.out.println(Mensagem.aguarde(operacao));
		
		FuncionarioM.inserir(func);
		
		System.out.println(Mensagem.sucesso(operacao));
	}
	
	/**
	 * Gerenciamento das opção de atualizar um Funcionário
	 * @param entradaDados Entrada de dados via terminal
	 */
	private static void gerenciarAtualizar (Scanner entradaDados){
		Funcionario func = new Funcionario();
		String operacao = "Atualizar Funcionario";
		
		ctrlVisualizar(entradaDados, true);
		
		System.out.println(Mensagem.atualizar(false));
		
		func = coletarInfo(entradaDados, true);
		
		System.out.println(Mensagem.aguarde(operacao));
		
		FuncionarioM.atualizar(func);
		
		System.out.println(Mensagem.sucesso(operacao));
	}
	
	/**
	 * Gerenciamento das opção de visualizar os funcionários existentes
	 * @param entradaDados Entrada de dados via terminal
	 * @param isFull Verificando se a exibição desta opção é completa ou não.
	 * Sendo true, incluirá o título na janela; caso contrário, não
	 */
	public static void gerenciarVisualizar (Scanner entradaDados, boolean isFull){
		String label = "Matrícula - Nome";
		if (isFull){
			label += "CPF - Data Nas. - isEmpreg. - Tel. - Email - Data Adm. - Qnt Val. - Cod. Prof. - Cod. INSS - Cod. IRRF";
			JanelasT.getJEditarVisualizarTabela("Funcionario");
		}
		
		LinkedList<Funcionario> funcionarios = FuncionarioM.lerCompleto();
		Funcionario func;
		
		System.out.println(label);
		for (int pos = 0; pos < funcionarios.size(); pos++){
			func = funcionarios.get(pos);
			
			System.out.println(func.toString(!isFull));
		}
	}
	
	/**
	 * Gerenciamento das opção de exclusão um funcionário
	 * @param entradaDados Entrada de dados via terminal
	 */
	private static void gerenciarDeletar (Scanner entradaDados){
		Funcionario func = new Funcionario();
		String operacao = "Deletar Funcionario";
		
		ctrlVisualizar(entradaDados, false);
		
		System.out.println(Mensagem.deletar(false));
		
		func.setMatricula(Mensagem.preencherCodigo(entradaDados));
		
		System.out.println(Mensagem.aguarde(operacao));
		
		FuncionarioM.deletar(func);
		
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
			escolha = Mensagem.questionaOpcoes(entradaDados, JanelasT.getJEditarAtualizarTabela("Funcionario"));
		else
			escolha = Mensagem.questionaOpcoes(entradaDados, JanelasT.getJEditarDeletarTabela("Funcionario"));
		
		if (escolha == 1)
			gerenciarVisualizar(entradaDados, false);
	}
	
	/**
	 * Aquisição das informações cruciais, via terminal
	 * @param entradaDados Entrada de dados via terminal
	 * @param codigoTambem Verificação se a aquisição do código é necessária
	 * @return Funcionario com as informações colidas
	 */
	private static Funcionario coletarInfo (Scanner entradaDados, boolean codigoTambem){
		Funcionario func = new Funcionario();
		
		if (codigoTambem)
			func.setMatricula(Mensagem.preencherCodigo(entradaDados));
		
		func.setCpf(Mensagem.preencheCpf(entradaDados));
		func.setNome(Mensagem.preencherNome(entradaDados));
		func.setDataNasc(Mensagem.preencherData(entradaDados, "Nascimento"));
		func.setTelefone(Mensagem.preencherTelefone(entradaDados));
		func.setEmail(Mensagem.preencherEmail(entradaDados));
		Mensagem.preencherProfissao(entradaDados, func);
		func.setDataAdm(Mensagem.preencherData(entradaDados, "Admissão"));
		func.setQntValeTransp(Mensagem.preencerValeTransporte(entradaDados));
		
		return func;
	}
}
