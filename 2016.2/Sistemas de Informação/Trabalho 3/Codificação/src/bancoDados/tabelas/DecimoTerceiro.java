package bancoDados.tabelas;

/**
 * Classe responsável pela implementação da tabela homônima do Banco de Dados 
 * @author	Rodrigo Guimarães
 * @version	1.0
 * @since	29/11/2016
 */
public class DecimoTerceiro {
	private int codigo;
	private boolean requisicao;
	private float parcelaAcumulada;
	private int contParcela;
	private int funcMat;
	
	
	
	/**
	 * Valor atribuído ao código do 13º
	 * @return O codigo do 13º
	 */
	public int getCodigo() {
		return codigo;
	}

	/**
	 * Atribuir valor ao código do 13º
	 * @param codigo O codigo a ser atribuído
	 */
	public void setCodigo(int codigo) {
		this.codigo = codigo;
	}

	/**
	 * Valor atribuído à requisição do 13º
	 * @return A requisicao do 13º
	 */
	public boolean isRequisitado() {
		return requisicao;
	}
	
	/**
	 * Atribuir valor à requisição do 13º
	 * @param requisicao A requisição a ser atribuída
	 */
	public void setRequisicao(boolean requisicao) {
		this.requisicao = requisicao;
	}
	
	/**
	 * Valor atribuído à parcela acumulada do 13º
	 * @return A parcela acumulada do 13º
	 */
	public float getParcelaAcumulada() {
		return parcelaAcumulada;
	}
	
	/**
	 * Atribuir valor à parcela acumulada do 13º
	 * @param parcelaAcumulada Aà parcela acumulada do 13º a ser atribuída
	 */
	public void setParcelaAcumulada(float parcelaAcumulada) {
		this.parcelaAcumulada = parcelaAcumulada;
	}
	
	/**
	 * Valor atribuído ao contador de parcelas pagas do 13º 
	 * @return O contador das parcelas pagas do 13º
	 */
	public int getContParcela() {
		return contParcela;
	}
	
	/**
	 * Atribuir valor ao contador de parcelas pagas do 13º
	 * @param contParcela O contador de parcelas pagas do 13º a ser atribuído
	 */
	public void setContParcela(int contParcela) {
		this.contParcela = contParcela;
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
	 * @param funcMat Aàmatrícula do funcionário a ser atribuída
	 */
	public void setFuncMat(int funcMat) {
		this.funcMat = funcMat;
	}
}
