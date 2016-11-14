import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.RandomAccessFile;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.function.Consumer;

/** 
 * Constroi as condicoes basicas para a execucao do programa:<br>
 * que visa converter melodias de arquivos .mid em melodias executaveis por<br>
 * instrumentos construidos baseados no pacote
 * <a href="http://cic.unb.br/~lcmm/cic-icsonica-2016-1/ics/trabalhos/sintese/javadoc/index.html">sintese</a>.<br>
 * @author	Helio Santana
 * @author	Rodrigo Guimaraes
 * @version	1.0
 * @since	14/06/2016
 */
public class Principal {
	/*
	public static long executar(Consumer<String> metodo, String vetor) {
	    long initialTime = System.nanoTime();
	    metodo.accept(vetor);
	    return System.nanoTime() - initialTime;
	}
	
    public static void main(String args[]){
    	Principal a = new Principal();
    	String teste = "interfaceGrafica.InterfaceGrafica::doIt";
    	executar (teste, "1");
    }
    //*/
	
	/*
	 public static long executar(Method metodo, String[] vetor) {
	    long initialTime = System.nanoTime();
	    try {
	        metodo.invoke(null, new Object[] { vetor });
	    } catch (IllegalAccessException e) {
	        throw new RuntimeException(e);
	    } catch (InvocationTargetException e) {
	        throw new RuntimeException(e);
	    }
	    return System.nanoTime() - initialTime;
	 }
	 
	 public static void main(String args[]){
		
		try {
			Method metodo = melodias.Melodias.class.getDeclaredMethod("teste", String[].class);
			executar (metodo, null);
			
		} catch (NoSuchMethodException | SecurityException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	   	
	 }
	//*/
	
	
	/**
	 * Garante a execucao do programa
	 * @param args Argumentos recebidos via linha de comando
	 */
	public static void main (String args[]){
		//*
		interfaceGrafica.InterfaceGrafica.criarInterface();
		//*/
		
		/*
		//conversao.ConversorMidiJava.converterArquivo ("musicas/Let It Go.mid");
		conversao.ConversorMidiJava.converterArquivo ("musicas/mvioloncelo1.mid");
		//conversao.ConversorMidiJava.converterArquivo ("musicas/The Rains of Castamere.mid");
		//conversao.ConversorMidiJava.converterArquivo ("musicas/Ainda bem - Mariza Monte.mid");
		//conversao.ConversorMidiJava.converterArquivo ("musicas/Super_Mario_Bros_-_Overworld_Theme_by_BlueSCD.mid");

		//teste ();
		
		//*/
	}
}
