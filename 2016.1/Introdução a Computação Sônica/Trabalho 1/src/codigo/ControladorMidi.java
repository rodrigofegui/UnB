package codigo;

import javax.sound.midi.*;
import javax.swing.JTextArea;

import interFace.AreaGrafica;

import java.io.*;

public class ControladorMidi {

	static Soundbank    bancoSELECIONADO;
	static Synthesizer  sintetizador = null;
	static Sequencer    sequenciador = null;
	static Sequence     sequencia;

	String  bancoSF2_externo = "8RealGS20.sf2";

	public void tocarMusica(String arquivo){


		arquivo = "musicas/"+arquivo;
		File arqMidi = new File(arquivo);

		try{
			sequencia = MidiSystem.getSequence(arqMidi);

			//preparando o sequenciador
			sequenciador = MidiSystem.getSequencer();
			sequenciador.open();

			carregarBanco(bancoSF2_externo);

			sequenciador.setSequence(sequencia);
			//Aqui começa a tocar
			sequenciador.start();


			int i = 0;

			while(true){

				if(sequenciador.isRunning()){

					long posicao = sequenciador.getMicrosecondPosition();
					int  seg     = Math.round(posicao*0.000001f);
					i++;

					if(i==20)
						i=0;

				}else{
					break;
				}
			}

			sequenciador.stop();
			sequenciador.close();

		}catch(MidiUnavailableException e1){/*preciso printar na tela 'Dispositivo midi não disponível'*/}
		 catch(InvalidMidiDataException e2){/*preciso printar 'Erro nos dados midi'*/}
		 catch(IOException              e3){/*preciso printar 'O arquivo midi não foi encontrado' */}

	}

	public void carregarBanco(String banco){

		try{

			sintetizador = MidiSystem.getSynthesizer();
			sintetizador.open();


		}catch(Exception ex){/*preciso printar 'Erro em MidiSystem.getSynthesizer()' */ }

		Soundbank bancoDefault = sintetizador.getDefaultSoundbank();

		if(bancoDefault != null)
			sintetizador.unloadAllInstruments(bancoDefault);

		File arquivoSf2 = new File("sf2/" + bancoSF2_externo);

		if(!arquivoSf2.exists()){/* printar o erro */}

		try{
			bancoSELECIONADO = MidiSystem.getSoundbank(arquivoSf2);
		}catch(Exception e){e.printStackTrace();}

		sintetizador.loadAllInstruments(bancoSELECIONADO);

		//imprimir a lsita do instrumentos

		try{
			sequenciador.getTransmitter().setReceiver(sintetizador.getReceiver());
		}catch(Exception e){/* printar o erro do banco*/}

	}

}
