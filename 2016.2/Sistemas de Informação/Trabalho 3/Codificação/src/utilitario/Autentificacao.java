package utilitario;

import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;

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
		try{
			int t = Integer.parseInt(fonte);
						
			if (fonte.length() == 11)
				return true;
			else
				return false;
		}catch (NumberFormatException e){
			return false;
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
			
			return resultado;
			
		}catch (NumberFormatException e){
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
		try{
			int t = Integer.parseInt(fonte);
						
			if (fonte.length() == 12)
				return true;
			else
				return false;
		}catch (NumberFormatException e){
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
