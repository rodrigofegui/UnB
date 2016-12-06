package bancoDados.tabelas;

import java.util.LinkedList;
import java.util.Scanner;

import bancoDados.manipulacao.INSSM;
import bancoDados.manipulacao.IRRFM;
import gui.Mensagem;
import gui.terminal.JanelasT;
import gui.terminal.Textual;

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
		LinkedList<IRRF> listIrrf = IRRFM.lerCompleto();
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
	 * Redução equivalente ao salário bruto do imposto do IRRF, sabendo-se o código da
	 * faixa do IRFF e o salário bruto
	 * @param codigoIrrf Código da faixa do IRRF a ser considerada
	 * @param salarioBruto Salário bruto a sofrer a dedução do imposto ao IRFF
	 * @return Desconto equivalente 
	 */
	public static float reducao (int codigoIrrf, float salarioBruto){
		LinkedList<IRRF> listIrrf = IRRFM.lerCompleto();
		IRRF irrf;
		
		float reducao = 0f;
		
		for (int pos = 0; pos < listIrrf.size(); pos++){
			irrf = listIrrf.get(pos);
			
			if (codigoIrrf == irrf.getCodigo()){
				reducao = irrf.getDesconto();
				break;
			}
		}
		
		return -reducao;
	}
	
	/**
	 * Redução equivalente ao salário bruto do imposto do IRRF, sabendo-se o código da
	 * faixa do IRFF e o salário bruto
	 * @param salarioBruto Salário bruto a sofrer a dedução do imposto ao IRFF
	 * @return Desconto equivalente 
	 */
	public static float reducao (float salarioBruto){
		return reducao(localizarCod(salarioBruto), salarioBruto);
	}
	
	
	/**
	 * Deduzir do salário bruto o imposto do IRRF, sabendo-se o código da
	 * faixa do IRFF e o salário bruto
	 * @param codigoIrrf Código da faixa do IRRF a ser considerada
	 * @param salarioBruto Salário bruto a sofrer a dedução do imposto ao IRFF
	 * @return Salário líquido com a dedução do imposto
	 */
	public static float deduzirAliquota (int codigoIrrf, float salarioBruto){
		return salarioBruto + reducao(codigoIrrf, salarioBruto);
	}
	
	/**
	 * Deduzir do salário bruto o imposto do IRRF, sabendo-se o código da
	 * faixa do IRFF e o salário bruto
	 * @param salarioBruto Salário bruto a sofrer a dedução do imposto ao IRFF
	 * @return Salário líquido com a dedução do imposto, respeitando os descontos
	 * pré-estabelecidos 
	 */
	public static float deduzirAliquota (float salarioBruto){
		return deduzirAliquota(localizarCod(salarioBruto), salarioBruto);
	}
	
	
	/**
	 * Inserção das alíquotas do IRRF default que devem constar no BD
	 */
	public static void povoar (){
		IRRF irrf;
		
		irrf = new IRRF();
		irrf.setCodigo(1);
		irrf.setLimSuperior(1903.98f);
		irrf.setDesconto(0f);
		IRRFM.inserir(irrf);
		
		irrf = new IRRF();
		irrf.setCodigo(2);
		irrf.setLimSuperior(2826.65f);
		irrf.setAliquota(.075f);
		irrf.setDesconto(142.80f);
		IRRFM.inserir(irrf);
		
		irrf = new IRRF();
		irrf.setCodigo(3);
		irrf.setLimSuperior(3751.05f);
		irrf.setAliquota(.15f);
		irrf.setDesconto(354.80f);
		IRRFM.inserir(irrf);
		
		irrf = new IRRF();
		irrf.setCodigo(4);
		irrf.setLimSuperior(4664.68f);
		irrf.setAliquota(.225f);
		irrf.setDesconto(636.13f);
		IRRFM.inserir(irrf);
		
		irrf = new IRRF();
		irrf.setCodigo(5);
		irrf.setLimSuperior(999999999999.99f);
		irrf.setAliquota(.275f);
		irrf.setDesconto(869.36f);
		IRRFM.inserir(irrf);
	}
	
	/**
	 * Representação inteligível ao usuário
	 * @return Representação formatada
	 */
	public String toString (){
		String toString = "" + getCodigo() + " - "
						+ getLimSuperior() + " - " 
						+ getAliquota() + " - "
						+ getDesconto();
		
		return toString;
	}

	
	
	/**
	 * Gerenciamento da Edição da tabela IRRF no BD
	 * @param entradaDados Entrada de dados via terminal
	 * @param opcao Opção de edição, sendo:
	 * <h1> 1 - Inserir;
	 * <h1> 2 - Atualizar;
	 * <h1> 3 - Visualizar;
	 * <h1> 4 - Deletar;
	 */
	public static void gerenciarEdicao (Scanner entradaDados, int opcao){
		switch (opcao){
			case 1:
				gerenciarInserir(entradaDados);
				break;
			case 2:
				gerenciarAtualizar (entradaDados);
				break;
			case 3:
				gerenciarVisualizar(entradaDados, true);
				break;
			case 4:
				gerenciarDeletar(entradaDados);
				break;
		}
		
		Textual.aguardeTecla(entradaDados);
	}
	
	/**
	 * Gerenciamento das opção de inserir uma nova faixa no IRRF
	 * @param entradaDados Entrada de dados via terminal
	 */
	private static void gerenciarInserir (Scanner entradaDados){
		IRRF irrf = new IRRF();
		String operacao = "Inserir IRRF";
		
		JanelasT.getJEditarInserirTabela("IRRF");
		
		irrf = coletarInfo(entradaDados, false);
		
		System.out.println(Mensagem.aguarde(operacao));
		
		IRRFM.inserir(irrf);
		
		System.out.println(Mensagem.sucesso(operacao));
	}
	
	/**
	 * Gerenciamento das opção de atualizar uma faia do IRRF
	 * @param entradaDados Entrada de dados via terminal
	 */
	private static void gerenciarAtualizar (Scanner entradaDados){
		IRRF irrf = new IRRF();
		String operacao = "Atualizar IRRF";
		
		ctrlVisualizar(entradaDados, true);
		
		System.out.println(Mensagem.atualizar(false));
		
		irrf = coletarInfo(entradaDados, true);
		
		System.out.println(Mensagem.aguarde(operacao));
		
		IRRFM.atualizar(irrf);
		
		System.out.println(Mensagem.sucesso(operacao));
	}
	
	/**
	 * Gerenciamento das opção de visualizar as faixas do IRRF existentes
	 * @param entradaDados Entrada de dados via terminal
	 * @param isFull Verificando se a exibição desta opção é completa ou não.
	 * Sendo true, incluirá o título na janela; caso contrário, não
	 */
	private static void gerenciarVisualizar (Scanner entradaDados, boolean isFull){
		if (isFull)
			JanelasT.getJEditarVisualizarTabela("IRRF");
		
		LinkedList<IRRF> listIrrf = IRRFM.lerCompleto();
		IRRF irrf;
		
		System.out.println("Código - Lim. Sup - Alíquota - Desconto");
		for (int pos = 0; pos < listIrrf.size(); pos++){
			irrf = listIrrf.get(pos);
			
			System.out.println(irrf.toString());
		}
	}
	
	/**
	 * Gerenciamento das opção de exclusão uma faixa do IRRF
	 * @param entradaDados Entrada de dados via terminal
	 */
	private static void gerenciarDeletar (Scanner entradaDados){
		IRRF irrf = new IRRF();
		String operacao = "Deletar IRRF";
		
		ctrlVisualizar(entradaDados, false);
		
		System.out.println(Mensagem.deletar(false));
		
		irrf.setCodigo(Mensagem.preencherCodigo(entradaDados));
		
		System.out.println(Mensagem.aguarde(operacao));
		
		IRRFM.deletar(irrf);
		
		System.out.println(Mensagem.sucesso(operacao));
	}
	
	/**
	 * Controle de visualização de dados fora da janela principal
	 * @param entradaDados Entrada de dados via terminal
	 * @param isAtualizar Verificação qual a origem do pedido.
	 * Sendo true, está contido na janela de atualização; caso contrário, na de exclusão
	 */
	private static void ctrlVisualizar (Scanner entradaDados, boolean isAtualizar){
		int escolha = 0;
		
		if (isAtualizar)
			escolha = Mensagem.questionaOpcoes(entradaDados, JanelasT.getJEditarAtualizarTabela("IRRF"));
		else
			escolha = Mensagem.questionaOpcoes(entradaDados, JanelasT.getJEditarDeletarTabela("IRRF"));
		
		if (escolha == 1)
			gerenciarVisualizar(entradaDados, false);
	}
	
	/**
	 * Aquisição das informações cruciais, via terminal
	 * @param entradaDados Entrada de dados via terminal
	 * @param codigoTambem Verificação se a aquisição do código é necessária
	 * @return Faixa do IRRF com as informações colidas
	 */
	private static IRRF coletarInfo (Scanner entradaDados, boolean codigoTambem){
		IRRF irrf = new IRRF();
		
		if (codigoTambem)
			irrf.setCodigo(Mensagem.preencherCodigo(entradaDados));
		
		irrf.setLimSuperior(Mensagem.preencherLimite(entradaDados));
		irrf.setAliquota(Mensagem.preencherAliquota(entradaDados));
		irrf.setDesconto(Mensagem.preencherDesconto(entradaDados));
		
		return irrf;
	}
}
