/**	Pacote ao qual pertence */
package principal;

import sintese.BancoDeInstrumentos;
import sintese.Curva;
import sintese.Dispositivo;
import sintese.Melodia;
import sintese.Som;

/** 
 * Constroi as condicoes basicas para a execucao do programa:<br>
 * que visa implementar os instrumentos especificados na 
 * <a href="http://cic.unb.br/~lcmm/cic-icsonica-2016-1/ics/trabalhos/t2/3instrumentosmusicv.png">imagem</a>,<br>
 * alem de possibilitar a execucao de melodias ou efeitos com tais intrumentos.
 * @author	Helio Santana
 * @author	Rodrigo Guimaraes
 * @version	1.0
 * @since	26/05/2016
 */
public class Principal{
	/**
	 * Garante a execucao do programa
	 * @param args Argumentos recebidos via linha de comando
	 */
	public static void main (String args[]){
		//new InterfaceGrafica();
		testeMelodia ();
		System.gc();
		System.out.println("\nacabou...");
	}
	
	private static void testeMelodia (){
		Dispositivo instrumentoEscolhido = BancoDeInstrumentos.sompuro();
		
		Melodia melodiaEscolhida = Melodias.padrao();
		
		//instrumentoEscolhido.setGanho(1.f);
		
		Som musica = melodiaEscolhida.getSom(instrumentoEscolhido);
		musica.setNome("testandoSom");
		
		musica.visualiza();
	}

}