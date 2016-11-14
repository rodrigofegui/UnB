package controladorMidi;

import interFace.Comandos;

import java.io.File;
import java.io.IOException;
import java.text.DecimalFormat;

import javax.sound.midi.InvalidMidiDataException;
import javax.sound.midi.MidiSystem;
import javax.sound.midi.MidiUnavailableException;
import javax.sound.midi.Receiver;
import javax.sound.midi.Sequence;
import javax.sound.midi.Sequencer;

public class ControladorMidi2 {
	public static Sequencer sequenciador = null;
	public static Sequence sequencia = null;
	public static Receiver receptor = null;
	public static double duracao = 0, tempoAtual = 0;
	public static long posicaoSequenciador = 0;
	public static File arqMidi = null;
	public static String textoDuracao = "", textoTempoAtual = "";
		
	public static void iniciaSequenciador () throws MidiUnavailableException{
		try{
			/*	Inicializaçãoi da Sequência */
			sequencia    = MidiSystem.getSequence(arqMidi);
			/*	Inicializaçãoi do Sequenciador */
			sequenciador = MidiSystem.getSequencer();
	
			/*	Configuração da sequência no Sequenciador */
	        sequenciador.setSequence(sequencia);
	        /*	Abertura do sequenciador */
	        sequenciador.open();
	        /*	Aguardar o hardware realizar as configurações */
	        Comandos.retardo (500);
	                    
            receptor = sequenciador.getTransmitters().iterator().next().getReceiver();
            sequenciador.getTransmitter().setReceiver(receptor);

            /*	Configurando a duração do arquivo Midi */
            duracao  = sequencia.getMicrosecondLength();
            /*	Configurando da duração no formato de texto */
            textoDuracao = formataInstante (duracao  / 1000000);
                                            	    
		}catch (MidiUnavailableException e1){
			System.out.println (e1 + " : Dispositivo midi nao disponivel.");
		}catch (InvalidMidiDataException e2){
			System.out.println (e2 + " : Erro nos dados midi.");
		}catch (IOException e3){
			System.out.println (e3 + " : O arquivo midi nao foi encontrado.");
		}	
	}
	
	public static void tocarMidi () throws MidiUnavailableException{
		iniciaSequenciador ();
		
		sequenciador.setMicrosecondPosition(posicaoSequenciador);
		
		/*	Iniciar o sequenciador */
        sequenciador.start();
	}
	
	public static void pausarMidi (){
		posicaoSequenciador = sequenciador.getMicrosecondPosition();
		
		sequenciador.stop();
	}
	
	public static void pararMidi (){
		posicaoSequenciador = 0;
				
		sequenciador.stop();
		sequenciador = null;
	}

	public static String textoTempoAtual (){
		if (sequenciador != null)
			posicaoSequenciador = sequenciador.getMicrosecondPosition();
		else
			posicaoSequenciador = 0;
			
		textoTempoAtual = formataInstante(posicaoSequenciador / 1000000);
		
		return textoTempoAtual;
	}
	
    public static String formataInstante (double tempo){
    	String textoTempo = "";

		/*	Determinando os tempos principais */
		double hora  = (int)(tempo / 3600.0);
		double minutos  = (int)((tempo - ((3600 * hora) / 60)));
		double segundos  = (tempo - ((3600 * hora) + (60 * minutos)));

		/*	Inicialização dos tempos no formato de texto */
		String textoHora = "";
		String textoMinutos = "";
		String textoSegundos = "";

		/*	Determinando o texto dos tempos: */
		/*	Para as horas: */
		/*	Sendo 0 horas, será mostrado '00' */
		if (hora == 0)
			textoHora = "00";
		/*	Abaixo de 10 horas, será mostrado '0(1-9)' */
		else if(hora < 10)
			textoHora = "0" + reformata (hora, 0);
		//else if(hora < 100)
			//textoHora = "0" + reformata (hora, 0);
		/*	Caso contrário, será mostrado o valor da hora */
		else
			textoHora = "" + reformata (hora, 0);

		/*	Para as minutos: */
		/*	Sendo 0 minutos, será mostrado '00' */
		if (minutos == 0)
			textoMinutos = "00";
		/*	Abaixo de 10 minutos, será mostrado '0(1-9)' */
		else if (minutos < 10)
			textoMinutos = "0" + reformata (minutos, 0);
		/*	Caso contrário, será mostrado o valor da hora */
		else if (minutos < 60)
			textoMinutos = "" + reformata (minutos, 0);

		/*	Para as minutos: */
		/*	Sendo 0 segundos, será mostrado '00' */
		if (segundos == 0)
			textoSegundos = "00";
		/*	Abaixo de 10 segundos, será mostrado '0(1-9)' */
		else if (segundos < 10)
			textoSegundos = "0" + reformata (segundos, 2);
		/*	Caso contrário, será mostrado o valor da hora */
		else if (segundos < 60)
			textoSegundos = reformata (segundos, 2);

		textoTempo = (" " + textoHora + "h " + textoMinutos + "m " + textoSegundos + "s");
		
		return textoTempo;
    }
    
    public static String reformata (double tempo, int casas){
    	DecimalFormat formaDecimal = new DecimalFormat() ;
    	
    	formaDecimal.setGroupingUsed(false);
    	formaDecimal.setMaximumFractionDigits(casas);
    	
    	return formaDecimal.format(tempo);
    }
}
