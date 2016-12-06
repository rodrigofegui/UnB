package bancoDados.tabelas;

import principal.Principal;
import trabalhoFeliz.Empregado;

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
	private int funcMat;
	private float inss;
	private float irrf;
	private float ferias;
	private float decTerceiro;	
	private float faltas;
	private float valeTransporte;
	private String holerite;
	
	
	/**
	 * Construção do Holerite, por maneira default
	 */
	public Holerite (){
		setCodigo(-1);
		
		setDataRef("0000-00-00");
		
		setSalLiq(0f);
		
		setFaltas(0);
		
		setFuncMat(-1);
		
		setHolerite("");
	}
	
	
	
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
	 */
	public void setSalLiq() {
		this.salLiq = getInss() + getIrrf() + getFaltas()
					+ getFerias() + getDecTerceiro()
					+ getValeTransporte();
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
	public float getFaltas() {
		return faltas;
	}
	
	/**
	 * Atribuir valor às faltas associadas à Holerite
	 * @param faltas As faltas associadas ser atribuída
	 */
	public void setFaltas(float faltas) {
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
		
	/**
	 * Valor atribuído à dedução do INSS
	 * @return A dedução do INSS
	 */
	public float getInss() {
		return inss;
	}
	



	/**
	 * Atribuir valor à dedução do INSS
	 * @param inss A dedução do INSS a ser atribuída
	 */
	public void setInss(float inss) {
		this.inss = inss;
	}
	



	/**
	 * Valor atribuído à dedução do IRRF
	 * @return A dedução do IRRF
	 */
	public float getIrrf() {
		return irrf;
	}
	



	/**
	 * Atribuir valor à dedução do IRRF
	 * @param irrf A dedução do IRRF a ser atribuída
	 */
	public void setIrrf(float irrf) {
		this.irrf = irrf;
	}
	



	/**
	 * Valor atribuído ao bônus das férias
	 * @return O bônus das ferias
	 */
	public float getFerias() {
		return ferias;
	}

	/**
	 * Atribuir valor ao bônus das férias
	 * @param ferias O bônus das férias a ser atribuído
	 */
	public void setFerias(float ferias) {
		this.ferias = ferias;
	}
	
	/**
	 * Valor atribuído ao bônus do 13º Salário
	 * @return O 13º salário
	 */
	public float getDecTerceiro() {
		return decTerceiro;
	}
	



	/**
	 * Atribuir valor ao bônus do 13º Salário
	 * @param decTerceiro O 13º salário a ser atribuído
	 */
	public void setDecTerceiro(float decTerceiro) {
		this.decTerceiro = decTerceiro;
	}
	



	/**
	 * Valor atribuído ao desconto do vale transporte
	 * @return O desconto do vale transporte
	 */
	public float getValeTransporte() {
		return valeTransporte;
	}
	



	/**
	 * Atribuir valor ao desconto do vale transporte
	 * @param valeTransporte O desconto do vale transporte a ser atribuído
	 */
	public void setValeTransporte(float valeTransporte) {
		this.valeTransporte = valeTransporte;
	}
	



	/**
	 * Valor atribuído à holerite, em si
	 * @return A holerite, em si
	 */
	public String getHolerite() {
		return holerite;
	}

	/**
	 * Atribuir valor à holerite, em si
	 * @param holerite A holerite a ser atribuída
	 */
	public void setHolerite(String holerite) {
		this.holerite = holerite;
	}



	/**
	 * Geração da Holerite 
	 * @param empregado Funcionário a ser analisado gerado a holerite
	 * @param salBase Salário base para a determinação de valores
	 */
	public void gerar(Empregado empregado, float salBase){
		String holerite = "";
		
		holerite =  "Empresa: TrabalhoFeliz\n";
		holerite += "CNPJ: 00.000.000/0000-01\n\n";
		
		holerite += "Holerite:\n";
		holerite += "\tData Ref.:\t" + getDataRef() + "\n";
		holerite += "\tSal. Base:\tR$" + Principal.FORMATAR_FLOAT.format(salBase) + "\n";
		holerite += "\tSal. Líq:\tR$" + Principal.FORMATAR_FLOAT.format(getSalLiq()) + "\n\n";
		
		holerite += "Funcionário:\n";
		holerite += "\tMatrícula:\t\t" + getFuncMat() + "\n";
		holerite += "\tNome:\t\t\t" + empregado.getFunc().getNome() + "\n";
		holerite += "\tCod. Cargo:\t\t" + empregado.getFunc().getCodProf() + "\n";
		holerite += "\tQnt. Faltas:\t" + empregado.getFaltas() + "\n\n";
		
		holerite += "Detalhamento:\n";
		holerite += "\tInss\t\t(-): R$" + Principal.FORMATAR_FLOAT.format(Math.abs(getInss())) + "\n";
		holerite += "\tIrrf\t\t(-): R$" + Principal.FORMATAR_FLOAT.format(Math.abs(getIrrf())) + "\n";
		holerite += "\tFaltas\t\t(-): R$" + Principal.FORMATAR_FLOAT.format(Math.abs(getFaltas())) + "\n";
		holerite += "\tVale Trans.\t(-): R$" + Principal.FORMATAR_FLOAT.format(Math.abs(getValeTransporte())) + "\n";
		holerite += "\tFérias\t\t(+): R$" + Principal.FORMATAR_FLOAT.format(Math.abs(getFerias())) + "\n";
		holerite += "\t13º\t\t\t(+): R$" + Principal.FORMATAR_FLOAT.format(Math.abs(getDecTerceiro())) + "\n";
		
		
		setHolerite(holerite);
	}
}
