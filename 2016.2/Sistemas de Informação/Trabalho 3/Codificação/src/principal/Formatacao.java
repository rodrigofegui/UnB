package principal;

import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;

/**
 * Classe responsável pela implementação de um controle de formatação
 * @author	Rodrigo Guimarães
 * @version	1.0
 * @since	29/11/2016
 */
public class Formatacao {
	/**
	 * Formatação do nome para o usual: retirando todos caracteres que não forem letras
	 * @param fonte String a ser formatada
	 * @return Nome formatado, apenas com caracteres de a-Z
	 */
	public static String nome (String fonte){
		return (fonte.replaceAll("[^a-zA-Z ]", "")).replaceAll("  ", " ");
	}
	
	/**
	 * Formatação do cpf para o usual: 000.000.000-00; dessa forma na String
	 * original só deve constar números
	 * @param fonte String a ser formatada, devendo ser semelhante a '00000000000'
	 * @return CPF formatado, como sendo: 000.000.000-00
	 */
	public static String cpf (String fonte){
		try{
			int t = Integer.parseInt(fonte);
			String resultado = "";
			
			for (int i = 0; i < 9; i += 3)
				resultado += fonte.substring(i, i + 3) + ".";
			
			resultado = resultado.substring(0, resultado.length() - 1);
			resultado += "-" + fonte.substring(9);
			
			return resultado;
		}catch (NumberFormatException e){
			System.out.println("Conversão não possível");
			
			return "Inv: " + fonte;
		}
	}

	/**
	 * Formatação da data para o inteligível pelo SGBD: aaaa-mm-dd; para tal
	 * a string só deve constar com números [0-9]
	 * @param fonte String a ser formatada, devendo ser semelhante a '00000000'
	 * @return Data formatada, como sendo: 0000-00-00
	 */
	public static String data (String fonte){
		try{
			int t = Integer.parseInt(fonte);
			String resultado = "";
			
			resultado += fonte.substring(0, 4) + "-";
			resultado += fonte.substring(4, 6) + "-";
			resultado += fonte.substring(6);
			
			if (isData(resultado))
				return resultado;
			else
				return "Inv: " + fonte;
		}catch (NumberFormatException e){
			System.out.println("Conversão não possível");
			
			return "Inv: " + fonte;
		}
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
		
		System.out.println("ext -> " + extraido);
		
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
		if ((limInf <= num) && (num <= limSup))
			return true;	
		
		return false;
	}
}
