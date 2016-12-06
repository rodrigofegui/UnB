package trabalhoFeliz;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.GregorianCalendar;

import bancoDados.tabelas.Holerite;
import gui.Mensagem;
import principal.Principal;
import utilitario.Autentificacao;
import utilitario.Erro;

/**
 * Classe responsável pela implementação do Departamento de Finanças
 * na empresa TrabalhoFeliz
 * @author	Rodrigo Guimarães
 * @version	1.0
 * @since	04/12/2016
 */
public class DeptFinan {
	private double dispesa;
	private String relatorio;
	
	public DeptFinan (){
		setDispesa(0);
		
		setRelatorio("");
	}
	
	/**
	 * Valor atribuído à dispesa da empresa
	 * @return A dispesa da empresa
	 */
	public double getDispesa() {
		return dispesa;
	}

	/**
	 * Atribuir valor à dispesa da empresa
	 * @param dispesa A dispesa a ser atribuída
	 */
	public void setDispesa(double dispesa) {
		this.dispesa = dispesa;
	}

	/**
	 * Valor atribuído ao relatório do mês
	 * @return O relatorio mensal
	 */
	public String getRelatorio() {
		return relatorio;
	}

	/**
	 * Atribuir valor ao relatório do mês
	 * @param relatorio O relatorio a ser atribuído
	 */
	public void setRelatorio(String relatorio) {
		this.relatorio = relatorio;
	}

	
	
	/**
	 * Pagando o valor da holerite e debitando a dispesa 
	 * na empresa
	 * @param holerite Holerite a ser paga
	 * @param empregado Empregado a ser avaliado no controle
	 */
	public void pagar (Holerite holerite, Empregado empregado){
		System.out.println(Mensagem.aguarde("Pagando Holerite"));
		
		String relatorio = getRelatorio();
		
		setDispesa(getDispesa() + holerite.getSalLiq());
		relatorio += "\tEmpregado: " + empregado.getFunc().getNome() + "\n";
		relatorio += "\tValor: R$" + Principal.FORMATAR_FLOAT.format(holerite.getSalLiq()) + "\n\n";
		
		setRelatorio(relatorio);
		
		System.out.println(Mensagem.sucesso("Pagando Holerite"));
	}
	
	/**
	 * Construção de um relatório formal, sobre as transações
	 * mensais 
	 */
	public void gerarRelatorio (){
		String relatorio = "Empresa: TrabalhoFeliz\n"
						+ "CNPJ: 00.000.000/0000-01\n\n";
		
		relatorio += "Gasto Total: R$" +  Principal.FORMATAR_FLOAT.format(getDispesa()) + "\n\n";
		
		relatorio += "Detalhamento:\n";
		relatorio += getRelatorio();
		
		setRelatorio(relatorio);
	}
	
	
	/**
	 * Registro do relatório em memória
	 * @param calendario Calendário a ser considerado no desenvolvimento
	 * do nome do arquivo
	 * @return True, se o processo ocorreu bem; false, caso contrário, sendo
	 * provavelmente por falta de diretório certo
	 */
	public boolean registrarMes (GregorianCalendar calendario){
		String caminho = "Registro/" + Autentificacao.data(calendario).replaceAll("/", "-") + ".txt";
		
		try{			
			BufferedWriter gravarArq = new BufferedWriter(new FileWriter (caminho));
			
			gerarRelatorio();
			gravarArq.append(getRelatorio() + "\n");
			
			gravarArq.close();
			
			setRelatorio("");
			setDispesa(0);

			System.out.println(Mensagem.sucesso("Salvar '" + caminho + "'"));
			
			return true;
			
		}catch (IOException e) {
			System.out.println(Erro.acessarArq(caminho));
			return false;
		}
	}
}
