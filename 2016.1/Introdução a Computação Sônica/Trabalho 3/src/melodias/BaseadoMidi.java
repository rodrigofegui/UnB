package melodias;

import sintese.Melodia;
import sintese.Nota;

/**
 * Responsavel por armazenar os metodos Java criados
 * a partir de arquivos midi
 * @author	Helio Santana
 * @author	Rodrigo Guimaraes
 * @version	1.0
 * @since	14/06/2016
 */
public class BaseadoMidi{
	static Melodia 	 melodiaPrincipal;
	static Nota 	 nota;

	public BaseadoMidi (){
		melodiaPrincipal = new Melodia();
		melodiaPrincipal.setSeminima (1);
		melodiaPrincipal.setAndamento (1f);
	}

	public static Melodia mvioloncelo1 (){
		new BaseadoMidi();

		nota = new Nota (1.2, 233.05911, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.85599995, 130.8, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.3440001, 329.59537, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.51399994, 123.45876, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.342, 164.79768, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.3440001, 219.9785, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.5140002, 164.79768, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.342, 219.9785, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.34399986, 261.6, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.17000008, 233.05911, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.34399986, 233.05911, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.342, 207.63206, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.34400034, 146.81804, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.1699996, 138.57777, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.34400034, 184.97914, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.342, 184.97914, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.17199993, 293.63608, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.17199993, 311.0966, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.17000008, 130.8, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.34399986, 195.97858, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.34200048, 130.8, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.17199993, 155.5483, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.17199993, 587.27216, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.17000008, 184.97914, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.34399986, 123.45876, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.17000008, 174.59706, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.17199993, 155.5483, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.17199993, 155.5483, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.17199993, 329.59537, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.17000008, 138.57777, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.17199993, 155.5483, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.17199993, 233.05911, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.17000008, 195.97858, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.17199993, 123.45876, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.17199993, 164.79768, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.17199993, 207.63206, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.17000008, 146.81804, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.17199993, 146.81804, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.17199993, 195.97858, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.17000008, 233.05911, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.17199993, 164.79768, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.17199993, 155.5483, 3.2125983);
		melodiaPrincipal.addNota (nota);


		return melodiaPrincipal;
	}

	public static Melodia theRainsOfCastamere (){
		new BaseadoMidi();

		nota = new Nota (1.2, 233.05911, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.85599995, 130.8, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.3440001, 329.59537, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.51399994, 123.45876, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.342, 164.79768, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.3440001, 219.9785, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.5140002, 164.79768, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.342, 219.9785, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.34399986, 261.6, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.17000008, 233.05911, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.34399986, 233.05911, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.342, 207.63206, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.34400034, 146.81804, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.1699996, 138.57777, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.34400034, 184.97914, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.342, 184.97914, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.17199993, 293.63608, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.17199993, 311.0966, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.17000008, 130.8, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.34399986, 195.97858, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.34200048, 130.8, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.17199993, 155.5483, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.17199993, 587.27216, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.17000008, 184.97914, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.34399986, 123.45876, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.17000008, 174.59706, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.17199993, 155.5483, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.17199993, 155.5483, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.17199993, 329.59537, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.17000008, 138.57777, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.17199993, 155.5483, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.17199993, 233.05911, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.17000008, 195.97858, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.17199993, 123.45876, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.17199993, 164.79768, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.17199993, 207.63206, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.17000008, 146.81804, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.17199993, 146.81804, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.17199993, 195.97858, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.17000008, 233.05911, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.17199993, 164.79768, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.17199993, 155.5483, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.6772628, 219.9785, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.0167782, 349.19412, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.3377471, 219.9785, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.0167785, 329.59537, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.3377471, 219.9785, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.6772628, 349.19412, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.6772628, 391.95715, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.016778, 329.59537, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774757, 219.9785, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.6772623, 391.95715, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.6772623, 349.19412, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.67726326, 329.59537, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.67726326, 293.63608, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (2.7143555, 329.59537, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774662, 439.957, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.6772623, 439.957, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774757, 466.11823, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.67726326, 391.95715, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774757, 261.6, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774757, 261.6, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.67726326, 439.957, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.67726135, 466.11823, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.016777, 391.95715, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774757, 439.957, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.67726326, 466.11823, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.67726326, 439.957, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.67726326, 391.95715, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.67726326, 349.19412, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (2.035324, 329.59537, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774757, 219.9785, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.016779, 349.19412, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774757, 219.9785, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.016779, 329.59537, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774757, 219.9785, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.67726135, 349.19412, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.67726135, 391.95715, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.016779, 329.59537, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774757, 219.9785, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.67726326, 391.95715, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.67726326, 349.19412, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.67726326, 329.59537, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.67726135, 293.63608, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (2.035324, 329.59537, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.67726135, 261.6, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.016777, 439.957, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774948, 466.11823, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.0167809, 391.95715, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774948, 261.6, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.67726517, 439.957, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.67726517, 466.11823, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.016777, 391.95715, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774567, 439.957, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.67726135, 466.11823, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.67726135, 439.957, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.67726135, 391.95715, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.67726135, 349.19412, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (2.7143555, 293.63608, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.67726517, 219.9785, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774948, 329.59537, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774948, 349.19412, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.3562927, 293.63608, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.67726135, 349.19412, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774567, 349.19412, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774567, 329.59537, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.3562927, 219.9785, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774567, 219.9785, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774567, 349.19412, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774567, 349.19412, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.3562927, 293.63608, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.67726517, 349.19412, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774948, 349.19412, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.6958122, 329.59537, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.67726517, 219.9785, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774948, 329.59537, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774948, 349.19412, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.3562927, 293.63608, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.67726135, 439.957, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.67726135, 439.957, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.67726135, 391.95715, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.016777, 293.63608, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774567, 349.19412, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.016777, 349.19412, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774567, 293.63608, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.016777, 329.59537, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774567, 349.19412, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (2.035324, 293.63608, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.67726135, 219.9785, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774567, 329.59537, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774567, 349.19412, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.3562927, 293.63608, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.677269, 439.957, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.677269, 439.957, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.677269, 391.95715, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.0167847, 293.63608, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.3377533, 349.19412, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.016777, 349.19412, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774567, 293.63608, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774567, 439.957, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774567, 391.95715, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774567, 329.59537, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774567, 349.19412, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (2.7143555, 293.63608, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (2.714356, 73.40902, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (2.7143564, 73.40902, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.3562937, 130.8, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.3562937, 195.97858, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.3562937, 87.29853, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.3562946, 130.8, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.3562927, 87.29853, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.3562927, 130.8, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (2.7143574, 97.98929, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (2.7143555, 109.98925, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774757, 73.40902, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774757, 109.98925, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (2.035326, 146.81804, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774757, 73.40902, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774567, 109.98925, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (2.035324, 146.81804, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774757, 73.40902, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774757, 109.98925, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (2.035324, 146.81804, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774567, 130.8, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774567, 195.97858, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (2.035324, 261.6, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774567, 87.29853, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774567, 130.8, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.67726517, 174.59706, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.3562965, 130.8, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774948, 87.29853, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774948, 130.8, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.67726517, 174.59706, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.3562927, 130.8, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774567, 97.98929, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774567, 146.81804, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.67726135, 195.97858, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774567, 109.98925, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774567, 164.79768, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.67726135, 219.9785, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.016777, 73.40902, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774567, 109.98925, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774567, 146.81804, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774567, 219.9785, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774567, 146.81804, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774567, 109.98925, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.0167809, 73.40902, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774948, 109.98925, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.3562965, 146.81804, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.0167809, 73.40902, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774948, 109.98925, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.3562927, 146.81804, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.016777, 109.98925, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774567, 164.79768, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.3562927, 261.6, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.3562927, 219.9785, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.016777, 73.40902, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774567, 109.98925, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.3562927, 146.81804, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.0167809, 109.98925, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774948, 164.79768, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.3562965, 261.6, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.3562965, 219.9785, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.0167809, 116.52956, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774567, 116.52956, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.67726135, 233.05911, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.67726135, 109.98925, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774567, 97.98929, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.67726135, 146.81804, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774567, 195.97858, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774567, 116.52956, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774567, 174.59706, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.67726135, 233.05911, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.67726135, 109.98925, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.67726135, 164.79768, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.016777, 73.40902, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.33774567, 109.98925, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.3562927, 146.81804, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.016777, 116.52956, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.3377533, 116.52956, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.677269, 233.05911, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.677269, 109.98925, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.3377533, 97.98929, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.677269, 146.81804, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.3377533, 195.97858, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.3562927, 116.52956, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.3562927, 109.98925, 3.2125983);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.3562927, 73.40902, 3.2125983);
		melodiaPrincipal.addNota (nota);


		return melodiaPrincipal;
	}

	public static Melodia bwv772 (){
		new BaseadoMidi();

		nota = new Nota (0.1263021, 0.0, 0.0);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 261.6, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 293.63608, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 329.59537, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23177081, 349.19412, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 293.63608, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23177087, 329.59537, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 261.6, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.43880224, 391.95715, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916675, 130.8, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.438802, 523.2, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916651, 146.81804, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916651, 164.79768, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.11328125, 523.2, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916651, 174.59706, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.114583254, 493.83505, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.11328125, 439.957, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916651, 146.81804, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.114583254, 493.83505, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.46614575, 523.2, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916675, 164.79768, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916675, 130.8, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23177075, 587.27216, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.9283855, 195.97858, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875024, 391.95715, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 439.957, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.68359375, 97.98929, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 493.83505, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23177099, 523.2, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 439.957, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23177099, 493.83505, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 391.95715, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.43880224, 587.27216, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916651, 195.97858, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.43880177, 783.9143, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916651, 219.9785, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916651, 246.91753, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.11328125, 783.9143, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916651, 261.6, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.114583015, 698.38824, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.11328125, 659.19073, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916651, 219.9785, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.114583015, 698.38824, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.466146, 783.9143, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916698, 246.91753, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916698, 195.97858, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23177099, 659.19073, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.46354198, 261.6, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 879.914, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875048, 783.9143, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.45182276, 246.91753, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 698.38824, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23177052, 659.19073, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.46354103, 261.6, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 783.9143, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23177052, 698.38824, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.45182323, 293.63608, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 879.914, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23177052, 783.9143, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.5130205, 329.59537, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 698.38824, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 659.19073, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.45182323, 195.97858, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 587.27216, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23177147, 523.2, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.46354198, 219.9785, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 659.19073, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23177052, 587.27216, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.45182228, 246.91753, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 698.38824, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23177052, 659.19073, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.5130205, 261.6, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 587.27216, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 523.2, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.45182323, 164.79768, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 493.83505, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23177052, 439.957, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.46354198, 184.97914, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 523.2, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23177147, 493.83505, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.46354198, 195.97858, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 587.27216, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23177147, 523.2, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.46354198, 219.9785, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 493.83505, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 439.957, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.46354103, 246.91753, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 391.95715, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23177052, 369.95828, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.12630177, 261.6, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.12630177, 246.91753, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 439.957, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.74739647, 261.6, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23177052, 391.95715, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 493.83505, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.43880177, 439.957, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916698, 146.81804, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.43880272, 293.63608, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916698, 164.79768, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916698, 184.97914, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.11328125, 523.2, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 195.97858, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.11458397, 493.83505, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.46614647, 523.2, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 164.79768, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916603, 184.97914, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23177147, 587.27216, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916603, 146.81804, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23177147, 493.83505, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.46354103, 195.97858, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 439.957, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 391.95715, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.46354103, 123.45876, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 369.95828, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23176956, 329.59537, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.46354103, 130.8, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 391.95715, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23177147, 369.95828, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.4518242, 146.81804, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 439.957, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23177147, 391.95715, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.46354294, 164.79768, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 493.83505, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23177147, 439.957, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.45182228, 184.97914, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 523.2, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23177147, 493.83505, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.46354103, 195.97858, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 587.27216, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23176956, 523.2, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.45182228, 164.79768, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 659.19073, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23176956, 587.27216, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.6966133, 123.45876, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.11328125, 493.83505, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.11328125, 523.2, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 587.27216, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 783.9143, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916603, 130.8, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.11328125, 523.2, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.92447853, 146.81804, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.11328125, 493.83505, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.11328125, 523.2, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.11328125, 493.83505, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23177147, 439.957, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.46354103, 73.40902, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23177147, 391.95715, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.4049473, 391.95715, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916603, 97.98929, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916603, 109.98925, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916603, 123.45876, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916603, 130.8, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916603, 109.98925, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 123.45876, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 97.98929, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.46354294, 146.81804, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 391.95715, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 439.957, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.45182228, 195.97858, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 493.83505, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23177147, 523.2, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.46354103, 184.97914, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 439.957, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23176956, 493.83505, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.45182228, 195.97858, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 391.95715, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.46354103, 369.95828, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916603, 219.9785, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916603, 146.81804, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 164.79768, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 184.97914, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 195.97858, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 164.79768, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916603, 184.97914, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916603, 146.81804, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.46354103, 219.9785, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 439.957, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 493.83505, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.45182228, 293.63608, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 523.2, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23176956, 587.27216, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.46354103, 261.6, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 493.83505, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23177147, 523.2, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.4518242, 293.63608, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 439.957, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.1731777, 493.83505, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 195.97858, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 391.95715, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916603, 349.19412, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916603, 329.59537, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916603, 293.63608, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916603, 349.19412, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916603, 329.59537, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916603, 391.95715, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.46354294, 349.19412, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 587.27216, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 523.2, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.46354294, 329.59537, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 493.83505, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23177338, 439.957, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.46354294, 349.19412, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 523.2, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23176956, 493.83505, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.46353912, 293.63608, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 587.27216, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.12630081, 523.2, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916412, 329.59537, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.12630081, 493.83505, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916412, 439.957, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.6354179, 523.2, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 391.95715, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 349.19412, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 329.59537, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 391.95715, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 349.19412, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 439.957, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.46354294, 391.95715, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 659.19073, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 587.27216, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.46353912, 349.19412, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 523.2, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23176956, 493.83505, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.46353912, 391.95715, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 587.27216, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23176956, 554.3111, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.46354294, 329.59537, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 659.19073, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.46614456, 587.27216, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 349.19412, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 466.11823, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.4518242, 554.3111, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 439.957, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 391.95715, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.46614838, 587.27216, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 349.19412, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 439.957, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.11328125, 698.38824, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916412, 391.95715, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.11458588, 659.19073, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.11328125, 587.27216, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916412, 466.11823, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.11458588, 659.19073, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.46614456, 698.38824, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916412, 439.957, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916412, 391.95715, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.4518242, 439.957, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 349.19412, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 329.59537, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.46614456, 493.83505, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 293.63608, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 349.19412, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.11328125, 587.27216, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 329.59537, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.11458206, 554.3111, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.11328125, 493.83505, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 391.95715, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.11458206, 554.3111, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.46614838, 587.27216, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 349.19412, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 329.59537, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.45182037, 369.95828, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916412, 293.63608, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916412, 261.6, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.46614456, 415.26413, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916412, 246.91753, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916412, 293.63608, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.4518242, 439.957, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 261.6, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 329.59537, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.46614456, 493.83505, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 293.63608, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 261.6, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.4518242, 523.2, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 246.91753, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 219.9785, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.12630463, 493.83505, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 207.63206, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.12630081, 523.2, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 246.91753, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.70051956, 587.27216, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916412, 219.9785, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916412, 261.6, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.4622383, 246.91753, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23177338, 329.59537, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 369.95828, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.46354294, 164.79768, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 415.26413, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23176956, 439.957, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.11197662, 293.63608, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.11198044, 261.6, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21744537, 369.95828, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.60416794, 293.63608, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23177338, 415.26413, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 329.59537, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23176956, 659.19073, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916412, 261.6, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 587.27216, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916412, 246.91753, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23176956, 523.2, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916412, 219.9785, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 659.19073, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 195.97858, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23176956, 587.27216, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 184.97914, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 523.2, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 219.9785, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23176956, 493.83505, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 207.63206, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 587.27216, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 246.91753, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23177338, 523.2, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 219.9785, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 879.914, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 261.6, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23177338, 830.52826, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 246.91753, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 987.6701, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916412, 293.63608, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23176956, 879.914, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916412, 261.6, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 659.19073, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916412, 329.59537, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23176956, 698.38824, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916412, 293.63608, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.20573044, 587.27216, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.20703125, 349.19412, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23176956, 415.26413, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.46354294, 329.59537, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 698.38824, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 659.19073, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.453125, 219.9785, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21224213, 587.27216, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.11328125, 587.27216, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.46224213, 329.59537, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.11328125, 523.2, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.11328125, 587.27216, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.11458206, 523.2, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23176956, 493.83505, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.4518242, 164.79768, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22526169, 439.957, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.27474213, 439.957, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.4049492, 219.9785, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23177338, 879.914, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23177338, 783.9143, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.1731796, 109.98925, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23176956, 698.38824, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23176956, 659.19073, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23176956, 783.9143, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23176956, 698.38824, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23176956, 879.914, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.11328125, 783.9143, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.11328125, 698.38824, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.875, 783.9143, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916412, 329.59537, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916412, 293.63608, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 261.6, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 246.91753, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 293.63608, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 277.15555, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 329.59537, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.11198044, 293.63608, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.11197662, 277.15555, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23176956, 659.19073, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.7591133, 293.63608, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23176956, 698.38824, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23176956, 783.9143, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23176956, 879.914, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23176956, 698.38824, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23176956, 783.9143, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23177338, 659.19073, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.11328125, 698.38824, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.11328125, 659.19073, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.875, 698.38824, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 219.9785, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 246.91753, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 261.6, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 293.63608, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 246.91753, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 261.6, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916412, 219.9785, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.11197662, 246.91753, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.11198044, 219.9785, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23176956, 783.9143, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.7591133, 246.91753, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23176956, 698.38824, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23177338, 659.19073, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23177338, 587.27216, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23177338, 698.38824, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23177338, 659.19073, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23176956, 783.9143, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.11328125, 698.38824, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.11328125, 659.19073, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.875, 698.38824, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 293.63608, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 261.6, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916412, 246.91753, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916412, 219.9785, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916412, 261.6, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916412, 246.91753, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916794, 293.63608, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.11198044, 261.6, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.11198044, 246.91753, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23177338, 587.27216, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (1.8567734, 261.6, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23177338, 659.19073, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23177338, 698.38824, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23177338, 783.9143, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23177338, 659.19073, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23177338, 698.38824, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23176575, 587.27216, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23176575, 587.27216, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.125, 659.19073, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.2278595, 195.97858, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.125, 698.38824, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.11588287, 659.19073, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916412, 219.9785, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.1158905, 698.38824, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.11197662, 659.19073, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916412, 233.05911, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.110672, 698.38824, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.10677338, 659.19073, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916412, 261.6, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.10676575, 698.38824, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.9765625, 659.19073, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916412, 219.9785, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22916412, 233.05911, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.22917175, 195.97858, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.46224213, 219.9785, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 523.2, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 587.27216, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.46353912, 233.05911, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 659.19073, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23177338, 698.38824, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.46354675, 219.9785, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 587.27216, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23177338, 659.19073, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.46354675, 195.97858, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 523.2, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23177338, 587.27216, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.46353912, 174.59706, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 659.19073, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 698.38824, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.46353912, 293.63608, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 783.9143, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23176575, 879.914, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.46353912, 261.6, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 698.38824, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23176575, 783.9143, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.46353912, 233.05911, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 659.19073, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23177338, 698.38824, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.46354675, 219.9785, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 783.9143, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 879.914, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.46354675, 349.19412, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 987.6701, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23177338, 1046.4, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.46353912, 329.59537, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 879.914, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23177338, 987.6701, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.46353912, 293.63608, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.21875, 783.9143, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.233078, 329.59537, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.4453125, 1046.4, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23177338, 146.81804, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.233078, 164.79768, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.4453125, 783.9143, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23177338, 174.59706, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.1158905, 698.38824, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.233078, 195.97858, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.11588287, 659.19073, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.1158905, 698.38824, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.233078, 164.79768, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.11588287, 659.19073, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23567963, 587.27216, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.233078, 174.59706, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.2096405, 523.2, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23177338, 146.81804, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.24609375, 523.2, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.4934845, 164.79768, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23307037, 466.11823, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.24609375, 439.957, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.49349213, 130.8, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23307037, 391.95715, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.24609375, 349.19412, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.49349213, 146.81804, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.233078, 439.957, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.24609375, 391.95715, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.49349213, 164.79768, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.23307037, 466.11823, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.26171875, 439.957, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.2591095, 174.59706, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.26171875, 493.83505, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.2591095, 146.81804, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.80207825, 523.2, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.2591095, 164.79768, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.24869537, 329.59537, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.2591095, 174.59706, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.5872345, 293.63608, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.8658829, 195.97858, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.5885391, 523.2, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.5885391, 349.19412, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.5885391, 97.98929, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (0.29296875, 493.83505, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (3.7135468, 65.4, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (3.7135468, 523.2, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (3.7135468, 391.95715, 5.1);
		melodiaPrincipal.addNota (nota);

		nota = new Nota (3.7135468, 329.59537, 5.1);
		melodiaPrincipal.addNota (nota);


		return melodiaPrincipal;
	}

	public static Melodia gerenciador (String nome){
		if (nome.equals("mvioloncelo1"))
			return mvioloncelo1();
		else if (nome.equals("theRainsOfCastamere"))
			return theRainsOfCastamere();
		else if (nome.equals("bwv772"))
			return bwv772();
		else return null;
	}
	public static Melodia gerenciador (String nome){
		if (nome.equals("mvioloncelo1"))
			return mvioloncelo1();
		else if (nome.equals("theRainsOfCastamere"))
			return theRainsOfCastamere();
		else if (nome.equals("bwv772"))
			return bwv772();
		else return null;
	}
}