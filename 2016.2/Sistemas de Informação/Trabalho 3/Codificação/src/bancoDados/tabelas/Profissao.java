package bancoDados.tabelas;

import bancoDados.manipulacao.ProfissaoM;

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
		
		setDisciplina_codigo(-1);
		
		setInss_codigo(-1);
		
		setIrrf_codigo(-1);
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
	public static void povar (){
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
		profissao.setDescricao("Equipe alimentação");
		profissao.setSalarioBase(1620.10f);
		profissao.setInss_codigo(INSS.localizarCod(profissao.getSalarioBase()));
		profissao.setIrrf_codigo(IRRF.localizarCod(INSS.deduzirAliquota(profissao)));
		ProfissaoM.inserir(profissao);
		
		profissao = new Profissao();
		profissao.setDescricao("Equipe áudio-visual");
		profissao.setSalarioBase(2100.00f);
		profissao.setInss_codigo(INSS.localizarCod(profissao.getSalarioBase()));
		profissao.setIrrf_codigo(IRRF.localizarCod(INSS.deduzirAliquota(profissao)));
		ProfissaoM.inserir(profissao);
	}
}
