/*	Pacote ao qual pertence */
package principal;

/*	Importando Classes necessárias */
import sintese.Melodia;
import sintese.Nota;

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
	
	/**
	 * Construcao do refrao da musica "Let it Go",
	 * do filme Frozen - da Disney
	 * @return A melodia construida
	 */
	public static Melodia granada (){
		
		new Melodias();
		
		frequencia = IntervalosMusicais.Asust (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.B (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.Asust (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.Gsust (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		
		nota = new Nota (IntervalosMusicais.semicolcheia(), 0, 0);
		melodiaPrincipal.addNota (nota);
		
		
		
		
		frequencia = IntervalosMusicais.Asust (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
				
		
		frequencia = IntervalosMusicais.Asust (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.Asust (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
				
		
		frequencia = IntervalosMusicais.Asust (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.Asust (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
				
		
		frequencia = IntervalosMusicais.Asust (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.B (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		nota = new Nota (IntervalosMusicais.colcheia(), 0, 0);
		melodiaPrincipal.addNota (nota);
		
		
		nota = new Nota (IntervalosMusicais.colcheia(), 0, 0);
		melodiaPrincipal.addNota (nota);
		
		
		
		frequencia = IntervalosMusicais.Asust (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.B (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.Asust (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.Gsust (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		
		nota = new Nota (IntervalosMusicais.semicolcheia(), 0, 0);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.Asust (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
				
		
		frequencia = IntervalosMusicais.Asust (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.Asust (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
				
		
		frequencia = IntervalosMusicais.Asust (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.Asust (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
				
		
		frequencia = IntervalosMusicais.Asust (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.B (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		
		nota = new Nota (IntervalosMusicais.colcheia(), 0, 0);
		melodiaPrincipal.addNota (nota);
		
		nota = new Nota (IntervalosMusicais.colcheia(), 0, 0);
		melodiaPrincipal.addNota (nota);
		
		
		
		
		
		frequencia = IntervalosMusicais.Asust (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.B (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.Asust (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.B (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.Asust (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.B (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.Asust (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.B (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.Asust (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.B (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.B (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		nota = new Nota (IntervalosMusicais.colcheia(), 0, 0);
		melodiaPrincipal.addNota (nota);
		nota = new Nota (IntervalosMusicais.colcheia(), 0, 0);
		melodiaPrincipal.addNota (nota);
		
		
		
		frequencia = IntervalosMusicais.Asust (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.B (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.Asust (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.B (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.Asust (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.B (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.Asust (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.B (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.Asust (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.B (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		frequencia = IntervalosMusicais.B (IntervalosMusicais.C4);
		nota = new Nota (IntervalosMusicais.colcheia(), frequencia, amplitudePadrao);
		melodiaPrincipal.addNota (nota);
		
		
		return melodiaPrincipal;
	}
	
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
	
	public static Melodia padrao (){
		new Melodias();

		nota = new Nota (2.0370934, 0.0, 0.0);
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
}