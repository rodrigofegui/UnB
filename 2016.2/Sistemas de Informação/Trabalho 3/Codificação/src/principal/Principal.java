package principal;

import trabalhoFeliz.DeptRH;

public class Principal {
	public static void main(String[] args){
		/*
		DeptRH deptRH = new DeptRH();
		
		deptRH.cadrastarFuncionario();
		//*/
		
		String teste = "Stringcomnumeros0123456789esmbolos@-_.com";
		System.out.println("old   -> " + teste);
		System.out.println("new -> " + Formatacao.isEmail(teste));
	}
}
