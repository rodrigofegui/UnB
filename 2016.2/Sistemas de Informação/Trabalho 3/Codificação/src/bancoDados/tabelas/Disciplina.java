package bancoDados.tabelas;

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
}
