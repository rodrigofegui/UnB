package utilitario;

import java.sql.Date;
import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.GregorianCalendar;
import java.util.Random;
import java.util.Scanner;

/**
 * Classe responsável pela implementação de um controle de formatação e de
 * autentificação dos formatos
 * @author	Rodrigo Guimarães
 * @version	1.0
 * @since	29/11/2016
 */
public class Autentificacao {
	/**
	 * Formatação do nome para o usual: retirando todos caracteres que não forem letras
	 * @param fonte String a ser formatada
	 * @return Nome formatado, apenas com caracteres de a-Z
	 */
	public static String nome (String fonte){
		return (fonte.replaceAll("[^a-zA-Z ]", "")).replaceAll("  ", " ");
	}
	
	/**
	 * Verificação de nome válido, ou seja, se só contém caracteres alfabeticos:
	 * [a-Z][A-Z]
	 * @param fonte Nome a ser avaliado
	 * @return True:
	 * <LI> Nome formatado for iguai à fonte
	 * <p> False:
	 * <LI> Caso contrário
	 */
	public static boolean isNome (String fonte){
		if (fonte.equals(nome(fonte)))
			return true;
		
		return false;
	}
	
	/**
	 * Formatação do cpf para o usual: 000.000.000-00; dessa forma na String
	 * original só deve constar números
	 * @param fonte String a ser formatada, devendo ser semelhante a '00000000000'
	 * @return CPF formatado, como sendo: 000.000.000-00
	 */
	public static String cpf (String fonte){
		String resultado = "";
			
		for (int i = 0; i < 9; i += 3)
			resultado += fonte.substring(i, i + 3) + ".";
		
		resultado = resultado.substring(0, resultado.length() - 1);
		resultado += "-" + fonte.substring(9);
		
		//System.out.println("resultado.CPF -> " + resultado);
		
		return resultado;
	}
	
	/**
	 * Verificação de CPF válido
	 * @param fonte CPF a ser avaliado
	 * @return True:
	 * <LI> Havendo só números (0-9), além de ter 11
	 * <p> False:
	 * <LI> Não sendo só constituído por números;
	 * <LI> Não tendo 11 números
	 */
	public static boolean isCpf (String fonte){
		if (isNumero(fonte, true)	&& fonte.length() == 11)
			return true;
		
		return false;	
	}

	/**
	 * Formatação da data para o inteligível pelo SGBD: aaaa-mm-dd; para tal
	 * a string só deve constar com números [0-9]
	 * @param fonte String a ser formatada, devendo ser semelhante a '00000000'
	 * @return Data formatada, como sendo: 0000-00-00
	 */
	public static String data (String fonte){
		if (!isNumero(fonte, false))
			return "Inv: " + fonte;
		
		String resultado = "";
		
		/*
		resultado += fonte.substring(0, 4) + "-";
		resultado += fonte.substring(4, 6) + "-";
		resultado += fonte.substring(6);
		//*/
		
		//*
		resultado += fonte.substring(6) + "/";
		resultado += fonte.substring(4, 6) + "/";
		resultado += fonte.substring(0, 4);
		//*/
		
		return resultado;
	}
	
	/**
	 * Formatação da data para um dado calendário
	 * @param calendario Calendário a ter a data formatada
	 * @return Data formatada
	 */
	public static String data (GregorianCalendar calendario){
		String data = String.format("%02d", calendario.get(Calendar.DAY_OF_MONTH)) + "/" 
					+ String.format("%02d", (calendario.get(Calendar.MONTH) + 1)) + "/"
					+ String.format("%04d", calendario.get(Calendar.YEAR));
		
		return data;
	}
	
	/**
	 * Criação de uma data inteligível pelo BD
	 * @param fonte Data a ser formatada
	 * @return Data formatada
	 */
	public static Date dataSQL (String fonte){
		DateFormat fmt = new SimpleDateFormat("dd/MM/yyyy");
		try {
			return new java.sql.Date(fmt.parse(fonte).getTime());
		} catch (ParseException e) {
			e.printStackTrace();
			return null;
		}
	}
	
	/**
	 * Extração do dia, para uma string no formato
	 * padrão: dd/MM/aaaa
	 * @param data Data a ser extraída o dia
	 * @return Dia da data
	 */
	public static int dia (String data){
		String dia = data.substring(0, 2);
				
		if (isNumero(dia, false))
			return Integer.parseInt(dia);
		
		return 00;
	}
	
	/**
	 * Extração do mes, para uma string no formato
	 * padrão: dd/MM/aaaa
	 * @param data Data a ser extraída o dia
	 * @return Mês da data
	 */
	public static int mes (String data){
		String mes = data.substring(3, 5);
				
		if (isNumero(mes, false))
			return Integer.parseInt(mes);
		
		return 00;
	}
	
	/**
	 * Extração do ano, para uma string no formato
	 * padrão: dd/MM/aaaa
	 * @param data Data a ser extraída o dia
	 * @return Ano da data
	 */
	public static int ano (String data){
		String ano = data.substring(6);
				
		if (isNumero(ano, false))
			return Integer.parseInt(ano);
		
		return 00;
	}
	
	/**
	 * Verificação de data válida ou não, considerando apenas a atual, sem ajustes
	 * @param fonte Data a ser avaliada
	 * @return True:
	 * <LI> Data válida
	 * <p> False:
	 * <LI> Caso contrário
	 */
	public static boolean isData (String fonte){
		String partes[] = fonte.split("-");
		
		DateFormat df = new SimpleDateFormat ("dd/MM/yyyy");
		df.setLenient (false);
        
		try{
            df.parse (partes[2] + "/" + partes[1] + "/" + partes[0]);
            
            return true;
        }catch (ParseException ex) {
           return false;
        }
	}

	/**
	 * Cálculo da diferença entre dadas, em meses
	 * @param data1 1º data a ser considerada
	 * @param data2 2º data a ser considerada
	 * @return Diferença, em meses, entre as datas
	 */
	public static int diffDataMes (GregorianCalendar data1, GregorianCalendar data2){
		int months = data2.get(Calendar.MONTH) - data1.get(Calendar.MONTH);
		int years = data2.get(Calendar.YEAR) - data1.get(Calendar.YEAR);
		int monthsPerYear = data1.getActualMaximum(Calendar.MONTH);
		
		return Math.abs(months + monthsPerYear * years);
	}
	
	/**
	 * Formatação do telefone para o usual: 000 0 0000 0000
	 * @param fonte String a ser formatada
	 * @return Telefone formatado
	 */
	public static String telefone (String fonte){
		String resultado = fonte.substring(0, 3) + " ";
		
		resultado += fonte.substring(3, 4) + " ";
		resultado += fonte.substring(4, 8) + " ";
		resultado += fonte.substring(8);
		
		return resultado;
	}
	
	/**
	 * Verificação de telefone válido
	 * @param fonte Telefone a ser avaliado
	 * @return True:
	 * <LI> Havendo só números (0-9), além de ter 12
	 * <p> False:
	 * <LI> Não sendo só constituído por números;
	 * <LI> Não tendo 12 números
	 */
	public static boolean isTelefone (String fonte){
		if (isNumero(fonte, true) && fonte.length() == 12) 
			return true;
		
		return false;
	}
	
	/**
	 * Verificação se é um email, seguinda forma: exemplo@exemplo.com;
	 * aceitando apenas caracteres alfa-numéricos e os especiais: [ _ . - ]
	 * @param fonte String a ser verificada
	 * @return True:
	 * <LI> E-mail no formato aceitável;
	 * <p>False:
	 * <LI> Excluindo os caracteres não permitidos, houver altereção de tamanho;
	 * <LI> Não houver duas partes, considerando "@" como divisor;
	 * <LI> Na segunda parte, não havendo espaço para "exemplo.com" 
	 */
 	public static boolean isEmail (String fonte){
		String extraido = fonte.replaceAll("[^a-zA-Z0-9@_.-]", "");
		
		//System.out.println("ext -> " + extraido);
		
		if (!fonte.equals(extraido))
			return false;
		
		String partes[] = fonte.split("@");
		
		if (partes.length < 2)
			return false;
		
		if  ((partes[1].length() > 4) && partes[1].contains(".com"))
			return true;
		
		return false;
	}
		
	/**
	 * Verificação de intervalo, se um dado número está num intervalo
	 * @param num Número a ser analisado
	 * @param limInf Limite inferior do intervalo
	 * @param limSup Limite superior do intervalo
	 * @return True:
	 * <LI> O número pertence ao intervalo
	 * <p> False:
	 * <LI> Caso contrário
	 */
	public static boolean isContido (int num, int limInf, int limSup){
		return isContido((double) num, (double) limInf, (double) limSup);
	}
	
	/**
	 * Verificação de intervalo, se um dado número está num intervalo
	 * @param num Número a ser analisado
	 * @param limInf Limite inferior do intervalo
	 * @param limSup Limite superior do intervalo
	 * @return True:
	 * <LI> O número pertence ao intervalo
	 * <p> False:
	 * <LI> Caso contrário
	 */
	public static boolean isContido (double num, double limInf, Double limSup){
		if ((limInf <= num) && (num <= limSup))
			return true;	
		
		return false;
	}
	
	/**
	 * Verificação se uma string fornecida pode ser intretada com um número
	 * @param fonte String a ser verificada
	 * @param isDecimal Verificação se o número da string é um provável 
	 * número decimal ou inteiro
	 * @return True:
	 * <LI> Pode ser interpretada
	 * <p> False:
	 * <LI> Caso contrário
	 */
	public static boolean isNumero (String fonte, boolean isDecimal){
		try{
			double testeDouble;
			int testeInt;
			
			if (isDecimal)
				testeDouble = Double.parseDouble(fonte);
			else
				testeInt = Integer.parseInt(fonte);
			
			return true;
		}catch (NumberFormatException e){
			return false;
		}
	}
	
	
	
	/**
	 * Controle de resposta inválida para números
	 * @param entradaDados Entrada de dados via terminal
	 * @param isDecimal Verificação se o número da string é um provável 
	 * número decimal ou inteiro
	 * @return Número válido
	 */
	public static double controleNumero (Scanner entradaDados, boolean isDecimal){
		String linha;
		
		do{
			linha = entradaDados.nextLine();
			
			if (Autentificacao.isNumero(linha, isDecimal)){
				return Double.parseDouble(linha);
				
			}else	System.out.println(Erro.numero());
			
		}while (true);
	}
	
	/**
	 * Controle de resposta inválida para números
	 * @param entradaDados Entrada de dados via terminal
	 * @param isDecimal Verificação se o número da string é um provável 
	 * número decimal ou inteiro
	 * @param limInf Limite inferior do intervalo
	 * @param limSup Limite superior do intervalo
	 * @return Número válido
	 */
	public static double controleNumero (Scanner entradaDados, boolean isDecimal, double limInf, double limSup){
		String linha;
		
		do{
			linha = entradaDados.nextLine();
			
			if (isNumero(linha, isDecimal) && isContido(Double.parseDouble(linha), limInf, limSup)){
				return Double.parseDouble(linha);
				
			}else	System.out.println(Erro.numero());
			
		}while (true);
	}
	
	
	/**
	 * Adicionando anos ao ano atual do calendário
	 * @param calendario Calendário a ter a data modificada
	 * @param qnt Quantidade de anos a ser acrescentada, podendo ser negativo
	 */
	public static void avancarAno (GregorianCalendar calendario, int qnt){
		calendario.add(Calendar.YEAR, qnt);
	}
	
	/**
	 * Adicionando meses ao mês atual do calendário
	 * @param calendario Calendário a ter a data modificada
	 * @param qnt Quantidade de meses a ser acrescentada, podendo ser negativo
	 */
	public static void avancarMes (GregorianCalendar calendario, int qnt){
		calendario.add(Calendar.MONTH, qnt);
	}
	
	/**
	 * Adicionando dias ao dia atual do calendário
	 * @param calendario Calendário a ter a data modificada
	 * @param qnt Quantidade de dias a ser acrescentada, podendo ser negativo
	 */
	public static void avancarDia (GregorianCalendar calendario, int qnt){
		calendario.add(Calendar.DAY_OF_MONTH, qnt);
	}

	

	/**
	 * Gerar sequência aleatória de números inteiros, num intervalor
	 * específico e numa quantidade determinada
	 * @param lim Limite do range dos números, sendo entre 0 - lim
	 * @param qnt Quantidade de números a serem gerados
	 * @return Compilação dos números gerados
	 */
	public static String gerarSeqInt (int lim, int qnt){
		Random gerador = new Random();
		String numero = "";
		
		for (int ind = 0; ind < qnt; ind ++)
			numero += gerador.nextInt(lim);
		
		return numero;
	}
		
	/**
	 * Gerar sequência aleatória de números inteiros, entre 0 e 9, numa 
	 * quantidade determinada
	 * @param qnt Quantidade de números a serem gerados
	 * @return Compilação dos números gerados
	 */
	public static String gerarSeqInt (int qnt){
		return gerarSeqInt(10, qnt);
	}

	/**
	 * Gerar uma data aleatória
	 * @param anoBase Ano mínino possível
	 * @return Data gerada
	 */
	public static String gerarData (int anoBase){
		String data = "" + (anoBase + Integer.parseInt(gerarSeqInt(Math.abs(1996 - anoBase), 1)))
					+ String.format("%02d", Integer.parseInt(gerarSeqInt(11, 1)))
					+ String.format("%02d", Integer.parseInt(gerarSeqInt(30, 1)));
		
		return data;
	}	
}
