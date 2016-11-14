package controladorMidi;

public class Z1{
      MidiJS oM; 
      int    canal       = 0;
      int    nota        = 60;   
      int    veloc       = 127;
      int    pan         = 64;
      int    banco       = 0;       
      int    instrumento = 0;       

      public Z1(){
    	  oM = new MidiJS ();
    	  oM.reset (canal);
    	  oM.bank_select (banco, canal);
    	  oM.program_change (canal, instrumento);
    	  oM.pan (pan, canal);    

    	  retardo (250);
     
    	  oM.note_on (nota, veloc, canal);

    	  try{
    		  System.in.read ();
    		  System.exit (0);
         }catch(Exception e){};     
      }

      public static void main(String args[]){
    	  new Z1();
      }

      static void retardo(int miliseg){  
    	  try{
    		  Thread.sleep(miliseg);
    	  }catch(InterruptedException e) { }
      }
}