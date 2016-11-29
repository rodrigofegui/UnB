package bancoDados.tabelas;

/**
 * Classe responsável pela implementação da tabela homônima do Banco de Dados 
 * @author	Rodrigo Guimarães
 * @version	1.0
 * @since	29/11/2016
 */
public class IRRF {
	private int codigo;
	private float limSuperior;
	private float aliquota;
	private float desconto;
	
	
	
	/**
	 * Valor atribuído ao código da faixa do IRRF
	 * @return O codigo da faixa do IRRF
	 */
	public int getCodigo() {
		return codigo;
	}
	
	
	/**
	 * Atribuir valor ao código da faixa do IRRF
	 * @param codigo O codigo a ser atribuído
	 */
	public void setCodigo(int codigo) {
		this.codigo = codigo;
	}
	
	/**
	 * Valor atribuído ao limite superior da faixa do IRRF
	 * @return O limite superior da faixa do IRRF
	 */
	public float getLimSuperior() {
		return limSuperior;
	}
	
	/**
	 * Atribuir valor o limite superior da faixa do IRRF
	 * @param limSuperior O limite superior a ser atribuído
	 */
	public void setLimSuperior(float limSuperior) {
		this.limSuperior = limSuperior;
	}

	/**
	 * Valor atribuído à aliquota da faixa do IRRF
	 * @return A alíquota da faixa do IRRF
	 */
	public float getAliquota() {
		return aliquota;
	}
	
	/**
	 * Atribuir valor à aliquota da faixa do IRRF
	 * @param aliquota A alíquota a ser atribuída
	 */
	public void setAliquota(float aliquota) {
		this.aliquota = aliquota;
	}

	/**
	 * Valor atribuído ao desconto da faixa do IRRF
	 * @return O desconto da faixa do IRRF
	 */
	public float getDesconto() {
		return desconto;
	}

	/**
	 * Atribuir valor ao desconto da faixa do IRRF
	 * @param desconto O desconto a ser atribuído
	 */
	public void setDesconto(float desconto) {
		this.desconto = desconto;
	}
	
	
}
