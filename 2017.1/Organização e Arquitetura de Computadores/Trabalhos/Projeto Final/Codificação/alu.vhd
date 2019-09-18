--Módulo para ULA
--Declaracao de bibliotecas
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

--Declaracao da entidade ALU (ULA)
entity alu is
	generic (DATA_WIDTH : natural := 32); --ULA faz operacoes com dados de 32 bits
	port (
		--entrada de dados com 32 bits
		input1, input2, input3 : in std_logic_vector(DATA_WIDTH-1 downto 0) :=(others =>'0');
		--codigo da operacao formado de 4 bits
		operation : in std_logic_vector(3 downto 0) :=(others =>'0');
		--saida de dados com 32 bits
		output : out std_logic_vector(DATA_WIDTH-1 downto 0) :=(others =>'0');
		--saidas zero (indica se output vale zero) e negative (indica se output e negativo)
		zero, negative : out std_logic; 
		--saidas carry(ultimo carry na soma) e overflow(ativa quando resultado da soma
		--ou subtracao excede o tamanho da palavra)
		carry, overflow : out std_logic 	
	);
	
end entity alu;

--Declaracao da arquitetura
architecture Behavioral of alu is
	--ambos os sinais declarados abaixo sao utilizados na operacao SLT
	signal slt_set_1 : integer := 1;
	signal slt_set_0 : integer := 0;

	begin

		process(input1, input2, operation)--processo para operacoes e sua lista de sensibilidade
		variable aux_aritm: std_ulogic_vector(DATA_WIDTH downto 0);--vetor de 33 bits, o MSB armazena carry da soma
		variable aux_overflow: std_logic_vector(2 downto 0);	--armazena os bits mais significativos do input1, input 2 e output
																				--na seguinte ordem (MSB_input1,MSB_input2,MSB_output)
		variable aux_output: std_logic_vector(DATA_WIDTH-1 downto 0);--armazena momentaneamente a saida output
		
		begin
		--inicializacao das saidas com 0
			negative <= '0';
			zero <= '0';
			carry <= '0';
			overflow <= '0';
			
			case operation is
				when "0000" => --AND
					aux_output := input1 and input2;
					output <= aux_output;
					
				when "0001" => --OR
					aux_output := input1 or input2;
					output <= aux_output;
					
				when "0010" => --ADD
					--conversoes entre tipos sao necessarias para obter aux_output
					aux_output := std_logic_vector(signed(input1) + signed(input2)); 
					--define output
					output <= aux_output;
					
					--conversoes entre tipos sao necessarias para obter aux_aritm
					--aux_aritm faz a operacao e armazena o carry em seu MSB
					aux_aritm := std_ulogic_vector(resize(signed(input1), aux_aritm'length) + resize(signed(input2), aux_aritm'length));
					

					
					--CARRY OUT sera o MSB de aux_aritm
					carry <= aux_aritm(DATA_WIDTH);
					
					--Montar vetor para analisar overflow
					aux_overflow := input1(input1'high) & input2(input2'high) & aux_aritm(DATA_WIDTH-1);
					case aux_overflow is
						when "001"|"110" =>
						--overflow, na soma, ocorre quando
						-- soma de dois positivos resulta em negativo ou
						-- soma de dois negativos resulta em positivo
							overflow <= '1'; 
						when others =>
							overflow <= '0';--nao ocorre overflow
					end case;
					
				when "0011" => --SUB
					--conversoes entre tipos sao necessarias para obter aux_output
					aux_output := std_logic_vector(signed(input1) - signed(input2)); 
					
					--define output
					output <= aux_output;
					aux_aritm := std_ulogic_vector(resize(signed(input1), aux_aritm'length) - resize(signed(input2), aux_aritm'length));
					
					--Montar vetor para analisar overflow
					aux_overflow := input1(input1'high) & input2(input2'high) & aux_aritm(DATA_WIDTH-1);
					case aux_overflow is
						when "011"|"100" =>
						--overflow, na subtracao, ocorre quando
						-- subtraimos um negativo de um positivo e obtemos negativo ou
						-- subtraimos um positivo de um negativo e obtemos positivo	
							overflow <= '1';
						when others =>
							overflow <= '0';--nao ocorre overflow
					end case;
					
				when "0100" => --SLT
					if signed(input1) < signed(input2) then
						aux_output := std_logic_vector(to_unsigned(slt_set_1, aux_output'length));
						output <= aux_output; --SLT valido, setar output com 1
					else
						aux_output := std_logic_vector(to_unsigned(slt_set_0, aux_output'length));
						output <= aux_output; --SLT nao valido, setar output com 0
					end if; 
					
				when "0101" => --NOR
					aux_output := input1 nor input2; 
					output <= aux_output; 
					
				when "0110" => --XOR
					aux_output := input1 xor input2; 
					output <= aux_output; 
					
				when "0111" => --SLL
					--sao necessarias conversoes para efetuar shift_left
					aux_output := std_logic_vector(shift_left(unsigned(input2), to_integer(unsigned(input3)))); 
					output <= aux_output;
	
				when "1000" => --SRL
					--sao necessarias conversoes para efetuar shift_right
					aux_output := std_logic_vector(shift_right(unsigned(input2), to_integer(unsigned(input3)))); 
					output <= aux_output;

				when "1001" => --SRA
					--funcao "sra" so funciona com vetores de bits, logo precisa de conversao entre tipos
					aux_output := to_stdlogicvector(to_bitvector(input2) sra to_integer(unsigned(input3))); 
					output <= aux_output;
 
				when others => --Demais casos
					NULL;
			end case;
			
			--analise do sinal e valor da saida	
			if (to_integer(signed(aux_output)) <= 0) then
				if (to_integer(signed(aux_output)) = 0) then
					--saida zero ativa quando output for nulo
					zero <= '1';
				else
					--saida negative ativa quando output for negativo
					negative <= '1';
				end if;
			end if;
	end process; --termino do processo
	
end Behavioral;