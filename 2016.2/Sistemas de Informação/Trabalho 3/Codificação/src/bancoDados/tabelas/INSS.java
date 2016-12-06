package bancoDados.tabelas;

import java.util.LinkedList;
import java.util.Scanner;

import bancoDados.manipulacao.INSSM;
import gui.Mensagem;
import gui.terminal.JanelasT;
import gui.terminal.Textual;

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
	
		LinkedList<INSS> listInss = INSSM.lerCompleto();
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
	 * Redução equivalente ao salário bruto do imposto do INSS, sabendo-se o código da
	 * faixa do INSS e o salário bruto
	 * @param codigoInss Código da faixa do INSS a ser considerada
	 * @param salarioBruto Salário bruto a sofrer a dedução do imposto ao INSS
	 * @return Dedução do imposto, onde para os salários
	 * até R$5.189,83 a dedução será proporcional ao salário, respeitando a
	 * alíquota; caso contrário, será deduzido o valor fixo de R$570,88. 
	 */
	public static float reducao (int codigoInss, float salarioBruto){
		if (codigoInss == 4)
			return -570.88f;
		
		LinkedList<INSS> listInss = INSSM.lerCompleto();
		INSS inss;
		
		float reducao = 0f;
		
		for (int pos = 0; pos < listInss.size(); pos++){
			inss = listInss.get(pos);
			
			if (codigoInss == inss.getCodigo()){
				reducao = salarioBruto * inss.aliquota;
				break;
			}
		}
		
		return -reducao;
	}
	
	/**
	 * Redução equivalente ao salário bruto do imposto do INSS, sabendo-se o código da
	 * faixa do INSS e o salário bruto
	 * @param salarioBruto Salário bruto a sofrer a dedução do imposto ao INSS
	 * @return Dedução do imposto, onde para os salários
	 * até R$5.189,83 a dedução será proporcional ao salário, respeitando a
	 * alíquota; caso contrário, será reduzido o valor fixo de R$570,88. 
	 */
	public static float reducao (float salarioBruto){
		return reducao(localizarCod(salarioBruto), salarioBruto);
	}
	
	
	
	/**
	 * Deduzir do salário bruto o imposto do INSS, sabendo-se o código da
	 * faixa do INSS e o salário bruto
	 * @param codigoInss Código da faixa do INSS a ser considerada
	 * @param salarioBruto Salário bruto a sofrer a dedução do imposto ao INSS
	 * @return Salário líquido com a dedução do imposto
	 */
	public static float deduzirAliquota (int codigoInss, float salarioBruto){
		return salarioBruto + reducao(codigoInss, salarioBruto);
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
		INSS inss;
		
		inss = new INSS();
		inss.setCodigo(1);
		inss.setLimSuperior(1556.94f);
		inss.setAliquota(.08f);
		INSSM.inserir(inss);
		
		inss = new INSS();
		inss.setCodigo(2);
		inss.setLimSuperior(2594.92f);
		inss.setAliquota(.09f);
		INSSM.inserir(inss);
		
		inss = new INSS();
		inss.setCodigo(3);
		inss.setLimSuperior(5189.82f);
		inss.setAliquota(.11f);
		INSSM.inserir(inss);
	}

	/**
	 * Representação inteligível ao usuário
	 * @return Representação formatada
	 */
	public String toString (){
		String toString = "" + getCodigo() + " - " + getLimSuperior() + " - " + getAliquota();
		
		return toString;
	}

	
	
	/**
	 * Gerenciamento da Edição da tabela INSS no BD
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
	 * Gerenciamento das opção de inserir uma nova faixa no INSS
	 * @param entradaDados Entrada de dados via terminal
	 */
	private static void gerenciarInserir (Scanner entradaDados){
		INSS inss = new INSS();
		String operacao = "Inserir INSS";
		
		JanelasT.getJEditarInserirTabela("INSS");
		
		inss = coletarInfo(entradaDados, false);
		
		System.out.println(Mensagem.aguarde(operacao));
		
		INSSM.inserir(inss);
		
		System.out.println(Mensagem.sucesso(operacao));
	}
	
	/**
	 * Gerenciamento das opção de atualizar uma faia do INSS
	 * @param entradaDados Entrada de dados via terminal
	 */
	private static void gerenciarAtualizar (Scanner entradaDados){
		INSS inss = new INSS();
		String operacao = "Atualizar INSS";
		
		ctrlVisualizar(entradaDados, true);
		
		System.out.println(Mensagem.atualizar(false));
		
		inss = coletarInfo(entradaDados, true);
		
		System.out.println(Mensagem.aguarde(operacao));
		
		INSSM.atualizar(inss);
		
		System.out.println(Mensagem.sucesso(operacao));
	}
	
	/**
	 * Gerenciamento das opção de visualizar as faixas do INSS existentes
	 * @param entradaDados Entrada de dados via terminal
	 * @param isFull Verificando se a exibição desta opção é completa ou não.
	 * Sendo true, incluirá o título na janela; caso contrário, não
	 */
	private static void gerenciarVisualizar (Scanner entradaDados, boolean isFull){
		if (isFull)
			JanelasT.getJEditarVisualizarTabela("INSS");
		
		LinkedList<INSS> listInss = INSSM.lerCompleto();
		INSS inss;
		
		System.out.println("Código - Lim. Sup - Alíquota");
		for (int pos = 0; pos < listInss.size(); pos++){
			inss = listInss.get(pos);
			
			System.out.println(inss.toString());
		}
	}
	
	/**
	 * Gerenciamento das opção de exclusão uma faixa do INSS
	 * @param entradaDados Entrada de dados via terminal
	 */
	private static void gerenciarDeletar (Scanner entradaDados){
		INSS inss = new INSS();
		String operacao = "Deletar INSS";
		
		ctrlVisualizar(entradaDados, false);
		
		System.out.println(Mensagem.deletar(false));
		
		inss.setCodigo(Mensagem.preencherCodigo(entradaDados));
		
		System.out.println(Mensagem.aguarde(operacao));
		
		INSSM.deletar(inss);
		
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
			escolha = Mensagem.questionaOpcoes(entradaDados, JanelasT.getJEditarAtualizarTabela("INSS"));
		else
			escolha = Mensagem.questionaOpcoes(entradaDados, JanelasT.getJEditarDeletarTabela("INSS"));
		
		if (escolha == 1)
			gerenciarVisualizar(entradaDados, false);
	}

	/**
	 * Aquisição das informações cruciais, via terminal
	 * @param entradaDados Entrada de dados via terminal
	 * @param codigoTambem Verificação se a aquisição do código é necessária
	 * @return Faixa do INSS com as informações colidas
	 */
	private static INSS coletarInfo (Scanner entradaDados, boolean codigoTambem){
		INSS inss = new INSS();
		
		if (codigoTambem)
			inss.setCodigo(Mensagem.preencherCodigo(entradaDados));
		
		inss.setLimSuperior(Mensagem.preencherLimite(entradaDados));
		inss.setAliquota(Mensagem.preencherAliquota(entradaDados));
		
		return inss;
	}
}
