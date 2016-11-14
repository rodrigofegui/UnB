/*	Pacote ao qual pertence */
package melodias;

/*	Importando Classes necessárias */
import sintese.Melodia;
import sintese.Nota;
import sintese.Tema;

/** 
 * Constroi as melodias personalizadas a serem tocadas pelos instrumentos
 * criados
 * @author	Helio Santana
 * @author	Rodrigo Guimaraes
 * @version	1.0
 * @since	28/05/2016
 */
public class Melodias {
	/**
	 * Melodia a ser modificada, independente do tema criado
	 * Nota a ser manipulada, a fim de construção da melodia
	 * Frequencia a ser atribuída à nota durante a melodia
	 * Amplitude padrao a ser utilizado pelas notas
	 * Construcao da melodia de maneira default
	 */

	static Melodia 	 melodiaPrincipal;
	static Nota 	 nota;
	static float 	 frequencia;
	static final int amplitudePadrao = 15;
	
	
	
	/**
	 * Construcao da melodia de maneira default
	 */

	public Melodias (){
		melodiaPrincipal = new Melodia();		
		melodiaPrincipal.setSeminima (1);	
		melodiaPrincipal.setAndamento (0.62f);

	}
	
	public static Melodia gerenciadorDefault (String nome){
		System.out.println("Buscando melodia -> " + nome);
		
		if (nome.equals("frozen"))
			return frozen();
		
		if (nome.equals("gameOfThrones"))
			return gameOfThrones();
		
		if (nome.equals("rainsOfCastamere"))
			return rainsOfCastamere();
		
		if (nome.equals("melodiasexta1"))
			return Tema.melodiasexta1();
		
		if (nome.equals("sonata_scarlatti"))
			return Tema.sonata_scarlatti();
		
		if (nome.equals("tema_aa_drawing_quintet_flauta"))
			return Tema.tema_aa_drawing_quintet_flauta();
		
		if (nome.equals("tema_aa_fuga1"))
			return Tema.tema_aa_fuga1();
		
		if (nome.equals("tema_bwv775_invencao14_direita"))
			return Tema.tema_bwv775_invencao14_direita();
		
		if (nome.equals("tema_bwv775_invencao4_direita"))
			return Tema.tema_bwv775_invencao4_direita();
		
		if (nome.equals("tema_bwv775_invencao4_esquerda"))
			return Tema.tema_bwv775_invencao4_esquerda();
		
		if (nome.equals("tema_bwv988goldberg_v03_eq"))
			return Tema.tema_bwv988goldberg_v03_eq();
		
		if (nome.equals("tema_duda_no_frevo_eq"))
			return Tema.tema_duda_no_frevo_eq();
		
		else return null;
	}
	
	/**
	 * Construcao do refrao da musica "Let it Go",
	 * do filme Frozen - da Disney
	 * @return A melodia construida
	 */
	public static Melodia frozen (){
		
		new Melodias();		
		
		frequencia = IntervalosMusicais.Dsust (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.Fsust (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.G (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.minima() + melodiaPrincipal.getSeminima(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.Csust (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.B (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.Gsust (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.minima() + melodiaPrincipal.getSeminima() + IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);

		frequencia = IntervalosMusicais.G (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.Fsust (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.E (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.E (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.E (IntervalosMusicais.C4);
		nota = new Nota (melodiaPrincipal.getSeminima(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.E (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.Fsust (IntervalosMusicais.C4);
		nota = new Nota (melodiaPrincipal.getSeminima(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.G (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.minima() + melodiaPrincipal.getSeminima(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		
		
		frequencia = IntervalosMusicais.Dsust (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.Fsust (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.G (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.minima() + melodiaPrincipal.getSeminima(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.Csust (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.B (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.Gsust (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.minima() + melodiaPrincipal.getSeminima() + IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.G (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.A (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.B (IntervalosMusicais.C4);
		nota = new Nota (melodiaPrincipal.getSeminima(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.B (IntervalosMusicais.C4);
		nota = new Nota (melodiaPrincipal.getSeminima(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		nota = new Nota (IntervalosMusicais.colcheia(), IntervalosMusicais.C5, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.B (IntervalosMusicais.C4);
		nota = new Nota (melodiaPrincipal.getSeminima(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.A (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.G (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.A (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.G (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.minima() + melodiaPrincipal.getSeminima() + IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		
		
		frequencia = IntervalosMusicais.D (IntervalosMusicais.C5);
		nota = new Nota (melodiaPrincipal.getSeminima() + IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.B (IntervalosMusicais.C4);
		nota = new Nota (melodiaPrincipal.getSeminima() + IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.A (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.minima() + melodiaPrincipal.getSeminima(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.G (IntervalosMusicais.C4);
		nota = new Nota (melodiaPrincipal.getSeminima(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.G (IntervalosMusicais.C4);
		nota = new Nota (melodiaPrincipal.getSeminima(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.D (IntervalosMusicais.C4);
		nota = new Nota (melodiaPrincipal.getSeminima() + IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.B (IntervalosMusicais.C4);
		nota = new Nota (melodiaPrincipal.getSeminima() + IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.A (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.minima() * 2, frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.G (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.G (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.Fsust (IntervalosMusicais.C4);
		nota = new Nota (melodiaPrincipal.getSeminima() + IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.D (IntervalosMusicais.C4);
		nota = new Nota (melodiaPrincipal.getSeminima() + IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.D (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.minima() * 2, frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		nota = new Nota (IntervalosMusicais.colcheia(), 0, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.G (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		nota = new Nota (melodiaPrincipal.getSeminima(), IntervalosMusicais.C5, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		nota = new Nota (IntervalosMusicais.colcheia(), IntervalosMusicais.C5, amplitudePadrao - 1);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.B (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao - 2);
		melodiaPrincipal.addNota (nota);
		
		nota = new Nota (IntervalosMusicais.colcheia(), IntervalosMusicais.C5, amplitudePadrao - 3);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.B (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao - 4);
		melodiaPrincipal.addNota (nota);
		
		nota = new Nota (IntervalosMusicais.colcheia(), IntervalosMusicais.C5, amplitudePadrao - 5);
		melodiaPrincipal.addNota (nota);
		
		nota = new Nota (IntervalosMusicais.colcheia(), IntervalosMusicais.C5, amplitudePadrao - 6);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.B (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao - 7);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.G (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao - 8);
		melodiaPrincipal.addNota (nota);

		
		return melodiaPrincipal;
	}
		
	/**
	 * Construcao da musica tema de "Game of Thrones",
	 * serie da HBO
	 * @return A melodia construida
	 */
	public static Melodia gameOfThrones (){
		/*	Construção default da melodia */
		new Melodias();
		
		frequencia = IntervalosMusicais.G (IntervalosMusicais.C3);
		nota = new Nota (IntervalosMusicais.minima() + IntervalosMusicais.seminima(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		
		nota = new Nota (IntervalosMusicais.minima() + IntervalosMusicais.seminima(), IntervalosMusicais.C3, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		
		frequencia = IntervalosMusicais.Dsust (IntervalosMusicais.C3);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.F (IntervalosMusicais.C3);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.G (IntervalosMusicais.C3);
		nota = new Nota (IntervalosMusicais.minima(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		
		nota = new Nota (IntervalosMusicais.minima(), IntervalosMusicais.C3, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.Dsust (IntervalosMusicais.C3);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.F (IntervalosMusicais.C3);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		for (int repeticoes = 0; repeticoes < 4; repeticoes++){
			frequencia = IntervalosMusicais.D (IntervalosMusicais.C3);
			nota = new Nota (IntervalosMusicais.seminima(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.G (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.seminima(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.Asust (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			nota = new Nota (IntervalosMusicais.colcheia(), IntervalosMusicais.C3, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
		}
		
		
		frequencia = IntervalosMusicais.F (IntervalosMusicais.C3);
		nota = new Nota (IntervalosMusicais.minima() + IntervalosMusicais.seminima(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		
		frequencia = IntervalosMusicais.Asust (IntervalosMusicais.C2);
		nota = new Nota (IntervalosMusicais.minima() + IntervalosMusicais.seminima(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		
		frequencia = IntervalosMusicais.D (IntervalosMusicais.C3);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.Dsust (IntervalosMusicais.C3);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.F (IntervalosMusicais.C3);
		nota = new Nota (IntervalosMusicais.minima(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		
		
		frequencia = IntervalosMusicais.Asust (IntervalosMusicais.C2);
		nota = new Nota (IntervalosMusicais.minima(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.Dsust (IntervalosMusicais.C3);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.D (IntervalosMusicais.C3);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		
		nota = new Nota (IntervalosMusicais.minima() + IntervalosMusicais.seminima(), IntervalosMusicais.C3, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		
		for (int repeticoes = 0; repeticoes < 3; repeticoes++){
			frequencia = IntervalosMusicais.G (IntervalosMusicais.C3);
			nota = new Nota (IntervalosMusicais.minima(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			nota = new Nota (IntervalosMusicais.minima(), IntervalosMusicais.C3, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.Dsust (IntervalosMusicais.C3);
			nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.F (IntervalosMusicais.C3);
			nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
		}
		
		frequencia = IntervalosMusicais.G (IntervalosMusicais.C3);
		nota = new Nota (IntervalosMusicais.minima(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		
		return melodiaPrincipal;
	}

	/**
	 * Construcao da musica tema dos Lannesters, da serie
	 * "Game of Thrones", "The Rains of Castamere"
	 * @return A melodia construida
	 */
	public static Melodia rainsOfCastamere (){
		new Melodias ();
	
		frequencia = IntervalosMusicais.A (IntervalosMusicais.C1);
		nota = new Nota (IntervalosMusicais.seminima(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		/*	Começo Repetição */
		for (int repeticoes = 0; repeticoes < 2; repeticoes++){
			frequencia = IntervalosMusicais.F (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.seminima() + IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.A (IntervalosMusicais.C1);
			nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.E (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.seminima() + IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.A (IntervalosMusicais.C1);
			nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.F (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.seminima(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.G (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.seminima(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.E (IntervalosMusicais.C1);
			nota = new Nota (IntervalosMusicais.seminima() + IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.A (IntervalosMusicais.C1);
			nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.G (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.seminima(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.F (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.seminima(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.E (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.seminima(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.D (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.seminima(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.E (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.semibreve(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			
			
			frequencia = IntervalosMusicais.A (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.A (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.seminima(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.Asust (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.G (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.seminima(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			nota = new Nota (IntervalosMusicais.colcheia(), IntervalosMusicais.C2, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			nota = new Nota (IntervalosMusicais.colcheia(), IntervalosMusicais.C2, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.A (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.seminima(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.Asust (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.seminima(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.G (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.seminima() + IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.A (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.Asust (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.seminima(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.A (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.seminima(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.G (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.seminima(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.F (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.seminima(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.E (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.minima() + IntervalosMusicais.seminima(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.A (IntervalosMusicais.C1);
			nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.A (IntervalosMusicais.C1);
			nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			
			
			frequencia = IntervalosMusicais.F (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.seminima() + IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.A (IntervalosMusicais.C1);
			nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.E (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.seminima() + IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.A (IntervalosMusicais.C1);
			nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.F (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.seminima(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
	
			frequencia = IntervalosMusicais.G (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.seminima(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.E (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.seminima() + IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.A (IntervalosMusicais.C1);
			nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.G (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.seminima(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.F (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.seminima(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.E (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.seminima(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
	
			frequencia = IntervalosMusicais.D (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.seminima(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
	
			frequencia = IntervalosMusicais.E (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.minima() + IntervalosMusicais.seminima(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
	
			nota = new Nota (IntervalosMusicais.seminima(), IntervalosMusicais.C2, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			
			
			frequencia = IntervalosMusicais.A (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.seminima() + IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.Asust (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.G (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.seminima() + IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			nota = new Nota (IntervalosMusicais.colcheia(), IntervalosMusicais.C2, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.A (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.seminima(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.Asust (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.seminima(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.G (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.seminima() + IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.A (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.Asust (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.seminima(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.A (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.seminima(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.G (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.seminima(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.F (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.seminima(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.D (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.semibreve(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			nota = new Nota (IntervalosMusicais.seminima(), 0, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.A (IntervalosMusicais.C1);
			nota = new Nota (IntervalosMusicais.seminima(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
		
		
		
			frequencia = IntervalosMusicais.E (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.F (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.D (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.minima(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.F (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.E (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.A (IntervalosMusicais.C1);
			nota = new Nota (IntervalosMusicais.minima(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			nota = new Nota (IntervalosMusicais.colcheia(), 0, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.A (IntervalosMusicais.C1);
			nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.F (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.F (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.D (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.minima(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.F (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.seminima(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.F (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.E (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.minima() + IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.A (IntervalosMusicais.C1);
			nota = new Nota (IntervalosMusicais.seminima(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			
			
			frequencia = IntervalosMusicais.E (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.F (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.D (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.minima(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.A (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.seminima(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.A (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.seminima(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.G (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.seminima(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.D (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.seminima() + IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.F (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.F (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.seminima() + IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.D (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.E (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.seminima() + IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.F (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.D (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.minima() + IntervalosMusicais.seminima(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.A (IntervalosMusicais.C1);
			nota = new Nota (IntervalosMusicais.seminima(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			
			
			frequencia = IntervalosMusicais.E (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.F (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.D (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.minima(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.A (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.seminima(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.A (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.seminima(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.G (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.seminima(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.D (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.seminima() + IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.F (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.F (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.seminima() + IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.D (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.A (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.G (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.E (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.F (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.D (IntervalosMusicais.C2);
			nota = new Nota (IntervalosMusicais.minima() + IntervalosMusicais.seminima(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
			
			frequencia = IntervalosMusicais.A (IntervalosMusicais.C1);
			nota = new Nota (IntervalosMusicais.seminima(), frequencia, amplitudePadrao);
			melodiaPrincipal.addNota (nota);
		}
		
		frequencia = IntervalosMusicais.D (IntervalosMusicais.C2);
		nota = new Nota (IntervalosMusicais.semibreve() + IntervalosMusicais.seminima(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		

		return melodiaPrincipal;
	}
	
}