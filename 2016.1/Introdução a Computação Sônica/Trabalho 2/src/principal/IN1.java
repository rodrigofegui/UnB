package principal;

import sintese.Curva;
import sintese.Envoltoria;
import sintese.Ruido;

public class IN1 extends Instrumento {
	Curva curvaDeEnvoltoria;
	
	public IN1(){
		super();
	}
	
	public IN1 (float fc){
		super(fc);
	}
	
	public IN1 (Ruido ruido, Envoltoria envoltoria, float fc){	
		super(ruido, envoltoria, fc);
	}
	
	@Override
	public void reset(){
		
		curvaDeEnvoltoria = constroiCurvaDeEnvoltoria();
		this.envoltoria.setCURVA(curvaDeEnvoltoria);
    	this.envoltoria.setDuracao (this.duracao);    	
        this.envoltoria.reset();
        
        this.ruido.setDispositivoAmplitude (this.envoltoria);        
        this.ruido.setFrequencia (this.frequencia * this.fatorCorte);        
        this.ruido.setFase (this.fase);        
        this.ruido.setDuracao (this.duracao);        
        this.ruido.reset();
        
        this.oscilador.setDispositivoAmplitude (this.ruido);        
        this.oscilador.setFrequencia (this.frequencia);        
        this.oscilador.setFase (this.fase);        
        this.oscilador.setDuracao (this.duracao);        
        this.oscilador.reset();   
	}

}
