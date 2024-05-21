unsigned char	swap_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
}

/*
--------------------------------------------------------------------------------
Pseudocódigo:
--------------------------------------------------------------------------------
	Nuestra funcion cambia los 4 primeros y ultimos bits de un caracter
  en reversa.
  Ponemos directamente en return la accion, y finalizamos la funcion.
--------------------------------------------------------------------------------
*/