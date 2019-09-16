library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity reg_bank is

	generic (
	DATA_WIDTH : natural := 32;
	ADDRESS_WIDTH : natural := 5
	);

	port (
	clk, wren : in std_logic;
	radd1, radd2, wadd : in std_logic_vector(ADDRESS_WIDTH-1 downto 0);
	wdata : in std_logic_vector(DATA_WIDTH -1 downto 0);
	rdata1, rdata2 : out std_logic_vector(DATA_WIDTH -1 downto 0)
	);

end entity reg_bank;

type regArray is array(0 to size-1) of std_logic_vector(DATA_WIDTH-1 downto 0);
signal reg_bank : regArray;

architecture Behavioral of reg_bank is
begin
	process(clk)
		begin
			if rising_edge(clk) then
				if wren = '1' & wadd /= '0' then
					regArray(to_integer(unsigned(wadd))) <= wdata;
				end if;
				
				rdata1 <= regArray(to_integer(unsigned(radd1)));
				rdata2 <= regArray(to_integer(unsigned(radd2)));
				
			end if;
	end process;	
end Behavioral;