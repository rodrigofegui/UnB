package bancoDados.tabelas;

import java.util.LinkedList;

import bancoDados.manipulacao.IRRFM;

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
	 * Construção do IRRF, por maneira default
	 */
	public IRRF (){
		setCodigo(-1);
		
		setLimSuperior(0f);
		
		setAliquota(0f);
		
		setDesconto(0f);
	}
	
	
	
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
	
	
	
	
	/**
	 * Determinar o código da faixa do IRRF de um salário
	 * @param salarioAlvo Salário a ser considerado na determinação
	 * @return Código da faixa de IRRF correspondente
	 */
	public static int localizarCod (float salarioAlvo){
		IRRFM irrfM = new IRRFM ();
		LinkedList<IRRF> listIrrf = irrfM.lerCompleto();
		IRRF irrf;
		int codigo = -1;
		
		for (int pos = listIrrf.size() - 1; pos >= 0 ; pos--){
			irrf = listIrrf.get(pos);
			
			if (salarioAlvo <= irrf.getLimSuperior())
				codigo = irrf.getCodigo();
			else break;
		}
		
		
		return codigo;
	}
	
	/**
	 * Inserção das alíquotas do IRRF default que devem constar no BD
	 */
	public static void povoar (){
		IRRFM irrfM = new IRRFM();
		IRRF irrf;
		
		irrf = new IRRF();
		irrf.setCodigo(1);
		irrf.setLimSuperior(1903.98f);
		irrf.setDesconto(0f);
		irrfM.inserir(irrf);
		
		irrf = new IRRF();
		irrf.setCodigo(2);
		irrf.setLimSuperior(2826.65f);
		irrf.setAliquota(.075f);
		irrf.setDesconto(142.80f);
		irrfM.inserir(irrf);
		
		irrf = new IRRF();
		irrf.setCodigo(3);
		irrf.setLimSuperior(3751.05f);
		irrf.setAliquota(.15f);
		irrf.setDesconto(354.80f);
		irrfM.inserir(irrf);
		
		irrf = new IRRF();
		irrf.setCodigo(4);
		irrf.setLimSuperior(4664.68f);
		irrf.setAliquota(.225f);
		irrf.setDesconto(636.13f);
		irrfM.inserir(irrf);
		
		irrf = new IRRF();
		irrf.setCodigo(5);
		irrf.setLimSuperior(999999999999.99f);
		irrf.setAliquota(.275f);
		irrf.setDesconto(869.36f);
		irrfM.inserir(irrf);
	}
}
