package bancoDados.tabelas;

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
	private String telefone;
	private String email;
	private String dataAdm;
	private int qntValeTransp;
	private int codProf;
	private int codProfInss;
	private int codProfIrrf;
	
	
	
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
	
	
}
