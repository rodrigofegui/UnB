package bancoDados.tabelas;

import java.util.LinkedList;

import bancoDados.manipulacao.DecimoTerceiroM;
import trabalhoFeliz.Empregado;

/**
 * Classe responsável pela implementação da tabela homônima do Banco de Dados 
 * @author	Rodrigo Guimarães
 * @version	1.0
 * @since	29/11/2016
 */
public class DecimoTerceiro {
	public static final int MES_LIM_1 = 10;
	public static final int MES_LIM_2 = 11;
	public static final int LIM_PARCELAS = 2;
	private int codigo;
	private boolean requisicao;
	private float parcelaAcumulada;
	private int contParcela;
	private int funcMat;
	
	
	/**
	 * Construção do DecimoTerceiro, por maneira default
	 */
	public DecimoTerceiro(){
		setCodigo(-1);
		
		setRequisicao(false);
		
		setParcelaAcumulada(0f);
		
		setContParcela(0);
		
		setFuncMat(1);
	}
	
	public DecimoTerceiro (Holerite holerite){
		this ();
		
		setFuncMat(holerite.getFuncMat());
		setParcelaAcumulada(holerite.getSalLiq()/12f);
	}
	
	
	
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
	
	
	public static void atualizar (Holerite holerite){
		if (DecimoTerceiroM.isEmpty()){
			DecimoTerceiroM.inserir(new DecimoTerceiro(holerite));
			
		}else{
			LinkedList<DecimoTerceiro> decTers = DecimoTerceiroM.lerCompleto();
			boolean achou = false;
			
			for (int pos = 0; pos < decTers.size(); pos++){
				DecimoTerceiro decTer = decTers.get(pos);
				
				if (decTer.getFuncMat() == holerite.getFuncMat()){
					achou = true;
					decTer.setParcelaAcumulada(decTer.getParcelaAcumulada() + (holerite.getSalLiq()/12f));
					DecimoTerceiroM.atualizar(decTer);
					break;
				}
			}
			
			if (!achou)
				DecimoTerceiroM.inserir(new DecimoTerceiro(holerite));
		}
	}
}
