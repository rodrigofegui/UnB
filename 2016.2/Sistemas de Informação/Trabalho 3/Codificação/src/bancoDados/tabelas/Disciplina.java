package bancoDados.tabelas;

import bancoDados.manipulacao.DisciplinaM;

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
		DisciplinaM discM = new DisciplinaM();
		
		discM.inserir("Matemática");
		discM.inserir("Português");
		discM.inserir("Geografia");
		discM.inserir("História");
		discM.inserir("Biologia");
		discM.inserir("Física");
	}
}
