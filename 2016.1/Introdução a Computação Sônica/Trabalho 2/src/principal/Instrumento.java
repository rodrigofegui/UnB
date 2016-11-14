package principal;

import sintese.Curva;
import sintese.Dispositivo;
import sintese.Envoltoria;
import sintese.Oscilador;
import sintese.Ruido;

public abstract class Instrumento extends Dispositivo {
	
	Oscilador oscilador = null;	
	Envoltoria envoltoria = null;
	Ruido ruido = null;
	
	protected boolean canal;
	protected float lambda;   
	protected float lambdaComplementar;
	protected float fase;
	protected float ganho = 1;
	protected float fatorCorte;
	

	
	public Instrumento (){
		this.envoltoria = new Envoltoria();		
		this.ruido = new Ruido();	
		this.oscilador = new Oscilador();		
		this.setRelogio (0);	
		this.fatorCorte = 0.0001f;		
		this.setLambda (0.5f);		
		this.setFase (0f);
	}
	
	public Instrumento (float fc){
		this();
		this.fatorCorte = fc;
	}
	
	public Instrumento (Ruido ruido, Envoltoria envoltoria, float fc){		
		this(fc);		
		this.ruido = ruido;	
		this.envoltoria = envoltoria;
	}
	
	public void relogio(){
		this.oscilador.relogio();
	}
	
	public void setRelogio (long n){		
		this.envoltoria.setRelogio(n);		
		this.ruido.setRelogio (n);		
		this.oscilador.setRelogio (n);		
		this.saida = this.oscilador.getSaida()*((this.canal) ? this.lambdaComplementar : this.lambda);		
		this.canal = !this.canal;	
	    this.reset();
	}
	
	public float getSaida (){		
		this.saida = this.oscilador.getSaida()*((this.canal) ? this.lambdaComplementar : this.lambda);		
		this.canal = !this.canal;
		return (this.ganho * this.saida);
    }
	
	public void setGanho (float ganho){    	
    	this.ganho = ganho;
    }
	
	public void setDuracao (float duracao){    	
    	this.duracao = duracao;    
    	this.reset();    	
    }

	public void setFrequencia(float frequencia){    	
	    	this.frequencia = frequencia;   	
	    	this.reset();
	}
	
	public void setLambda(double lambda){    	
	    	this.lambda = (float) lambda;    	
	    	this.lambdaComplementar = 1 - this.lambda;    	
	    	this.reset();
	}
	
	public void setEnvoltoria (Envoltoria envoltoria){   	
    	this.envoltoria = envoltoria;   	
    	this.reset();
    }
	
	public void setFase(float fase){
    	this.fase = fase;   
    	this.reset();
    }
	
	public Curva constroiCurvaDeEnvoltoria () {	
				
		Curva curvaDeEnvoltoria = new Curva (720);
		curvaDeEnvoltoria.addPonto (0f,	0f);
		curvaDeEnvoltoria.addPonto (20f,	400f);
		curvaDeEnvoltoria.addPonto (240f, 300f);
		curvaDeEnvoltoria.addPonto (720f,	0f);
		
		return curvaDeEnvoltoria;
	}
	
	public Curva constroiFuncaoFrequenciaRuido(){
		Curva funcaoFrequenciaRuido = new Curva(720);
		funcaoFrequenciaRuido.addPonto(0f, 200f);        
        funcaoFrequenciaRuido.addPonto(720f, 200f);
        
        return funcaoFrequenciaRuido;
	}
	
	public void setFatorCorte(float fc){
		this.fatorCorte = fc;
	}
	
	public float getFatorCorte(){
		return this.fatorCorte;
	}
	
	public float getFase(){
		return this.fase;
	}
	
	public float getLambda(){
		return this.lambda;
	}
	
	public abstract void reset();
}
