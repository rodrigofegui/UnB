package bancoDados.tabelas;

/**
 * Classe responsável pela implementação da tabela homônima do Banco de Dados 
 * @author	Rodrigo Guimarães
 * @version	1.0
 * @since	29/11/2016
 */
public class INSS {
	private int codigo;
	private float limSuperior;
	private float aliquota;
	
	
	
	/**
	 * Valor atribuído ao código da faixa do INSS
	 * @return O codigo da faixa
	 */
	public int getCodigo() {
		return codigo;
	}
	
	/**
	 * Atribuir valor ao código da faixa do INSS
	 * @param codigo O codigo a ser atribuído
	 */
	public void setCodigo(int codigo) {
		this.codigo = codigo;
	}


	/**
	 * Valor atribuído ao limite superior da faixa do INSS
	 * @return O limite superior da faixa do INSS
	 */
	public float getLimSuperior() {
		return limSuperior;
	}
	

	/**
	 * Atribuir valor o limite superior da faixa do INSS
	 * @param limSuperior O limite superior a ser atribuído
	 */
	public void setLimSuperior(float limSuperior) {
		this.limSuperior = limSuperior;
	}
	

	/**
	 * Valor atribuído à alíquota da faixa do INSS
	 * @return A alíquota da faixa do INSS
	 */
	public float getAliquota() {
		return aliquota;
	}
	

	/**
	 * Atribuir valor à alíquota da faixa do INSS
	 * @param aliquota A alíquota a ser atribuída
	 */
	public void setAliquota(float aliquota) {
		this.aliquota = aliquota;
	}
	
}
