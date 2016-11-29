package bancoDados.tabelas;

/**
 * Classe responsável pela implementação da tabela homônima do Banco de Dados 
 * @author	Rodrigo Guimarães
 * @version	1.0
 * @since	29/11/2016
 */
public class Holerite {
	private String dataRef;
	private float salLiq;
	private int codigo;
	private int faltas;
	private int funcMat;
	
	
	/**
	 * Valor atribuído à data de referência da Holerite
	 * @return A data de referência da Holerite
	 */
	public String getDataRef() {
		return dataRef;
	}
	
	/**
	 * Atribuir valor à data de referência da Holerite
	 * @param dataRef A data de referência a ser atribuída
	 */
	public void setDataRef(String dataRef) {
		this.dataRef = dataRef;
	}
	
	/**
	 * Valor atribuído ao salário líquido da Holerite
	 * @return O salário líquido
	 */
	public float getSalLiq() {
		return salLiq;
	}
	
	/**
	 * Atribuir valor ao salário líquido da Holerite
	 * @param salLiq O o salário líquido a ser atribuído
	 */
	public void setSalLiq(float salLiq) {
		this.salLiq = salLiq;
	}
	
	/**
	 * Valor atribuído ao código da Holerite
	 * @return O codigoo da Holerite
	 */
	public int getCodigo() {
		return codigo;
	}
	
	/**
	 * Atribuir valor ao código da Holerite
	 * @param codigo O o código a ser atribuído
	 */
	public void setCodigo(int codigo) {
		this.codigo = codigo;
	}
	
	/**
	 * Valor atribuído às faltas associadas à Holerite
	 * @return As faltas associadas à Holerite
	 */
	public int getFaltas() {
		return faltas;
	}
	
	/**
	 * Atribuir valor às faltas associadas à Holerite
	 * @param faltas As faltas associadas ser atribuída
	 */
	public void setFaltas(int faltas) {
		this.faltas = faltas;
	}
	
	/**
	 * Valor atribuído à matrícula do funcionário
	 * @return A matrícula do funcionário
	 */
	public int getFuncMat() {
		return funcMat;
	}
	
	/**
	 * Atribuir valor à matrícula do funcionário
	 * @param funcMat A matrícula do funcionário a ser atribuída
	 */
	public void setFuncMat(int funcMat) {
		this.funcMat = funcMat;
	}
	
	
}
