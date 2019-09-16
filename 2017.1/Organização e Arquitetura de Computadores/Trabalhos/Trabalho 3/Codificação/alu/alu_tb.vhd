--Declaracao de bibliotecas
LIBRARY ieee;                                               
USE ieee.std_logic_1164.all;    
USE ieee.numeric_std.all;    

ENTITY alu_tb IS
	generic (DATA_WIDTH : natural := 32); --tamanho de 32 bits para dados de input e output
END alu_tb;

ARCHITECTURE alu_arch OF alu_tb IS
	--sinais necessarios para o process do testbench
	SIGNAL S_input1 : std_logic_vector(DATA_WIDTH -1 downto 0);
	SIGNAL S_input2 : std_logic_vector(DATA_WIDTH -1 downto 0);
	SIGNAL S_operation : std_logic_vector(3 downto 0);
	SIGNAL S_output : std_logic_vector(DATA_WIDTH -1 downto 0);
	SIGNAL S_zero : std_logic;
	SIGNAL S_negative : std_logic;
	SIGNAL S_carry : std_logic;
	SIGNAL S_overflow : std_logic;
	
	COMPONENT alu --declaracao do componente alu(ula) que sera submetida a teste
		PORT (
			input1, input2 : in std_logic_vector(DATA_WIDTH -1 downto 0);
			operation : in std_logic_vector(3 downto 0);
			output : out std_logic_vector(DATA_WIDTH -1 downto 0);
			zero, negative : out std_logic;
			carry, overflow : out std_logic
		);
	END COMPONENT;

	BEGIN
		i1 : alu PORT MAP(--mapeamento dos sinais com as portas do componente alu
			input1 => S_input1,
			input2 => S_input2,
			operation => S_operation,
			output => S_output,
			zero => S_zero,
			negative => S_negative,
			carry => S_carry,
			overflow => S_overflow);

		Stimulus : PROCESS --processo de testbench que gera estimulos para os sinais
			variable op1,op2 : integer; --variaveis para armazenar valores inteiros para posterior conversao
			BEGIN         

					-- Testar operacoes nao aritmeticas
					op1 := 19;
					op2 := 13;
					--conversao dos inteiros para std_logic_vector
					S_input1  <= std_logic_vector(to_signed(op1, S_input1'length));
					S_input2  <= std_logic_vector(to_signed(op2, S_input2'length));
					
					--Teste AND
					S_operation <= "0000";  wait for 5 ps;
					
					--Teste OR
					S_operation <= "0001";  wait for 5 ps;
					
					--Teste SLT
					--Primeiro teste resultando SLT = 0 (op1>op2)
					S_operation <= "0100";  wait for 5 ps;
					--Segundo teste resultando SLT = 1 (op1<op2)
					op2 := 53;
					S_input2  <= std_logic_vector(to_signed(op2, S_input2'length));
					wait for 5 ps;
					
					--Teste NOR
					S_operation <= "0101";  wait for 5 ps;
					
					--Teste XOR
					S_operation <= "0110";  wait for 5 ps;
					
					-- novos inputs para testar shifts(sll,srl e sra)
					S_input1  <= "10100100000000000010000000010011";
					S_input2  <= "00000000000000000000000000000101";
					
					--Teste SLL
					S_operation <= "0111";  wait for 5 ps;
					
					--Teste SRL
					S_operation <= "1000";  wait for 5 ps;
					
					--Teste SRA
					S_operation <= "1001";  wait for 5 ps;
					
					-- Testar operacoes aritmeticas (ADD e SUB)
					--ADD com resultado positivo
					op1 := 19;
					op2 := 13;
					S_input1  <= std_logic_vector(to_signed(op1, S_input1'length));
					S_input2  <= std_logic_vector(to_signed(op2, S_input2'length));
					S_operation <= "0010";  wait for 5 ps;
					
					--ADD com resultado zero
					op2 := -19;
					S_input2  <= std_logic_vector(to_signed(op2, S_input2'length));
					wait for 5 ps;
						
					--ADD com resultado negativo
					op2 := -30;
					S_input2  <= std_logic_vector(to_signed(op2, S_input2'length));
					wait for 5 ps;
						
					--ADD com overflow e carry = 1
					--caso onde somamos dois numeros negativos e obtemos resultado positivo
					op1 := -1073741824;
					op2 := -1342177280;
					S_input1  <= std_logic_vector(to_signed(op1, S_input1'length));
					S_input2  <= std_logic_vector(to_signed(op2, S_input2'length));
					wait for 5 ps;
						
					--SUB com resultado positivo
					op1 := 19;
					op2 := 13;
					S_input1  <= std_logic_vector(to_signed(op1, S_input1'length));
					S_input2  <= std_logic_vector(to_signed(op2, S_input2'length));
					S_operation <= "0011";  wait for 5 ps;
					
					--SUB com resultado zero
					op2 := 19;
					S_input2  <= std_logic_vector(to_signed(op2, S_input2'length));
					wait for 5 ps;
					
					--SUB com resultado negativo
					op2 := 30;
					S_input2  <= std_logic_vector(to_signed(op2, S_input2'length));
					wait for 5 ps;
					
					--SUB com overflow
					--caso overflow quando subtraimos numero positivo de um negativo e obtemos resultado positivo
					op1 := -536870912;
					op2 := 1879048192;
					S_input1  <= std_logic_vector(to_signed(op1, S_input1'length));
					S_input2  <= std_logic_vector(to_signed(op2, S_input2'length));
					wait for 5 ps;
			WAIT;			
			END PROCESS Stimulus; --fim do testbench
END alu_arch;