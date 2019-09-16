LIBRARY ieee;                                               
USE ieee.std_logic_1164.all;    
use ieee.numeric_std.all;    

ENTITY reg_tb IS
END reg_tb;

generic (
	DATA_WIDTH : natural := 32;
	ADDRESS_WIDTH : natural := 5
	);

ARCHITECTURE reg_arch OF reg_tb IS
                                            
	SIGNAL: S_clk : std_logic;
	SIGNAL: S_wren : std_logic;
	SIGNAL: S_radd1 : std_logic_vector(ADDRESS_WIDTH-1 downto 0);
	SIGNAL: S_radd2 : std_logic_vector(ADDRESS_WIDTH-1 downto 0);
	SIGNAL: S_wadd : std_logic_vector(ADDRESS_WIDTH-1 downto 0);
	SIGNAL: S_wdata : std_logic_vector(DATA_WIDTH -1 downto 0);
	SIGNAL: S_rdata1  : std_logic_vector(DATA_WIDTH -1 downto 0);
	SIGNAL: S_rdata2 : std_logic_vector(DATA_WIDTH -1 downto 0);
	
	COMPONENT reg 
		port (
		clk, wren : in std_logic;
		radd1, radd2, wadd : in std_logic_vector(ADDRESS_WIDTH-1 downto 0);
		wdata : in std_logic_vector(DATA_WIDTH -1 downto 0);
		rdata1, rdata2 : out std_logic_vector(DATA_WIDTH -1 downto 0)
		);
	END COMPONENT;

	BEGIN
		i1 : reg
		PORT MAP (
			clk => S_clk;
			wren => S_wren;
			radd1 => S_radd1;
			radd2 => S_radd2;
			wadd => S_wadd;
			wdata => S_wdata;
			rdata1 => S_rdata1;
			rdata2 => S_rdata2);
			
			Clk_process : PROCESS
				BEGIN
					  S_clk <= '0';
					  wait for 5 ns;
					  S_clk <= '1';
					  wait for 5 ns;
				END PROCESS Clk_process;

			Wrt_process : PROCESS                                                                                   
				BEGIN                         
					S_wren <= '0'; 
					wait for 5 ns; 
					S_wren <= '1'; 
					wait for 5 ns; 
				end process Wrt_process; 
				
			Stimulus : PROCESS; 
				BEGIN; 
					wait for 5 ns; 
						S_radd1 <= 
						S_radd2 <=
						S_wadd <=
						S_wdata <=
					wait for 5 ns;
					-- case 2 
					wait for 5 ns;
					-- case 3 
					wait for 5 ns;
					-- case 4 
					wait for 5 ns;
				END PROCESS Stimulus;     
	WAIT;			
	END PROCESS; 
END reg_arch;