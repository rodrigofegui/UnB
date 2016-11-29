package bancoDados.tabelas;

/**
 * Classe responsável pela implementação da tabela homônima do Banco de Dados 
 * @author	Rodrigo Guimarães
 * @version	1.0
 * @since	29/11/2016
 */
public class Ferias {
	private int codigo;
	private String dataRef;
	private int funcMat;
	
	
	
	/**
	 * Valor atribuído ao código das Férias
	 * @return O codigo das Férias
	 */
	public int getCodigo() {
		return codigo;
	}


	/**
	 * Atribuir valor ao código das Férias
	 * @param codigo O codigo a ser atribuído
	 */
	public void setCodigo(int codigo) {
		this.codigo = codigo;
	}
	

	/**
	 * Valor atribuído à data de referência das Férias
	 * @return A data de referência das Férias
	 */
	public String getDataRef() {
		return dataRef;
	}
	
	/**
	 * Atribuir valor ao mês de referência das Férias
	 * @param dataRef O mês de referência a ser atribuído
	 */
	public void setDataRef(String dataRef) {
		this.dataRef = dataRef;
	}
	
	/**
	 * Valor atribuído à matricula do funcionário referenciado 
	 * @return A matrícula do funcionário
	 */
	public int getFuncMat() {
		return funcMat;
	}
	
	/**
	 * Atribuir valor à matricula do funcionário referenciado
	 * @param funcMat A matrícula funcionário referência a ser atribuído
	 */
	public void setFuncMat(int funcMat) {
		this.funcMat = funcMat;
	}
	
}
