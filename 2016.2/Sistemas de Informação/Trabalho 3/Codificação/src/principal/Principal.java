package principal;

import java.io.IOException;
import java.sql.Date;
import java.text.DecimalFormat;
import java.util.Calendar;
import java.util.GregorianCalendar;
import java.util.Scanner;

import bancoDados.manipulacao.DecimoTerceiroM;
import bancoDados.manipulacao.FuncionarioM;
import bancoDados.tabelas.Funcionario;
import gui.terminal.Textual;
import trabalhoFeliz.DeptRH;
import utilitario.Autentificacao;
import utilitario.Erro;

public class Principal {
	public static Scanner entradaDados = new Scanner(System.in);
	public static final DecimalFormat FORMATAR_FLOAT = new DecimalFormat("0.00");
	
	public static void main(String[] args){
		Textual.limpaTela();
		/*
		DeptRH deptRH = new DeptRH();
		
		
		deptRH.cadrastarFuncionario();
		//*/
		
		/*
		String teste = "061 9 8385 9997";
		System.out.println("old   -> " + teste.length());
		System.out.println("new -> " + Autentificacao.telefone(teste));
		//*/
		
		/*
		String teste = "061.202.020-25";
		System.out.println("old   -> " + teste.length());
		//*/
		
		/*
		GregorianCalendar calendario = new GregorianCalendar();
		
		for (int i = 0; i < 5; i++){
			System.out.println(data(calendario));
			Autentificacao.avancarDia(calendario, 1);
		}
		//*/
		
		/*
		for (int i = 0; i < 24; i++)
			System.out.println(Autentificacao.gerarSeqInt(2, 1));
		//*/
		
		/*
		Scanner entrada = new Scanner(System.in);
		
		System.out.println("Digite nome:");
		String nome = entrada.nextLine();
		
		System.out.println("Digite CPF:");
		String CPF = entrada.nextLine();
		
		System.out.println("Digite data nascimento:");
		String data = entrada.nextLine();
		
		
		System.out.println("\nDados:");
		System.out.println("Nome -> " + nome);
		System.out.println("CPF -> " + CPF);
		System.out.println("Data -> " + data);
		//*/
	
		//System.out.println(Autentificacao.data("19941224"));

		/*
		GregorianCalendar data1 = new GregorianCalendar(2016, 01, 01);
		GregorianCalendar data2 = new GregorianCalendar(2015, 00, 01);
		System.out.println("\n" + data(data1));
		System.out.println(data(data2));
		System.out.println("diff -> " + Autentificacao.diffDataMes(data1, data2));
		System.out.println("segundos -> " + (data1.getTime().compareTo(data2.getTime())));
		//*/
		
		//*
		//DeptRH.esvaziarTudo();
		DeptRH.povoarBase();
		new Textual();
		//*/
		
		//System.out.println("vazia? " + FuncionarioM.isEmpty());
		
		System.out.println("\nAcabou\n");
		
		entradaDados.close();
	}
	
	/**
	 * Executar um comando no terminal, via aplicação
	 * @param comando Comando a ser executado
	 */
	public static void executar(String comando){
		Runtime executador = Runtime.getRuntime();
		
		try {
			executador.exec(comando);
			
		} catch (IOException e) {
			System.out.println(Erro.executar(comando));
			
		}finally {
			executador.gc();
		}		
	}
	
	
}
