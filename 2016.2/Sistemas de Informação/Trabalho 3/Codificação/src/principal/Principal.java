package principal;

import java.util.LinkedList;
import java.util.Scanner;

import bancoDados.tabelas.Funcionario;
import trabalhoFeliz.DeptRH;
import trabalhoFeliz.Empregado;
import utilitario.Autentificacao;

public class Principal {
	public static void main(String[] args){
		/*
		DeptRH deptRH = new DeptRH();
		
		
		//deptRH.cadrastarFuncionario();
		//*/
		
		/*
		String teste = "061 9 8385 9997";
		System.out.println("old   -> " + teste);
		System.out.println("new -> " + Autentificacao.telefone(teste));
		//*/
		
		Empregado.preencerValeTransporte(new Funcionario());
		
		System.out.println("\nAcabou\n");
	}
}
