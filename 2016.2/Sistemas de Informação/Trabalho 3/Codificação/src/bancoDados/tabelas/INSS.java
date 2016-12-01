package bancoDados.tabelas;

import java.util.LinkedList;

import bancoDados.manipulacao.INSSM;

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
	 * Construção do INSS, por maneira default
	 */
	public INSS (){
		setCodigo(-1);
		
		setLimSuperior(0f);
		
		setAliquota(0f);
	}
	
	
	
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
	
	
	
	
	/**
	 * Determinar o código da faixa do INSS de um salário
	 * @param salarioAlvo Salário a ser considerado na determinação
	 * @return Código da faixa de INSS correspondente, onde para valores
	 * superiores a R$5189,83 será atribuído o código 4, caso contrário
	 * será buscado no BD
	 */
	public static int localizarCod (float salarioAlvo){
		if (salarioAlvo >= 5189.83f)
			return 4;
		
		INSSM inssM = new INSSM();
		LinkedList<INSS> listInss = inssM.lerCompleto();
		INSS inss;
		int codigo = -1;
		
		for (int pos = listInss.size() - 1; pos >= 0; pos--){
			inss = listInss.get(pos);
			
			if (salarioAlvo <= inss.getLimSuperior())
				codigo = inss.getCodigo();
			else break;
		}
		
		return codigo;
	}
	
	
	/**
	 * Deduzir do salário bruto o imposto do INSS, sabendo-se o código da
	 * faixa do INSS e o salário bruto
	 * @param codigoInss Código da faixa do INSS a ser considerada
	 * @param salarioBruto Salário bruto a sofrer a dedução do imposto ao INSS
	 * @return Salário líquido com a dedução do imposto, onde para os salários
	 * até R$5.189,83 a dedução será proporcional ao salário, respeitando a
	 * alíquota; caso contrário, será deduzido o valor fixo de R$570,88. 
	 */
	public static float deduzirAliquota (int codigoInss, float salarioBruto){
		if (codigoInss == 4)
			return salarioBruto - 570.88f;
		
		INSSM inssM = new INSSM();
		LinkedList<INSS> listInss = inssM.lerCompleto();
		INSS inss;
		
		float salarioDeduzido = 0f;
		
		for (int pos = 0; pos < listInss.size(); pos++){
			inss = listInss.get(pos);
			
			if (codigoInss == inss.getCodigo()){
				salarioDeduzido = salarioBruto * (1 - inss.aliquota);
				break;
			}
		}
		
		return salarioDeduzido;
	}
	
	/**
	 * Deduzir do salário bruto o imposto do INSS, sabendo-se o salário bruto
	 * @param salarioBruto Salário bruto a sofrer a dedução do imposto ao INSS
	 * @return Salário líquido com a dedução do imposto, onde para os salários
	 * até R$5.189,83 a dedução será proporcional ao salário, respeitando a
	 * alíquota; caso contrário, será deduzido o valor fixo de R$570,88.
	 */
	public static float deduzirAliquota (float salarioBruto){
		return deduzirAliquota(localizarCod(salarioBruto), salarioBruto);
	}
	
	/**
	 * Deduzir do salário-base o imposto do INSS
	 * @param profissao Profissão que será analisada a dedução do imposto
	 * @return Salário líquido com a dedução do imposto, onde para os salários
	 * até R$5.189,83 a dedução será proporcional ao salário, respeitando a
	 * alíquota; caso contrário, será deduzido o valor fixo de R$570,88.
	 */
	public static float deduzirAliquota (Profissao profissao){
		return deduzirAliquota(profissao.getInss_codigo(), profissao.getSalarioBase());
	}
	
	
	
	/**
	 * Inserção das alíquotas do INSS default que devem constar no BD
	 */
	public static void povoar (){
		INSSM inssM = new INSSM();
		INSS inss;
		
		inss = new INSS();
		inss.setCodigo(1);
		inss.setLimSuperior(1556.94f);
		inss.setAliquota(.08f);
		inssM.inserir(inss);
		
		inss = new INSS();
		inss.setCodigo(2);
		inss.setLimSuperior(2594.92f);
		inss.setAliquota(.09f);
		inssM.inserir(inss);
		
		inss = new INSS();
		inss.setCodigo(3);
		inss.setLimSuperior(5189.82f);
		inss.setAliquota(.11f);
		inssM.inserir(inss);
	}
}
