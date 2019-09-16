--MÃƒÆ’Ã‚Â³dulo para memÃƒÆ’Ã‚Â³ria de dados
library IEEE; 
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity md is
  generic(N: integer := 7; M: integer := 32);
  port(
			clk:  in  STD_LOGIC := '0'; 
			we:   in  STD_LOGIC := '0';
			adr:  in  STD_LOGIC_VECTOR(N-1 downto 0) := (others => '0');
			din:  in  STD_LOGIC_VECTOR(M-1 downto 0) := (others => '0');
			dout: out STD_LOGIC_VECTOR(M-1 downto 0)
		);
end;

architecture memory_arch of md is

	type mem_array is array(0 to (2**N-1)) of STD_LOGIC_VECTOR(M-1 downto 0);
	signal mem: mem_array := (
											x"00000001",
											x"00000002",
											x"00000003",
											x"00000004",
											x"00000005",
											others => (others => '0')
										 );
										 
									 
begin
	
	process(clk) begin
	
		if clk'event and clk='1' then 
			if we='1' then 
				mem(to_integer(unsigned(adr))) <= din;
			end if;
		end if;
		
	end process;

	dout <= mem(to_integer(unsigned(adr)));
	
end;